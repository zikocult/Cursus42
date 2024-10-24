/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_rm_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarulls <gbarulls@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:53:38 by gbarulls          #+#    #+#             */
/*   Updated: 2023/05/26 22:07:54 by gbarulls         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*ft_erase(char *str, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (i < (size_t)ft_strlen(set))
	{
		j = 0;
		while (str[j])
		{
			if (str[j] == set[i])
			{
				k = j;
				while (str[k])
				{
					str[k] = str[k + 1];
					k++;
				}
			}
			j++;
		}
		i++;
	}
	return (str);
}

char	*ft_str_rm_str(char const *s1, char const *set)
{
	char	*str;

	str = (char *)ft_calloc(sizeof(char), (ft_strlen(s1)) + 1);
	if (!str)
		return (NULL);
	str = ft_strdup(s1);
	ft_erase(str, set);
	return (str);
}

// int main(void)
// {
// 	char *str;
// 	// char *str2;
// 	// char *str3;
// 	char frase1[100] = "Hola Mundo abcdefiou";
// 	char frase2[100] = "lorem \n ipsum \t dolor \n sit \t amet";
// 	char frase3[100] = "Habia una vez un barco en Maracana de la Selva";
// 	str = ft_strtrim(frase1, "aeiou");
// 	printf("%s\n", str);
// 	free (str);
// 	str = ft_strtrim(frase2, "aeiou");
// 	printf("%s\n", str);
// 	free(str);
// 	str = ft_strtrim(frase3, "n");
// 	printf("%s\n", str);
// 	free(str);
// 	return (0);
// }
