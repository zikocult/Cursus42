/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls->                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:38:34 by gbaruls-          #+#    #+#             */
/*   Updated: 2024/08/16 11:14:39 by gbaruls-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/include/ft_printf.h"
#include "../libft/include/libft.h"

typedef struct s_pipe
{
	char	*cmd1;
	char	*cmd2;
	char	*param1;
	char	*param2;
	char	**paths;
}	t_pipe;

#ifndef PIPEX_H
# define PIPEX_H

void	init_pipex(char *argv, char **env, t_pipe *data);

#endif
