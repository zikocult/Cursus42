## Milestone2 Index

- [Born2beroot](###Born2beroot)
  	- Linux and the virtualization comes together in this project, becoming a real Linux system administrator
	- Used technologies:
		- Debian / Rocky Linux / Bash / Vi / VirtualBox / KVM 
- [PrintF](###PrintF)
	- This project is pretty straightforward, you have to recode printf.
	- Used technologies:
   		- C / Git / Makefile
- [GetNextLine](###GetNexLine)
	- May it be a file, stdin, or even later a network connection, you will always need a way to read content line by line.
	- Used technologies:
		- C / Git

### Born2beroot

We are facing a unique project where we will be installing a Linux machine in a local virtualized environment, using VirtualBox in my case.

No graphical environment was allowed for this project.

In my case, I opted for the installation version of Rocky Linux, with the corresponding configuration of SSH, HTTP, PHP, WordPress, Cockpit and firewall services.

On the other hand, work has also been done on securing passwords, users, as well as SSH access and the configuration of SELinux.

One of the tasks to be carried out was creating a script for monitoring the server status, and configuring it with Cron so that its execution could be seen by all connected users, here is my script.

```bash
#!/bin/bash

ARQUITECTURA=$(uname -a)

VIRTPROC=$(cat /proc/cpuinfo | grep "processor" | wc -l)

PHYSPROC=$(cat /proc/cpuinfo | grep "physical id" | wc -l)

MEM_USED=$(free --mega | awk '$1 == "Mem:" {print $3}')
MEM_TOTAL=$(free --mega | grep "Mem:" | awk '{Mem = $2} END {printf("%iMb", Mem)}')
MEM_PCT=$(free --mega | awk '$1 == "Mem:" {printf("(%.2f%%)\n", $3/$2*100)}')

HD_USED=$(df -m | grep -v "tmpfs" | awk '{use += $3} END {printf("%.2f", use / 1024)}')
HD_TOTAL=$(df -m | grep -v "tmpfs" | awk '{use += $2} END {printf("%.2fGb", use / 1024)}')
HD_PCT=$(df -m | grep -v "tmpfs" | awk '{use += $3} {total +=$2} END {printf("%.2f%%", (use / total)*100)}')

CPU_USE=$(ps -eo "%C" | awk '{cpu+=$1} END {printf("%.1f%%\n", cpu)}')

LAST_BOOT=$(who -b | awk '{print $3 " " $4}')

LVM_USE=$(if [ $(lsblk | grep "LVM" | wc -l) -gt 0 ]; then echo yes; else echo no; fi)

TCP_ESTAB=$(ss -ta | grep "ESTAB" | wc -l)

USER_LOGGED=$(users | wc -w)

IP=$(hostname -I | awk '{print $1}')

MAC=$(ip link | grep "link/ether" | awk '{mac = $2} END {printf("(%s)", mac)}')

SUDO_CMD=$(journalctl -q _COMM=sudo | grep COMMAND | wc -l)

wall "
                #Architecture: $ARQUITECTURA
                #CPU physical: $PHYSPROC
                #vCPU: $VIRTPROC
                #Memory Usage: $MEM_USED/$MEM_TOTAL $MEM_PCT
                #Disk Usage: $HD_USED/$HD_TOTAL ($HD_PCT)
                #CPU Load: $CPU_USE
                #Last Boot: $LAST_BOOT
                #LVM Use: $LVM_USE
                #Connections TCP: $TCP_ESTAB ESTABLISHED
                #User log: $USER_LOGGED
                #Network IP $IP $MAC
                #Sudo: $SUDO_CMD cmd"

```

<p align="left">
  <a href="https://github.com/zikocult/Cursus42/tree/main/02_ring"><img src="https://github.com/zikocult/Cursus42/blob/main/02_ring/docs/assets/Born2beroot/script.png" /></a>
</p>

*Note*: I take the image in my own computer, because I needed the disk space of the virtual machine for my actual projects.

**My opinion about the project 🖥️**

I have had a lot of fun working on this project and testing my knowledge about Linux, services, and servers, and learning about the history of this operating system.

### PrintF

[Here the code.](https://github.com/zikocult/Cursus42/tree/main/02_ring/printf)

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

### GetNexLine

[Here the code](https://github.com/zikocult/Cursus42/tree/main/02_ring/getnextline).

This has been an exciting project. Initially, it seemed like a simple project, but far from reality, this was a project where memory leaks and handling malloc became critical.

Essentially, this project aims to delve into the use of static variables and line-by-line file reading, regardless of the number of characters we read as input.

The bonus task required us to implement a feature where we could read multiple files simultaneously using multiple threads.

**How to use it ✒️**

For this project, we were not allowed to create a makefile, so in order to use it, multiple test mains and different text files have been used for testing purposes. 

I've show the code of the main I used for compilation below. This compilation has always been done with the following flags and options:

* `-Wall` - Enable all compiler warnings
* `-Wextra` - Enable extra compiler warnings
* `-Werror` - Treat warnings as errors
* `-D BUFFER_SIZE=x` - Size allowed to read for every loop, x is a value.

Here is my main, i use arguments to simplify the tests.

```c
#include "../get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main (int argc, char **argv)
{
	char *line;
	ssize_t	fd;
	int	i = 0;
	int counter = 0;
	char caracter;

	if (argc > 1)
	{
		i = 0;
		printf("BUFFER_SIZE: %d\n", BUFFER_SIZE);
		counter = 0;
// count the number of lines the file has
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Openning fail!\n");
			return (0);
		}
		while (read(fd, &caracter, 1) == 1)
			if (caracter == '\n')
				counter++;
		close(fd);

// second open, here the execution starts
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			printf("Openning fail!");
			return (1);
		}
		while (i < counter)
		{
			line = get_next_line(fd);
			printf("%s", line);
			free(line);
			i++;
		}
		close(fd);
	}	
	else
		printf("No args to continue\n");
	return (0);
}
```

**My opinion about the project 📝**

This has been by far the most challenging project I have undertaken at 42Barcelona so far, and it was short, but there are many points where errors can arise, and they have indeed arisen during the coding process.

All this, apart from teaching me a lot about memory management, has led me to learn how to effectively use debuggers. In my case, I chose GDB (GNU Debugger) as my tool of choice, but I tried LLDB and DAP too.

In my opinion this is a 10/10 project to learn how to program in C.
