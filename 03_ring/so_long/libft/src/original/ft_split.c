/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarulls <gbarulls@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 23:59:19 by gbarulls          #+#    #+#             */
/*   Updated: 2024/08/07 09:40:13 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_strndup_local(const char *s, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (n == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (NULL);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**error_mal(char **split, int count)
{
	while (count-- > 0)
		free(split[count]);
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
		if (split[count++] == 0)
			return (error_mal(split, count));
	}
	split[count] = NULL;
	return (split);
}

// int main(void)
// {
// 	char **splitted;
// 	char prueba1[100] = "AbraCadabra pata de cabra";
// 	char prueba2[100] = " ";
// 	char prueba3[100] = "hello!";
// 	splitted = ft_split(prueba1, 'a');
// 	for (int i = 0; splitted[i] != NULL; i++)
// 		printf("%s\n", splitted[i]);
// 	for (int i = 0; splitted[i] != NULL; i++)
// 		free(splitted[i]);
// 	printf("**********************************\n");
// 	splitted = ft_split(prueba2, 'a');
// 	for (int i = 0; splitted[i] != NULL; i++)
// 		printf("%s\n", splitted[i]);
// 	for (int i = 0; splitted[i] != NULL; i++)
// 		free(splitted[i]);
// 	printf("**********************************\n");
// 	splitted = ft_split(prueba3, ' ');
// 	for (int i = 0; splitted[i] != NULL; i++)
// 		printf("%s\n", splitted[i]);
// 	for (int i = 0; splitted[i] != NULL; i++)
// 		free(splitted[i]);
// 	return (0);
// }
