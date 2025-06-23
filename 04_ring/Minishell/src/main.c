/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 08:04:17 by pamanzan          #+#    #+#             */
/*   Updated: 2025/06/07 17:16:49 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	first_init(t_env *data, char **env)
{
	data->head = NULL;
	data->tail = NULL;
	data->heredoc_content = NULL;
	data->exit_var = 0;
	if (env == NULL || env[0] == NULL)
		init_envi_list(data);
	else
		init_list(data, env);
}

static bool	validation_main(char *command_buff, t_env *data)
{
	if (!command_buff)
	{
		free(command_buff);
		printf("exit\n");
		return (true);
	}
	if (*command_buff == '\0')
	{
		free(command_buff);
		return (false);
	}
	if (ft_strlen(command_buff) > 0)
		add_history(command_buff);
	if (select_type(command_buff, data))
	{
		free(command_buff);
		return (true);
	}
	free(command_buff);
	return (false);
}

int	main(int argc, char **argv, char **env)
{
	char	*command_buff;
	t_env	data;

	if (argc == 1 && argv[0])
		first_init(&data, env);
	write(STDOUT_FILENO, "\033[2J\033[H", 7);
	printf(COLOR_BLUE "Minishell (🚀 Barcelona Edition): Don't panic & ole,  "
		"ole 💃\n\n" COLOR_RESET);
	while (1)
	{
		data.status = data.exit_var;
		data.exit_var = 0;
		interactive_signals();
		command_buff = readline(C_F "Minishell 💻 y OLÉ!💃 " COLOR_RESET);
		non_interactive_signals();
		if (validation_main(command_buff, &data))
			break ;
	}
	return (free_list(&data), 0);
}
