/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 15:00:33 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/06/20 17:26:59 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*ft_strndup_local(const char *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (n == 0)
		return (NULL);
	str = (char *)ft_calloc(n + 1, sizeof(char));
	if (!str)
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
	int	control;

	i = 0;
	control = 0;
	while (*str)
	{
		if (*str != c && control == 0)
		{
			control = 1;
			i++;
		}
		else if (*str == c)
			control = 0;
		str++;
	}
	return (i);
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
		if (!split[count])
			return (ft_error_mal(split, count));
		count++;
	}
	split[count] = NULL;
	return (split);
}