I finished the first milestone in my way to complete the common core at [42 Barcelona][1], in this milestone we only have one project **LibFT**.

- [What is LibFT?](#What-is-libft)
- [Mandatory functions](#Mandatory)
- [Bonus functions](#Bonus_Functions)
- [Running and creating the library, the makefile rules](#Running)

<div align="left">
  <a href = "mailto:gbarulls@gmail.com"><img src="https://img.shields.io/badge/Gmail-D14836?style=for-the-badge&logo=gmail&logoColor=white"></a>
  <a href="https://www.linkedin.com/in/guillem-barulls-casades%C3%BAs-9906001a/" target="_blank"><img src="https://img.shields.io/badge/-LinkedIn-%230077B5?style=for-the-badge&logo=linkedin&logoColor=white" target="_blank"></a> 
</div>

### What-is-libft

Libft is an individual project at [42][1] that requieres us to re-create some standard C library functions for future projects, and have a deeper understanding of data structures and basic algorithms. 

At 42 we are not allowed to use some standard libraries on our projects, so we have to keep growing this libary with our own functions as we go farther in the program.

The used technologies for this project: C / git / Makefile
<p align="left">
  <a href=""><img src="https://github.com/zikocult/Cursus42/blob/main/utils/Used_photos/libft/libftdetail.png?raw=true" /></a>
</p>

### Mandatory

| **Function**   | **Declaration**                                                        | **Description**                                                        |
| -------------- | ---------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| **isalpha**    | int ft_isalpha(int c);                                                 | is a char a letter                                                     |
| **isdigit**    | int ft_isdigit(int c);                                                 | is a char a digit                                                      |
| **isalnum**    | int ft_isalnum(int c);                                                 | is a char a number                                                     |
| **iascii**     | int ft_isascii(int c);                                                 | is a char an ascii char                                                |
| **isprint**    | int ft_isprint(int c);<br>                                             | is a char printable                                                    |
| **strlen**     | size_t	ft_strlen(const char *s);<br>                                   | len of string                                                          |
| **memset**     | void	\*ft_memset(void \*s, int c, size_t n);<br>                       | set the mem position with a char                                       |
| **bzero**      | void	ft_bzero(void \*s, size_t n);<br>                                 | initiate the memory at \\0                                             |
| **memcpy**     | void	\*ft_memcpy(void \*dest, const void \*src, size_t n);<br>         | copy a memory content to another position                              |
| **memmove**    | void	\*ft_memmove(void \*dest, const void \*src, size_t n);<br>        | move a memory content to another position                              |
| **strlcpy**    | size_t	ft_strlcpy(char \*dst, const char \*src, size_t size);<br>      | copy n char of a string                                                |
| **strlcat**    | size_t	ft_strlcat(char \*dst, const char \*src, size_t size);<br>      | concatenate n chars of two strings                                     |
| **toupper**    | int ft_toupper(int c);<br>                                             | transform a char to uppercase                                          |
| **tolower**    | int ft_tolower(int c);<br>                                             | transform a char to lowercase                                          |
| **strchr**     | char \*ft_strchr(const char \*s, int c);<br>                           | look for a char in a string                                            |
| **strrchr**    | char \*ft_strrchr(const char \*s, int c);                              | look for a char in a string reverse mode                               |
| **strncmp**    | int ft_strncmp(const char \*s1, const char \*s2, size_t n);<br>        | compare n chars of a string                                            |
| **memchr**     | void	\*ft_memchr(const void \*s, int c, size_t n);<br>                 | look for a content in the memory                                       |
| **memcmp**     | int ft_memcmp(const void \*s1, const void \*s2, size_t n);<br>         | compare memory content                                                 |
| **strnstr**    | char	\*ft_strnstr(const char \*s1, const char \*s2, size_t len);<br>   | look for a string in a string                                          |
| **atoi**       | int ft_atoi(const char \*ptr);<br>                                     | convert ascii to integer                                               |
| **calloc**     | void	\*ft_calloc(size_t number, size_t size);<br>                      | set a malloc to \\0                                                    |
| **strdup**     | char	\*ft_strdup(const char \*s);<br>                                  | duplicate a string in memory                                           |
| **substr**     | char	\*ft_substr(char const \*s, unsigned int start, size_t len);<br>  | create a new string from a piece of another one                        |
| **strjoin**    | char	\*ft_strjoin(char const \*s1, char const \*s2);<br>               | join two strings in a new one                                          |
| **strtrim**    | char	\*ft_strtrim(char const \*s1, char const \*set);<br>              | erase the selected chars in the begin and the finish of a string       |
| **split**      | char	\*\*ft_split(char const \*s, char c);<br>                         | separate a string into a pieces, using a char as separator             |
| **itoa**       | char	\*ft_itoa(int n);<br>                                             | convert an integer into a string                                       |
| **strmapi**    | char	\*ft_strmapi(char const \*s, char (\*f)(unsigned int, char));<br> | Apply the function f to every char of the string creating a new string |
| **striteri**   | void	ft_striteri(char \*s, void (\*f)(unsigned int, char\*));<br>      | Apply the function f to every char of the string                       |
| **putchar_fd** | void	ft_putchar_fd(char c, int fd);<br>                                | write a char in a file                                                 |
| **putstr_fd**  | void	ft_putstr_fd(char \*s, int fd);<br>                               | write a string in a file                                               |
| **putendl_fd** | void	ft_putendl_fd(char \*s, int fd);<br>                              | write a string in a file and add a final jump of line \\n              |
| **putnbr_fd**  | void	ft_putnbr_fd(int nb, int fd);<br>                                 | write a number in a file                                               |

### Bonus_Functions

For this part, i nee to use the defined struct:

```C
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| **Function**     | **Declaration**                                                                     | **Description**                                                            |
| :--------------- | :---------------------------------------------------------------------------------- | :------------------------------------------------------------------------- |
| **lstnew**       | t_list	\*ft_lstnew(void \*content);<br>                                             | create a new node                                                          |
| **lstlast**      | t_list	\*ft_lstlast(t_list \*lst);<br>                                              | return the last node of the list                                           |
| **lstsize**      | int		ft_lstsize(t_list \*lst);<br>                                                  | quantity of nodes in a list                                                |
| **lstadd_front** | void	ft_lstadd_front(t_list \*\*lst, t_list \*new);<br>                             | add a node as the first node of a list                                     |
| **lst_add_back** | void	ft_lstadd_back(t_list \*\*lst, t_list \*new);<br>                              | add a node as the last node of a list                                      |
| **lstdelone**    | void	ft_lstdelone(t_list \*lst, void (\*del)(void\*));<br>                          | delete a node                                                              |
| **lstclear**     | void	ft_lstclear(t_list \*\*lst, void (\*del)(void\*));<br>                         | clear all the list and nodes                                               |
| **lstiter**      | void	ft_lstiter(t_list \*lst, void (\*f)(void \*));<br>                             | apply the funcion f to the content of every node                           |
| **lstmap**       | t_list	\*ft_lstmap(t_list \*lst, void \*(\*f)(void \*), void (\*del)(void \*));<br> | create a new list with the applied function f in the content of every node |

### Running

We only need to execute **make** commad to create the final library with the mandatory part, to compile the library with the bonus part too, **make bonus** is the command to use.

The create library is named **libft.a**, be free of use it in your projects if you want.

The next commands are included in the makefile:


| **Command**      | **Description**                                 |
| ---------------- | ----------------------------------------------- |
| **make**         | Create the basic library                        |
| **make bonus**   | Create the library and add the bonus part       |
| **make clean**   | Clean all the pre compiled objects created      |
| **make fclean**  | Clean all the files and folders created         |
| **make re**      | Fclean + create the basic library               |
| **make rebonus** | Fclean + create the library with the bonus part |

A visual example and the final result:

<p align="left">
  <a href=""><img src="https://github.com/zikocult/Cursus42/blob/main/utils/Used_photos/libft/make.png?raw=true" /></a>
</p>


[1]: https://www.42barcelona.com/
