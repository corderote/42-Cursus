<div align=center>
	<p>
	<i>
	This project has been created as part of the 42 curriculum by
	<b>pcordero</b>
	</i>
	</p>
	<h1>Libft</h1>
</div>

## Description: 

This is the first project to tackle as a student of the **42 Cursus** experience. In wich we have to recreate some basic functions from the standard library. 
This project is made to evolve along the student, including new functions and utilities as we develop further projects for the curse. 

## Instructions: 

### Requirements:
The functions and Makefile are designed for use in a UNIX-like environment; any use outside this scope does not guarantee correct or efficient operation.
- Make
- GCC

### Compiling:
To generate the libft library: 
``` bash
make
```

### Using **Libft** as a static library:
After installation is complete, the libft.a file will appear. This static library can be used in any project.

You can include the library by including libft.h and libft.a as in the example:

- First include the header file in your C or header files.
``` h
#include "libft.h"
```

- Then compile using the library
``` bash
cc <project_file.c> <libft_library_file>
```
**Note:** You can modify the libft.a name file inside the Makefile document before generating it. 