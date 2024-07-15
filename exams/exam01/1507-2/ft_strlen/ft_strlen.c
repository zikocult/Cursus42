/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 18:09:48 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/15 18:14:21 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

int ft_strlen(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i])
	{
		i++;
		count++;
	}
	return (count);
}

/* int main(int argc, char **argv) */
/* { */
/* 	if (argc == 2) */	
/* 		printf("Número de letras: %i \n", ft_strlen(argv[1])); */
/* 	return (0); */
/* } */
