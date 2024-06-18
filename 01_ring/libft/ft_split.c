/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:00:33 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/06/18 08:40:38 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_strndup_local(const char *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	if (n == 0)
		return (NULL);
	str = (char *)ft_calloc(n + 1, sizeof(char));
	if (str == 0)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}

static char	**ft_error_mal(char **split, int count)
{
	while (count > 0)
	{
		free(split[count]);
		count--;
	}
	free(split);
	return (NULL);
}

static int	ft_count_word(char const *str, char c)
{
	int	i;
	int	count;
	int	control;

	i = 0;
	count = 0;
	control = 0;
	while (str[i])
	{
		if (str[i] != c && control == 0)
		{
			control = 1;
			count++;
		}
		else if (str[i] == c)
			control = 0;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		count;
	int		end;
	int		start;

	count = 0;
	end = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!split)
		return (NULL);
	while (count < ft_count_word(s, c) && s[end] != '\0')
	{
		while (s[end] == c)
			end++;
		start = end;
		while (s[end] != c && s[end] != '\0')
			end++;
		split[count] = ft_strndup_local(&s[start], end - start);
		if (split[count] == 0)
			return (ft_error_mal(split, count));
		count++;
	}
	split[count] = NULL;
	return (split);
}
/*
int main(void)
{
	char **splitted;
	char prueba1[100] = "AbraCadabra pata de cabra";
	char prueba2[100] = " ";
	char prueba3[100] = "hello!";
	splitted = ft_split(prueba1, 'a');
	for (int i = 0; splitted[i] != NULL; i++)
	{
		printf("%s\n", splitted[i]);
		free(splitted[i]);
	}	
	free(splitted);
	
	printf("**********************************\n");
	splitted = ft_split(prueba2, 'a');
	for (int i = 0; splitted[i] != NULL; i++)
	{
		printf("%s\n", splitted[i]);
		free(splitted[i]);
	}	
	free(splitted);
	
	printf("**********************************\n");
	splitted = ft_split(prueba3, ' ');
	for (int i = 0; splitted[i] != NULL; i++)
	{
		printf("%s\n", splitted[i]);
		free(splitted[i]);
	}	
	free(splitted);
	
	return (0);
}*/
