/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:43:13 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/18 11:12:20 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	nbrlen(int nbr)
{
	int len = 0;

	if (nbr == 0)
		return (1);
	if (nbr == -2147483648)
		return (11);
	if (nbr < 0)
	{
		nbr *= -1;
		len++;
	}
	while (nbr > 0)
	{
		nbr = nbr/10;
		len++;
	}
	return (len);
}

char *ft_itoa(int nbr)
{
	int len;
	char *str;

	len = nbrlen(nbr);
	str = (char *)malloc((len + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nbr == -2147483648)
	{
		nbr = 147483648;
		str[0] = '-';
		str[1] = '2';
	}
	if (nbr < 0)
	{
		nbr *= -1;
		str[0] = '-';
	}
	while (nbr / 10 > 0)
	{
		str[len - 1] = (nbr % 10) + '0';
		nbr /= 10;
		len--;
	}
	str[len - 1] = (nbr % 10) + '0';
	return (str);
}

/* int main(int argc, char **argv) */
/* { */
/* 	int nbr; */
/* 	char *str; */

/* 	if (argc == 2) */
/* 	{ */
/* 		nbr = atoi(argv[1]); */
/* 		str = ft_itoa(nbr); */
/* 		printf("%s\n", str); */
/* 	} */
/* 	free(str); */
/* 	return (0); */
/* } */
