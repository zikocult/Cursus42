/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:56:39 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/19 16:18:18 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
// Para las pruebas hay que incluir #include <fcntl.h>
/*int main (void)
{
	int fd;
 	char *a = "Hola\nMundo!";

 	fd = open("./prueba.txt", O_WRONLY);
 	if (fd == -1)
 		printf("Error al abrir el archivo\n");
 	ft_putstr_fd(a, fd);
 	close(fd);
 	return (0);
}*/
