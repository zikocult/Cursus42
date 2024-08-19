/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 10:02:35 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/08/19 13:07:11 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

	// ft_printf("%s\n", data.cmd[0]);
	// ft_printf("%s\n", data.cmd[1]);
	// ft_printf("%s\n", data.param[0]);
	// ft_printf("%s\n", data.param[1]);
	// ft_printf("%s\n", data.files[0]);
	// ft_printf("%s\n", data.files[1]);
	// ft_printf("%i\n", data.infile);
	// ft_printf("%i\n", data.outfile);

int	main(int argc, char **argv, char **env)
{
	t_pipe	data;

	if (argc == 5 && argv)
	{
		init_path(env, &data);
		init_cmd(argc - 2, argv, &data);
		init_files(argc, argv, &data);
		check_files(&data);
		check_cmds(&data, argc - 3);
		clean_exit(&data);
	}
	else
		error_args();
	return (0);
}
