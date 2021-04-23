/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_command_exit.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:57:35 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 19:26:03 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_int_tab(int **tab)
{
	int	**fixed_tab;

	fixed_tab = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(fixed_tab);
}

/*
**	command_exit function exits the program if user prompted exit
*/

void		command_exit(t_minishell *m)
{
	free_tab(m->fixed_tab);
	free_tab(m->fixed_str_variables);
	free_int_tab(m->fixed_int_variables);
	exit(EXIT_SUCCESS);
}
