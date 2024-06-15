/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:43:02 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/06/15 18:21:56 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_set(char str, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && ft_set(s1[start], set))
		start++;
	while (end > start && ft_set(s1[end - 1], set))
		end--;
	str = (char *)ft_calloc(end - start + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (start < end)
		str[i++] = s1[start++];
	return (str);
}
/*
int main(void)
{
	char *str;
	// char *str2;
	// char *str3;
	char frase1[100] = "    Hola Mundo abcdefiou";
	char frase2[100] = "Vamos a ver\t";
	char frase3[100] = "kakkkkHabia una vez un barco en la Selvakkka";
	str = ft_strtrim(frase1, " ");
	printf("%s\n", str);
	free (str);
	str = ft_strtrim(frase2, "\t");
	printf("%s\n", str);
	free(str);
	str = ft_strtrim(frase3, "kaH");
	printf("%s\n", str);
	free(str);
	return (0);
}*/
