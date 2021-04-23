/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_command_echo.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:57:35 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 20:55:16 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	command_echo function mimics "echo" command behaviour in shell
*/

void	command_echo(t_minishell *m)
{
	int	var_pos;
	//char	*str;
	
	if (ft_strncmp("echo ", *(m->tab), 5) == 0)
	{
		if ((*(m->tab))[5] == '$')
		{
			//var_pos = variable_finder(m, str);
			//printf("----%d----", var_pos);
		}
		printf("%s\n", *(m->tab) + 5);
	}
	else if (ft_strncmp("echo", *(m->tab), ft_strlen(*(m->tab))) == 0)
		printf("\n");
	else
		command_not_found(m);
}
