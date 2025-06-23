/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Guillem Barulls <Guillem Barulls>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 10:38:31 by Guillem Barulls   #+#    #+#             */
/*   Updated: 2025/06/05 18:39:37 by pamanzan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	update_env(t_env *data, char *variable)
{
	char	*pwd;

	pwd = (char *)getcwd(NULL, 0);
	if (!pwd)
		return (printf("Minishell: cd: getcwd failed\n"), 1);
	add_elem(data, variable, pwd, "env");
	free(pwd);
	return (data->exit_var);
}

static int	extra_options(t_env *data, char *variable)
{
	t_var	*current;
	int		ret;

	current = (env_search(data, variable));
	if (!current || !current->content || current->content[0] == '\0')
		return (printf("Minishell: cd: %s not set\n", variable), 1);
	ret = chdir(current->content);
	if (ret == -1)
		return (-1);
	if (!ret)
		update_env(data, variable);
	if (!ft_strcmp("OLDPWD", variable) && !ret)
		printf("%s\n", current->content);
	return (chdir(current->content));
}

static int	cd(char *param, t_env *data)
{
	char	*oldpwd;
	int		ret;

	oldpwd = getcwd(NULL, 0);
	if (!oldpwd)
		return (printf("Minishell: cd: getcwd failed\n"), -1);
	if (!param)
		ret = extra_options(data, "HOME");
	else if (!ft_strcmp(param, "-") || !ft_strcmp(param, "--"))
		ret = extra_options(data, "OLDPWD");
	else
		ret = chdir(param);
	if (ret == -1)
	{
		free(oldpwd);
		return (-1);
	}
	add_elem(data, "OLDPWD", oldpwd, "env");
	free(oldpwd);
	update_env(data, "PWD");
	return (ret);
}

int	cd_builtin(t_env *data, char *param)
{
	int	ret;
	int	arg_count;

	arg_count = 0;
	if (param)
		arg_count = count_args_spaces(param);
	if (arg_count > 1)
		return (printf("Minishell: cd: too many arguments\n"), 1);
	else
		ret = cd(param, data);
	if (ret == -1)
	{
		printf("Minishell: cd: %s: no such file or directory\n", param);
		return (1);
	}
	update_env(data, "PWD");
	return (0);
}

int	run_cd(t_env *data, char **str)
{
	int	count;
	int	ret;

	count = 0;
	if (str)
		count = count_args_double_pointer(str);
	if (count > 1)
		return (printf("Minishell: cd: too many arguments\n"), 1);
	if (!str)
		ret = cd_builtin(data, NULL);
	else
		ret = cd_builtin(data, str[0]);
	return (ret);
}
