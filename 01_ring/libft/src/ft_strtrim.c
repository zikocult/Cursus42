/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:43:02 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2024/06/20 16:54:44 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
