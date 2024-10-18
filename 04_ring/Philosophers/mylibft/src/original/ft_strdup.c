/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:50:01 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/07/05 10:58:16 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(const char *s)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = (char *)ft_calloc((ft_strlen(s)) + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i])
	{
		ptr[i] = (char)s[i];
		i++;
	}
	return (ptr);
}
