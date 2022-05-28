#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>

typedef FILE* file;
typedef char* buffer;

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
