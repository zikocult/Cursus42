/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamanzan <pamanzan@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 20:05:43 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 08:16:06 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	single_quotes(char **str, t_env *data)
{
	int		len;
	char	*new_com;

	(void)data;
	len = ft_strlen(*str);
	if ((*str)[0] == '\'' && (*str)[len - 1] == '\'')
	{
		new_com = remove_single_quotes(*str);
		*str = new_com;
		if ((*str)[0] == '\"')
		{
			new_com = remove_double_quotes(*str);
			*str = new_com;
			handle_dollar(str, data);
		}
		return (1);
	}
	return (0);
}

int	simple_double_dollar(char **str, t_env *data)
{
	int		i;
	int		len;
	char	*new_com;

	(void)data;
	if ((*str)[0] == '\'' && (*str)[1] == '\"')
	{
		new_com = return_str_parse(*str);
		len = ft_strlen(new_com);
		*str = (char *)malloc(sizeof(char) * (len + 2 + 1));
		(*str)[0] = '\"';
		i = 0;
		while (i < len)
		{
			(*str)[i + 1] = new_com[i];
			i++;
		}
		(*str)[len + 1] = '\"';
		(*str)[len + 2] = '\0';
		free(new_com);
		return (1);
	}
	return (0);
}

int	double_simple_dollar(char **str, t_env *data)
{
	int		i;
	int		len;
	char	*new_com;

	if ((*str)[0] == '\"' && (*str)[1] == '\'')
	{
		new_com = return_str_parse(*str);
		handle_dollar(&new_com, data);
		len = ft_strlen(new_com);
		*str = (char *)malloc(sizeof(char) * (len + 2 + 1));
		(*str)[0] = '\'';
		i = 0;
		while (i < len)
		{
			(*str)[i + 1] = new_com[i];
			i++;
		}
		(*str)[len + 1] = '\'';
		(*str)[len + 2] = '\0';
		free(new_com);
		return (1);
	}
	return (0);
}

int	double_quotes_dollar(char **str, t_env *data)
{
	char	*new_str;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(*str);
	if (len == 0)
		return (0);
	if ((*str)[0] == '\"' && (*str)[len - 1] == '\"')
	{
		while ((*str)[i] == 32)
			i++;
		new_str = remove_double_quotes(*str);
		handle_dollar(&new_str, data);
		*str = new_str;
		return (1);
	}
	return (0);
}
