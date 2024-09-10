[**Results in this milestone**](https://github.com/zikocult/Cursus42/tree/main/02_ring)

Because putnbr and putstr aren't enough.

This project, consists of coding a library that contains a simplified version of the printf function. I will use this function for all our future projects.

With this code, I was able to learn about the use of variable arguments functions and the stdarg.h library.

Functions implemented:

| Argumento | Función                                         |
|:---------:|:----------------------------------------------- |
|    %c     | print a single char                             |
|    %s     | print a string                                  |
|    %%     | the easy one, print a %                         |
|    %d     | print a decimal                                 |
|    %i     | print a integer                                 |
|    %u     | print an unsigned char                          |
|    %x     | convert and print in hexadecimal with lowercase |
|    %X     | same but with uppercase                         |
|    %p     | print the memory position in hexadecimal        |

**How to use it ✒️**

You only need to copy the repository and use the makefile with the base option, this will create the "libftprintf.a" and you can use it in your projects.

The makefile content the next options.


| Option      | Action                                                                   |
| ----------- | ------------------------------------------------------------------------ |
| make        | compile and create the libftprintf.a                                     |
| make clean  | clean all the objects created, the objects are created in its own folder |
| make fclean | clean objects, created folders and libftprintf.a                         |
| make re     | make fclean and compile from scrach                                      |

**My opinion about the project 🤓**

It has been a very rewarding project. On one hand, I had been eager to start using printf in my projects, and on the other hand, I have seen how it works from scratch. The learning experience has been significant.