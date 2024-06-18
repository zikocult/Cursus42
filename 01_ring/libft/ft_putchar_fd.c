/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:50:17 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/06/18 14:03:40 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write (fd, &c, 1);
}
/*
// Para las pruebas hay que incluir #include <fcntl.h>
int main (void)
{
 	int fd;

 	fd = open("prueba.txt", O_WRONLY);
 	if (fd == -1)
 		printf("Error al abrir el archivo\n");
 	ft_putchar_fd('a', fd);
 	close(fd);
 	return (0);
}*/
