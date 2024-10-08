/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobledo <grobledo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:07:24 by greg              #+#    #+#             */
/*   Updated: 2024/07/31 10:52:07 by grobledo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*---------INCLUDE-------------*/
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <termios.h>
# include <sys/ioctl.h>

/*----------ERROR MES-----------*/
# define ERR_TOKEN "minishell: syntax error near unexpected token `newline'\n"
# define ERR_TOKEN_SHORT "minishell: syntax error near unexpected token `"
# define ERR_NUM "numeric argument required"

/*----------STRUCTURE-----------*/
//structure tableau de cmd
typedef struct s_cmd
{
	char	**cmd;
	char	**stdin;
	char	**stdout;
}	t_cmd;

//main structure
typedef struct s_min
{
	t_cmd	**struct_cmd;
	pid_t	pid;
	char	**c_env;
	char	**c_exp;
	char	*line;
	char	*prompt;
	char	*val_home;
	int		ret_err;
	int		fd_hd[2];
	int		nb_passage_exp;
	int		nb_cmd;
	int		sig_heredoc;
	int		rl_done;
	int		in_cmd;
}	t_min;

extern t_min	g_mini;
//t_min	g_mini;

/*--------------------------BUILT-IN-----------------------------------*/
//cd.c
void	cd(t_min *mini, char **cmd);
void	change_value_pwd(char **str);
void	change_value_oldpwd(char **str, char *pwd, char *oldpwd);

//cd_tild.c
char	*cd_tildpwd(char *str);
void	change_valtab(t_min *mini, char **cmd);
void	change_valcdtild(t_min *mini, char **cmd);
void	cd_noarg(t_min *mini);

//cd_utils.c
char	*recup_pwd(char **str);
char	*recup_oldpwd(char **str);
int		check_arg(char *str);
void	cpy_value(char *name_var, char **str, char *new_val);

//cd_utils2.c
void	create_oldpwd(t_min *mini);
int		check_oldpwd(char **str);

//echo.c
void	echo(char **cmd);

//env.c
void	ft_env(t_min *mini, char **cmd);
void	change_val(char **str, char *new_pwd, char *pwd, char *oldpwd);
void	add_reponame(char **str, char *repo);

//exit_pwd_utils.c
void	verif_arg_exit(t_min *mini, int i, char **cmd);

//exit_pwd.c
int		recup_new_pwd(char **str);
void	exit_min(t_min *mini, char **cmd);
void	pwd(char **c_env, char **cmd);
void	change_val_pwdpath(char **str, char **cmd);

//export_addvar.c
void	add_valexp(t_min *mini, char *str);
void	add_valenv(t_min *mini, char *str);

//export_change_val
char	*recup_name(char *cmp);
char	*addegal(char *cmp);
void	redir_changeval(t_min *mini, char *str);

//export_utils.c
char	**fill_exp(char **new_val, char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		tablen(char **s1);
int		check_exp(char **s1, char **s2, int index);
void	print_export(char **str);

//export_utils2.c
int		verif_modif_var(char **str, char *cmp);
void	new_vars(t_min *mini, char *str, int y, char **cmd);

//export.c
char	**order_exp(char **s1, char **s2);
int		verif_modif_var(char **str, char *cmp);
void	export(t_min *mini, char **cmd);

//signals_utils.c
void	echo_control_seq(int c);
void	signal_exit(void);

//signals.c
void	signaux(void);
void	signal_exit(void);

//unset.c
int		check_var(char *str);
void	unset(t_min *mini, char **cmd);

//annexe.c
char	*verif_pwd(char *line);
char	*get_namevar(char *str);
char	*get_tmp(char *line, char cotes);
int		verif_space(char *str);
int		verif_cmdcotesempty(char *line);

/*------------------------PARSE-------------------------------------------*/
//gestion_dollar.c
char	*redir_line(char *line, int nb_dollar);

//gestion_dollar_utils.c
char	*recup_namevar(char *line);
char	*rm_d_dollar(char *tmp);
int		verif_dollarcase(char *line);
int		verif_var(char *name_var);
int		count_nbdollar(char *line);

//gestion_dollar_line.c
char	*recup_valvar(char *name_var);
char	*change_line(char *name_var, char *line);

//gestion_dollar_quotes.c
char	*rm_dollarcotes(char *line, int i, int savedollar);
char	*rmd_bf_cotes(char *line, int savedollar);
int		verif_cotes(char *line);
int		d_outside_cotes(int i, char *line);
int		verif_redirdollar(char *line);

//gestion_dollar_utils2.c
char	*copy_tmp(char *line, int i);

//init.c
char	*recup_valhome(char	**c_env);
void	init_struct(t_min *mini, char **envp);
void	init_export(t_min *mini);
void	free_all(t_min mini);
void	aff_err(char **cmd);

//lexer.c
void	redir_pipe(t_min *mini, t_cmd **cmd);
void	redirection(t_min *mini, t_cmd **cmd);
void	parcour_line(t_min *mini);
char	*modif_line(char *line, int nb_dollar);
void	redirection2(t_min *mini, t_cmd *cmd);

//parse.c
char	**init_cpy(char **str, char **dest);
char	**ft_cpytab(char **tab);
char	**init_exp(char **tab);
void	free_tab(char **tab);
void	verif_struct_cmd(t_cmd **tab_cmd);

// pipe_utils.c
void	ft_child(t_cmd **cmd, int **pp, int i);
void	ft_parent(int **pp, int i);
void	ft_last_command(t_cmd **cmd, int **pp, int i);
void	ft_wait_all(void);

//pipe.c
void	ft_exec2(t_min *mini, char **all_path, char **pathcmd, char **cmd);
void	ft_set_pathexec2(t_min *mini, char **cmd);
int		piping(void);
void end_piping(int i, int **pp);

// printstruc.c
void	printstruc(t_cmd *cmd);
void	printstruc2(t_cmd **cmd);

//modif_tcmd.c
void	modif_cmd(char **cmd);
void	modif_stdin(char **stdin);
void	modif_stdout(char **stdout);
void	free_seline(char *s_line, char *e_line);

// redir_utils.c
int		heredoc(char *cond);
int		ft_nb_heredoc(t_cmd **cmd);
char	*ft_last_single_redir_in(t_cmd **cmd);
int		ft_open_file(char *file, int fd, int how);

// redir_utils2.c
int		ft_redir_out(t_cmd **cmd, int nb);
int		ft_what_is_last_redir_in(t_cmd **cmd);

// redir.c
int		ft_redir_in(t_cmd **cmd);

//splitcmd.c
t_cmd	**spliter3(char **inst);

//splitcmd_utils1.c
int		ft_qpar(char *s, int i);
char	*ft_space_bracket(char *s);
int		count_cmd(char *line);
int		count_redir(char **list, char c);
int		count_all_redir(char *temp);

//splitcmd_utils2.c
char	**ft_init_resu(char *line);
t_cmd	*ft_malloc_resu(char **list);
void	ft_copy_inside_simple_cote(char **res, char *line, int *i, int *j);
void	ft_copy_inside_double_cote(char **res, char *line, int *i, int *j);
void	free_t_cmd(t_cmd **cmd);

//splitcmd_utils3.c
char	*remove_double_char(char *line, char c, int remove_both_char);
char	*remove_double_char_q(char *line, char c);

//splitcmd_valid.c
t_cmd	**validation_cmd(t_cmd **resu);

//splitline.c
char	**spliter(void);

// splitline_utils.c
int		iscotevalid(char *line);
int		count_instruct(char *line);
int		is_single_pipe(int j);
void	*ft_test(void *var, void *error);

//verif_cotes.c
void	verif_cmdcotes(t_min *mini);
char	*rm_cotes(char *line, char cotes);

//verif_cotes_utils.c
char	*get_sline(char *line, char cotes);
char	*get_eline(char *line, char cotes);
char	*changecotesline(char *line, char cotes);

//check_cmd.c
char	*check_cmd(char *line);

//verif_pipes.c
char	*verif_pipes(char *line);
void	verif_tmp(char *line);

//utils.c
char	*join_linetmp(char *s_line, char *tmp, char *e_line);
char	*join_wout_tmp(char *s_line, char *e_line);
int		count_cotes(char *line);
int		get_endcotes(char *line, char cotes, int j);
int		verif_redirdollar(char *line);
void	verif_tmp(char *line);

/*-----------------------UTILS--------------------------------------------*/
//errmsg.c
int		verif_line(char *line);
void	ft_print_error_msg3(char *s1, char *s2, char *s3);
void	ft_export_error_msg(char *s1, char *s2);

//5 fichiers
//itoa.c (libft)
char	*ft_itoa(int nb);

//ft_split.c (libft)
char	**ft_split(char const *s, char c);

//utils.c
char	*ft_strdup(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strlen(char *str);
int		strdigit(char *str);
int		ft_isdigit(char c);

// utils2.c
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(const char *str);
int		find_cotes(char *line);
void	ft_bzero(void *s, int n);
char	*ft_strchr(const char *s, int c);

// utils3.c
char	*ft_strtrim(char *s1, char *set);
void	*ft_calloc(int count, int size);

// printstruc.c
void	printstruc(t_cmd *cmd);
void	printstruc2(t_cmd **cmd);

//fonction read_line(signaux.c)
void	rl_replace_line(const char *text, int clear_undo);

/*-----------------------------------------------------------------------*/

//exec.c
char	**recup_path(t_min *mini);
char	**init_cmd(char **cmd, char **pathcmd);
void	ft_execve(t_min *mini, char **all_path, char **pathcmd, char **cmd);
void	ft_exec(t_min *mini, char **all_path, char **pathcmd, char **cmd);
void	ft_set_pathexec(t_min *mini, char **cmd);

//exec_utils
char	*recup_pathexec(t_min *mini);
int		aff_errcmd(char **cmd);
int		verif_cmd(char **all_path, char **pathcmd, char **cmd);

#endif