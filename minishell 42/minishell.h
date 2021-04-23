/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 18:01:26 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 20:54:11 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>

#define ARG_MAX 262144

typedef struct	s_minishell
{
	int			parser_block;
	int			dollar_question;
	char		**tab;
	char		**fixed_tab;
	char		**str_variables;
	char		**fixed_str_variables;
	int			**int_variables;
	int			**fixed_int_variables;
}				t_minishell;


/*
**	minishell_initialization.c
*/

void			minishell_init(t_minishell *m);

/*
**	minishell_command_parser.c
*/

void			command_parser(t_minishell *m);

/*
**	minishell_utils
*/

char			**ft_split(char const *s, char c);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*ft_strdup(const char *str);
char			*ft_strjoin(char *s1, char *s2);
char			*str_flip(char	*s);
char			*ft_strchr(char *s, int c);
char			*str_replace(char *s_in, char *s_out);
char			*strdup_from_to(char *s, int start, int c);

/*
**	minishell_input.c
*/

void			free_tab(char **tab);
char			**user_input(char ***tab);

/*
**	minishell_variables.c
*/

void			set_variables(t_minishell *m);
//int				variable_finder(t_minishell *m, char *str);

/*
**	minishell_commands
*/

void			command_cd(t_minishell *m);
void			command_pwd(t_minishell *m);
void			command_echo(t_minishell *m);
void			command_not_found(t_minishell *m);
void			command_exit(t_minishell *m);

#endif
