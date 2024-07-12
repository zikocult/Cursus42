/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:22:38 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/12 16:31:52 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char *ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

/* int main (void) */
/* { */
/* 	char a[50] = "abcdef"; */
/* 	char b[50]; */

/* 	strcpy(b, a); */
/* 	printf("testeando %s\n", b); */
/* 	return (0); */
/* } */
