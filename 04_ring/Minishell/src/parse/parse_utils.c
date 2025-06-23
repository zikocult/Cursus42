/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:24:41 by Guillem Bar       #+#    #+#             */
/*   Updated: 2025/04/28 16:39:12 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*ptr;
	size_t	len;

	i = 0;
	if (n < ft_strlen(s))
		len = n;
	else
		len = ft_strlen(s);
	ptr = (char *)ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i] && i < n)
	{
		ptr[i] = (char)s[i];
		i++;
	}
	return (ptr);
}

char	*ft_strcat(char *dst, const char *src)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(dst);
	while (src[i] != '\0')
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = '\0';
	return (dst);
}

static void	consecutive_copy_param(int mode, char *temp, char **parameter,
		char *token)
{
	ft_strcpy(temp, *parameter);
	if (mode == 0)
		ft_strcat(temp, "#");
	else if (mode == 1)
		ft_strcat(temp, "#_");
	else if (mode == 2)
		ft_strcat(temp, "#_");
	else if (mode == 4)
		ft_strcat(temp, "#>");
	else if (mode == 3)
		ft_strcat(temp, "#<");
	ft_strcat(temp, token);
	free(*parameter);
	*parameter = temp;
}

void	append_parameter(char **parameter, char *token, int mode)
{
	size_t	len;
	char	*temp;

	if (*parameter)
	{
		len = ft_strlen(*parameter) + ft_strlen(token) + 4;
		temp = (char *)malloc(len);
		if (temp)
			consecutive_copy_param(mode, temp, parameter, token);
	}
	else
	{
		if (mode == 1)
			*parameter = ft_strjoin("#_", token);
		else if (mode == 2)
			*parameter = ft_strjoin("#_", token);
		else if (mode == 4)
			*parameter = ft_strjoin("#>", token);
		else if (mode == 3)
			*parameter = ft_strjoin("#<", token);
		else
			*parameter = ft_strjoin("#", token);
	}
	free(token);
}
