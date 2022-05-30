#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef FILE* file;

void fcontrol(file);												
size_t flen(file);	
void fview(file);													
void fcopy(file,file);	
int fcompare(file,file);
long int fsearch(file,char*);

void fcontrol(file FilePointer){
	if( FilePointer==NULL ){	perror("Error");	exit(1); }		
}

size_t flen(file FilePointer){
	size_t lenght=0;	
	size_t position = ftell(FilePointer);										
	fseek(FilePointer, 0, SEEK_SET);						
	while( (fgetc(FilePointer))!=EOF ){	lenght++;	 }
	fseek(FilePointer, position, SEEK_SET);			
	return lenght;																							
}
	
void fview(file FilePointer){	
	char FileChar;
	size_t position = ftell(FilePointer);										
	fseek(FilePointer, 0, SEEK_SET);
	while( !feof(FilePointer) ){	putchar( fgetc(FilePointer) ); }
	fseek(FilePointer, position, SEEK_SET);			
}
	
void fcopy(file FileCopy, file FileOrig){
	size_t position = ftell(FileOrig);																	
	fseek(FileOrig, 0, SEEK_SET);			
	fseek(FileCopy, 0, SEEK_SET);		 	
	while( !feof(FileOrig) ){							
		fputc( fgetc(FileOrig), FileCopy );  
	}
	fseek(FileOrig, position, SEEK_SET);
	fseek(FileCopy, 0, SEEK_SET);
}

int fcompare(file File1, file File2){
	int File1Counter, File2Counter;
	long int position1 = ftell(File1);
	long int position2 = ftell(File2);
	fseek(File1, 0, SEEK_SET);
	fseek(File2, 0, SEEK_SET);
	File1Counter = File2Counter = 0;
	while( !feof(File1) ){	File1Counter += fgetc(File1); }
	while( !feof(File2) ){	File2Counter += fgetc(File2); }
	fseek(File1, position1, SEEK_SET);
	fseek(File2, position2, SEEK_SET);
	return (File1Counter - File2Counter);
}

long int fsearch(file FilePointer,char *StringToFind){
	size_t i, EqualCharCounter = 0;
	long int PositionSave, PositionOrig = ftell(FilePointer);
	fseek(FilePointer, 0, SEEK_SET);
	while( !feof(FilePointer) ){
		PositionSave = ftell(FilePointer);
		if( fgetc(FilePointer) == StringToFind[0] ){
			EqualCharCounter++;
			for(i=1; i<strlen(StringToFind); i++){
				if( fgetc(FilePointer) == StringToFind[i] ){	EqualCharCounter++; }
			}
			if( EqualCharCounter == strlen(StringToFind) ){
				fseek(FilePointer, PositionOrig, SEEK_SET);
				return PositionSave;
			}else{	PositionSave = (-1); }
		}
	}
	return PositionSave;
}
