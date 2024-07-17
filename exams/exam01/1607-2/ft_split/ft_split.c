/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 22:53:23 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/16 23:34:03 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	count_words(char *str)
{
	int i = 0;
	int count = 0;

	while(str[i])
	{
		while (str[i] == ' ' || str[i] == 9 || str[i] == 10 || str[i] == 11)
			i++;
		if(str[i])
			count++;
		while (str[i] != ' ' && str[i] != 9 && str[i] != 10 && str[i] != 11 && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(char *str)
{
	int len = 0;
	int count = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	char **split;

	len = count_words(str);
	split = (char **)malloc((len + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	while (len > count)
	{
		while (str[i] == ' ' || str[i] == 9 || str[i] == 10 || str[i] == 11)
			i++;
		if(str[i])
			j = i;
		while (str[i] != ' ' && str[i] != 9 && str[i] != 10 && str[i] != 11 && str[i])
			i++;
		split[count] = (char *)malloc((i - j + 1) * sizeof(char *));
		k = 0;
		while (j < i)
			split[count][k++] = str[j++];
		split[count][k] = '\0';
		count++;
	}
	split[count] = NULL;
	return (split);
}

// int main (int argc, char **argv)
// {
// 	int i = 0;
// 	char **split;
//
// 	if (argc == 2)
// 	{
// 		int len = count_words(argv[1]);
// 		split = ft_split(argv[1]);
// 		while (i < len)
// 		{
// 			printf("[%d] - %s\n", i, split[i]);
// 			i++;
// 		}
// 		free(split);
// 	}
// 	return (0);
// }
