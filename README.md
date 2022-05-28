The library file.h is a library containing useful functions for file management in C language, it's created for being an extension of the standard library (stdio.h)

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
HOW TO IMPLEMENT THE FILE LIBRARY

You can use the file library function in your code just by adding the library to the header of the program. 
You can add the library with #include and the library file path (relative or absolute) in quotes.

    Example:    #include "file.h"
                #include "../Library/file.h"                  
                #include "C:/User/Desktop/Program/Library/fie.h"
           
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
DATA TYPE FROM THE FILE LIBRARY

The file library permit to use all the data type used in the standard library (stdio.h) and other implemented libraries.
There are two new data type:

   file     -->      a shorter declaration of a file pointer
   
   buffer   -->      a string used for conteining text from the file
                
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
FUNCTION FROM THE FILE LIBRARY

These are the functions available from the file library:

  fcontrol()   -->  a void function interrupting the execution of the program with an error if the opened passed file doesn't exist
  
  flen()   -->  a function returning an integer value reporting the passed file lenght in characters
  
  fview()   -->  a function printing the content of the passed file
  
  fcopy()   -->  a function copying the content of the second declared file to the first one
  
  
