/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbaruls- <gbaruls-@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 12:29:23 by gbaruls-          #+#    #+#             */
/*   Updated: 2025/06/23 18:20:30 by Guillem Barulls  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../mylibft/include/ft_printf.h"
# include "../mylibft/include/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <linux/limits.h>
# include <stdio.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define READ_END 0  // index pipe extremo escritura
# define WRITE_END 1 // index pipe extremo lectura
# define FILE_MODE 0644

/* ========== COLORS ANSI (BOLD) ========== */
// Texto
# define COLOR_RESET "\033[0m" // Resetear estilo
# define COLOR_BOLD "\033[1m"  // Negrita

// Colores básicos
# define COLOR_RED "\033[1;31m"      // Rojo (errores)
# define COLOR_GREEN "\033[1;32m"    // Verde (éxito)
# define COLOR_YELLOW "\033[1;33m"   // Amarillo (advertencias)
# define COLOR_BLUE "\033[1;34m"     // Azul (info)
# define C_F "\033[1;35m" // Rosa flamenco (prompt)
# define COLOR_CYAN "\033[1;36m"     // Cyan (debug)

// Fondos (opcionales)
# define BG_RED "\033[41m"   // Fondo rojo
# define BG_GREEN "\033[42m" // Fondo verde

typedef struct s_var
{
	char			*type;
	char			*var_name;
	char			*content;
	struct s_var	*next;
}					t_var;

typedef struct s_env
{
	t_var			*head;
	t_var			*last_node;
	t_var			*tail;
	char			*heredoc_content;
	int				num_pipes;
	int				exit_var;
	int				status;
}					t_env;

typedef struct s_par
{
	char			*command;
	char			**parameter;
	char			**infile;
	char			**outfile;
	struct s_par	*next;
}					t_par;

typedef struct s_parse
{
	char			*command;
	char			*parameter;
	char			*infile;
	char			*outfile;
	int				in_single_quotes;
	int				in_double_quotes;
	int				mode;
	t_par			*head;
	t_par			*tail;
}					t_parse;

typedef struct s_child
{
	int				i;
	int				**pipes;
	int				num_pipes;
	int				position;
	int				fd;
	int				last_fd;
	int				heredoc_pipe[2];
}					t_child;

// COMMAND
void				start_expansion(t_parse *parse_data, t_env *data);
void				execute_command(t_par *current, t_env *data);

// PATH
char				*find_path(t_par *current, t_env *data);
char				*check_path(t_par *current, t_env *data);
char				*get_full_path(char *path, char *command);

// INIT_FUNCTIONS
void				init_envi_list(t_env *data);
void				init_parse_state(t_parse *state, char *command_buff);
void				init_list(t_env *data, char **env);
void				init_parse(char *command_buff, t_parse *state);

// BODY_FUNCTIONS
int					select_type(char *command_buff, t_env *data);
void				print_token(t_parse *data);

// SECURITY_FUNCTIONS
void				malloc_error(char *str);
char				*if_notstr(char *str);
void				error_msg(char *str, int flag);

// VARS_FUNCTIONS
char				*expand_variable(char *input, t_env *data);
int					expand_mult_intern(char **str, int flag, t_env *data);
int					expand_mult(char **str, t_env *data);
int					handle_question(char **str, int i, char *temp, t_env *data);

// VARS_UTILS
int					not_expansion(char **str, char *temp, char *end);
char				*extract_expand(char *str, int i, t_env *data,
						char **end_ptr);
int					build_new_string(char **str, char *temp, char *new_str,
						char *end);
int					dollar_search(char *str);

// DOLLAR_FUNCTIONS
int					handle_dollar(char **str, t_env *data);

// EXPAND_QUOTES
int					single_quotes(char **str, t_env *data);
int					double_simple_dollar(char **str, t_env *data);
int					simple_double_dollar(char **str, t_env *data);
int					double_quotes_dollar(char **str, t_env *data);

// EXPAND_UTILS
int					mult_dollar(char *str, char c);
char				*ft_strjoin_free(char *s1, char *s2);
char				*expansion(char **temp, t_env *data, char *result);
char				*append_text(char **temp, char *result, int flag);
int					expand_mult(char **str, t_env *data);

// STD_UTILS
int					process_data(t_parse *node, t_env *data,
						int (*func)(char **, t_env *));

// MORE_UTILS
int					count_args_double_pointer(char **ptr);
int					count_args_spaces(char *param);

// BUILT_UTILS
int					check_built(t_child params, t_par *current, t_env *data);

// EXPORT_LIST
void				export_list_builtin(t_env *data);

// EXPORT_BUILTIN
int					export_builtin(char *str, t_env *data);
int					run_export(t_env *data, char **str);

// ADD_UTILS
char				*create_var(char *str);
char				*create_value(char *str);

// ENV_FUNCTIONS
void				*create_node2(char *env_var, t_var *new_node,
						char *equal_sign);
t_var				*create_node(char *env_var);
t_var				*env_search(t_env *data, char *str);
t_var				*insert_blank_node(t_env *data);

// ENV_BUILTIN
void				env_list_builtin(t_env *data);
int					env_builtin(char *str, t_env *data);
int					run_env(t_env *data, char **str);

// ENV_MSG_ERROR
void				env_msg_error(char *str, int flag);

// EXIT
void				run_exit(t_parse *state, t_env *data);

// ECHO_FUNCTIONS
int					run_echo(char **args);

// PWD_BUILTIN
int					run_pwd(void);

// ADD_VAR
int					add_elem(t_env *data, char *name, char *content,
						char *type);
int					run_command_var(t_env *var, t_parse *data, bool action);

// COMMAND_VAR
int					command_var(t_env *var, t_parse *data);
bool				select_var(t_par *current, t_par *next, t_parse *data);

// COMMAND_VAR2
void				add_command(char *str, t_env *data);
void				remove_node_var(t_par *current, t_par *next, t_parse *data);

// UNSET_BUILTIN
void				unset_builtin(t_env *data, char *str);
int					run_unset(t_env *data, char **str);

// VALIDATE_REDIRECTIONS
bool				check_consecutive_redirections(char *cmd_buff);

// VALIDATE_BUFF
bool				validate_cmdbuff(char *cmd_buff);
bool				check_parse_error(char c, int count);

// VALIDATE_UTILS
void				jump_single_quotes(char *cmd_buff, int *i);
void				jump_double_quotes(char *cmd_buff, int *i);
void				init_vars(int *i, int *count, char *last_char);
void				validation_reset(int *count, char *last_char);

// PARSE_NODE
void				free_temp_data(t_parse *data);
void				copy_data(t_par *new_node, t_parse *data);
void				add_node(t_parse *data);

// PARSE_INIT
void				init_newnode(t_par *new_node);
void				init_data(t_parse *data, bool mode);
void				free_parse(t_parse *data);

// PARSE_UTILS
void				append_parameter(char **parameter, char *token, int mode);
char				*ft_strndup(const char *s, size_t n);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);

// PARSE_TOKEN
void				process_token(char *start, char *end, int *mode,
						t_parse *data);
char				*handle_special_char(char *end, int *mode, t_parse *data);
void				parse_token(char *cmd_buff, t_parse *data);

// PARSE_REMOVE_QUOTES
void				remove_quotes_from_par(t_par *current);
void				remove_quotes_from_par2(t_par *current, int i);
bool				search_dollar_parse(char *str);
char				*return_str_parse(char *str);
char				*remove_single_quotes(char *str);
char				*remove_double_quotes(char *str);

// VALIDATE_QUOTES
bool				validate_quotes(char *cmd_buff);
bool				len_buff(char *cmd_buff);

// HEREDOC
void				process_heredoc(char *delimiter, t_env *data);
char				*free_strjoin(char *s1, const char *s2);
int					run_heredoc(char *delimiter, t_env *data, char *command);

// CD
int					cd_builtin(t_env *data, char *param);
int					run_cd(t_env *data, char **str);

// MAIN_SIGNALS
void				interactive_signals(void);
void				non_interactive_signals(void);

// HERE_SIGNALS
void				here_signals(void);

// PIPE_PATH.C
char				**enviroment(t_env *data);
int					**create_big_pip(int num_pipes);

// PIPE_COMMAND.C
void				create_pipes(int **pipes, int num_pipes);
void				close_pipes(int **pipes, int num_pipes);
void				close_parent_pipes(int i, int num_pipes, int **pipes);
void				end_execute(t_child params, t_env *data);

// EXTRA_PIPE
int					count_pipes(t_parse *state);
int					count_outfile(t_par *current);
int					count_vars(t_env *data);
int					count_double_inf(t_par *current);
int					count_total_infile(t_par *current);

// PIPE
void				build_command_args(t_par *current, char **res);
void				execute_pipex(t_parse *state, t_env *data);
void				write_heredoc(t_env *data, t_child *params);

//CHILD_FUNCTIONS
void				handle_child_process(t_par *current, t_child params,
						t_env *data);
char				*new_file_name(char *str);
void				redirect_io(t_par *current, t_child params, t_env *data);

// REDIRECT
void				close_previous_fd(t_child *params);
void				redirect_and_close(int fd, int std_fd);
int					return_open(t_par *current);
int					search_doble_inf(t_par *current);
char				*search_file(t_par *current);

// REDI HEREDOC
int					handle_input_heredoc(t_par *current, t_child *params,
						t_env *data);

// REDI INFILE
int					handle_input_redirection(t_par *current, t_child *params,
						t_env *data);

// REDI OUTFILE
int					handle_output_redirection(t_par *current, t_child *params);

// FREE_FUNCTIONS
void				free_pipes(int **pipes, int num_pipes);
void				free_memory(char **ptr);
void				free_list(t_env *data);
void				free_array(char **array, int size);

#endif
