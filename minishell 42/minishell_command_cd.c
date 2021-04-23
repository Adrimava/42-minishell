/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_command_cd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:57:35 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 19:32:06 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	command_cd function changes directory if user prompted cd and a valid path
*/

void	command_cd(t_minishell *m)
{
	if (ft_strncmp("cd ", *(m->tab), 3) == 0)
	{
		if ((chdir(*(m->tab) + 3)) != 0)
		{
			printf("cd: no such file or directory: %s\n", *(m->tab) + 3);
			m->dollar_question = 1;
		}
	}
	else if (ft_strncmp("cd", *(m->tab), ft_strlen(*(m->tab))) == 0)
		chdir(getenv("HOME"));/////////////////getenv no está explícitamente permitida///////////////
	else
		command_not_found(m);
}
