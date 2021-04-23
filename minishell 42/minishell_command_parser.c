/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_command_parser.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:57:35 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 19:52:17 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**
*/

void	command_parser(t_minishell *m)
{
	if (ft_strncmp("cd", *(m->tab), 2) == 0)
		command_cd(m);
	else if (ft_strncmp("pwd", *(m->tab), ft_strlen(*(m->tab))) == 0 ||
			ft_strncmp("PWD", *(m->tab), ft_strlen(*(m->tab))) == 0)
		command_pwd(m);
	else if (ft_strncmp("echo", *(m->tab), 4) == 0)
		command_echo(m);
	else if (ft_strncmp("exit", *(m->tab), ft_strlen(*(m->tab))) == 0)
		command_exit(m);
	else if (ft_strncmp("test", *(m->tab), 4) == 0)
	{
		m->str_variables = m->fixed_str_variables;
		while (*(m->str_variables))
		{
			printf("                      [%s]\n", *(m->str_variables));
			m->str_variables++;
		}
	}
	else
	command_not_found(m);
}
