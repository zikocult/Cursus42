/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 16:10:13 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/06/07 17:28:44 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*free_strjoin(char *s1, const char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*heredoc_expansion(t_env *data, char *line)
{
	char	*flag;
	char	*temp;
	char	*new_line;

	flag = NULL;
	if (ft_strchr(line, '\''))
		flag = "\'\0";
	else if (ft_strchr(line, '\"'))
		flag = "\"\0";
	if (flag)
	{
		new_line = ft_strtrim(line, "\"\'");
		handle_dollar(&new_line, data);
		temp = ft_strjoin(flag, new_line);
		free(new_line);
		new_line = free_strjoin(temp, flag);
		free(line);
	}
	else
	{
		handle_dollar(&line, data);
		new_line = ft_strdup(line);
		free(line);
	}
	return (new_line);
}

static char	*read_to_finish(char *delimiter, t_env *data)
{
	char	*line;
	char	*content;
	char	*my_del;

	content = ft_strdup("");
	line = ft_strdup("");
	my_del = ft_strtrim(delimiter, "\'\"");
	while (content)
	{
		free(line);
		line = readline("> ");
		if (!line || !ft_strcmp(line, my_del))
		{
			if (!line)
				ft_putendl_fd("warning: found EOF insted of delimeter", 2);
			break ;
		}
		if (!(ft_strchr(delimiter, '\'') || ft_strchr(delimiter, '\"')))
			line = heredoc_expansion(data, line);
		content = free_strjoin(content, line);
		content = free_strjoin(content, "\n");
	}
	free(line);
	return (free(my_del), content);
}

void	process_heredoc(char *delimiter, t_env *data)
{
	here_signals();
	data->heredoc_content = read_to_finish(delimiter, data);
	non_interactive_signals();
}
