/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_command_pwd.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:57:35 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 19:24:56 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	command_pwd function obtains current path if user prompted pwd
*/

void	command_pwd(t_minishell *m)
{
	char		cwd[FILENAME_MAX];

	if (!(getcwd(cwd, FILENAME_MAX)))
	{
		printf("Error: couldn't get the path");
		m->dollar_question = 1;
	}
	else
		printf("%s\n", cwd);
}
