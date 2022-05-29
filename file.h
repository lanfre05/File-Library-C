#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef FILE* file;

void fcontrol(file);												
size_t flen(file);	
void fview(file);													
void fcopy(file,file);												

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

size_t freplace(file FilePointer, char *StringToFind, char *NewString){
	long int position = ftell(FilePointer);
	size_t i, j, EqualCharCounter = 0, CountReplacement = 0;
	char buffer[flen(FilePointer)];
	fread(buffer, 1, flen(FilePointer), FilePointer);
	fseek(FilePointer, 0, SEEK_SET);
	for(i=0; i<strlen(buffer); i++){
		if( buffer[i] == StringToFind[0] ){
			EqualCharCounter++;
			for(j=1; StringToFind[j]!='\0'; j++){
				if( buffer[i+j] == StringToFind[j] ){ 	EqualCharCounter++; }
			}
			if( EqualCharCounter == strlen(StringToFind) ){
				EqualCharCounter = 0;
				for(j=0; NewString[j]!='\0'; j++){	fputc(NewString[j], FilePointer); }
				CountReplacement++;
				i += (strlen(StringToFind)-1);
			}else{	fputc(buffer[i], FilePointer); }
		}else{	fputc(buffer[i], FilePointer); }	
	}
	fseek(FilePointer, position, SEEK_SET);
	return CountReplacement;
}
