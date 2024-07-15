/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:07:08 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/15 17:16:46 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_countwords(char *str)
{
	int i = 0;
	int count = 0;

	while (str[i])
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 11)) && str[i])
			i++;
		if (str[i])
			count++;
		while ((str[i] != ' ' && (str[i] < 9 || str[i] > 11)) && str[i])
			i++;
	}
	return (count);
}
char    **ft_split(char *str)
{
	int i = 0, j, k;
	char **split;
	int count = 0;
	split = (char **)malloc((ft_countwords(str) + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (str[i])
	{
		while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 11)) && str[i])
			i++;
		if (str[i])
		{
			j = i;
			while ((str[i] != ' ' && (str[i] < 9 || str[i] > 11)) && str[i])
				i++;
			split[count] = (char *)malloc((i - j + 1) * sizeof(char));
			k = 0;
			while (j < i)
				split[count][k++] = str[j++];
			split[count][k] = '\0';
			count++;
			while ((str[i] == ' ' || (str[i] >= 9 && str[i] <= 11)) && str[i])
                i++;
		}
	}
	split[count] = NULL;
	return (split);
}
//
// int main (void)
// {
// 	char **split;
// 	char str[200] = "     Hola    s       Mundo que tal           alñkda       a";
// 	int i = 0;
//
// 	printf("El total de palabras son: %i\n", ft_countwords(str));
// 	split = ft_split(str);
// 	while (i < ft_countwords(str))
// 	{
// 		printf("Word %i: %s\n", i, split[i]);
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// 	return (0);
// }
