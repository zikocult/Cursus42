/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 16:36:25 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/05/19 16:55:10 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*create_var(char *str)
{
	char	*var;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i] != '=' && str[i])
	{
		count++;
		i++;
	}
	var = (char *)ft_calloc(count + 1, sizeof(char));
	if (!var)
		return (NULL);
	while (j < i)
	{
		var[j] = str[j];
		j++;
	}
	return (var);
}

char	*create_value(char *str)
{
	int		i;
	char	*value;

	i = 0;
	value = (char *)ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!value)
		return (NULL);
	while (str[i])
	{
		value[i] = str[i];
		i++;
	}
	return (value);
}
