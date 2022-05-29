The library file.h is a library containing useful functions for file management in C language, it's created for being an extension of the standard library (stdio.h)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
HOW TO IMPLEMENT THE FILE LIBRARY  (for Beginners)

You can use the file library function in your code just by adding the library to the header of the program. 
You can add the library with #include and the library file path (relative or absolute) in quotes.

    Example:    #include "file.h"
                #include "../Library/file.h"                  
                #include "C:/User/Desktop/Program/Library/file.h"
           
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
DATA TYPES FROM THE FILE LIBRARY

The file library permit to use all the data type used in the standard library (stdio.h) and other implemented libraries.
There are two new data type:

   file     -->      a shorter declaration of a file pointer
   
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   
                
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
FUNCTIONS FROM THE FILE LIBRARY

These are the functions available from the file library:

  fcontrol(FilePointer)   -->  a void function interrupting the execution of the program with an error if the opened passed FilePointer doesn't exist
  
  flen(FilePointer)   -->  a function returning an integer value reporting the FilePointer lenght in characters
  
  fview(FilePointer)   -->  a function printing the content of FilePointer
  
  fcopy(FileCopy,FileOrig)   -->  a function copying the content of FileOrig file to FileCopy
  
  fcompare(File1,File2)  --> a function returning an integer value containing the difference of the characters value of two files
                             >0 if File1 is greater / =0 if File1 is equal to File2 / <0 if File2 is greater
                  
  freplace(FilePointer,StringToFind,NewString)  -->  a function replacing every StringToFind in the FilePointer with NewString
                                                     it returns the integer number of replacements done
   
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  
