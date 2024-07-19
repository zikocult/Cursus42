/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 09:56:10 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/18 09:59:48 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

/* int main (int argc, char **argv) */
/* { */
/* 	if (argc == 2) */
/* 		printf("total: %i\n", ft_strlen(argv[1])); */
/* 	return (0); */
/* } */
