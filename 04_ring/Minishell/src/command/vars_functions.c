/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vars_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patri <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 11:31:22 by patri             #+#    #+#             */
/*   Updated: 2025/06/05 19:02:57 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*expand_variable(char *input, t_env *data)
{
	char	*var_name;
	t_var	*value;
	int		i;

	i = 0;
	var_name = (char *)malloc(ft_strlen(input) + 1);
	if_notstr(var_name);
	while (*input)
		var_name[i++] = *input++;
	var_name[i] = '\0';
	value = env_search(data, var_name);
	free(var_name);
	if (!value)
		return (NULL);
	return (value->content);
}

int	handle_question(char **str, int i, char *temp, t_env *data)
{
	char	*new_str;
	char	*end;

	(void) i;
	new_str = ft_itoa(data->status);
	if (!new_str)
	{
		free(temp);
		return (0);
	}
	end = *str + i + 1;
	build_new_string(str, temp, new_str, end);
	free(new_str);
	data->exit_var = 0;
	return (1);
}

char	*check_quotes(char *result)
{
	int		i;
	int		j;
	char	*new_result;

	j = 0;
	i = mult_dollar(result, '\"');
	new_result = malloc(((ft_strlen(result) - i) + 1));
	if (!new_result)
	{
		perror("malloc");
		exit(4);
	}
	i = 0;
	while (result[i] != '\0')
	{
		while (result[i] == '\"')
			i++;
		if (result[i] == '\0')
			break ;
		new_result[j++] = result[i++];
	}
	new_result[j] = '\0';
	free(result);
	return (new_result);
}

int	expand_mult_intern(char **str, int flag, t_env *data)
{
	char	*result;
	char	*temp;

	result = ft_strdup("");
	temp = *str;
	while (*temp != '\0')
	{
		if (*temp == '$')
			result = expansion(&temp, data, result);
		else if (flag == 1 && (temp)[ft_strlen(temp) - 1] == '\'')
		{
			result = remove_single_quotes(temp);
			*str = result;
			return (1);
		}
		else
			result = append_text(&temp, result, flag);
		if (!result)
			return (1);
	}
	result = check_quotes(result);
	free(*str);
	*str = result;
	return (1);
}

int	expand_mult(char **str, t_env *data)
{
	int		flag;

	flag = 0;
	if ((*str)[0] == '\'')
		flag = 1;
	if (mult_dollar(*str, '$') > 1)
		expand_mult_intern(str, flag, data);
	return (0);
}
