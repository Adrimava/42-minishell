/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_initialization.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:57:35 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 19:57:22 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	minishell_init function:
**		$creates two arrays, one for string variables and one for int variables
**		$initialize the following flags:
**			-parser_bock	(this flag avoid calling command_parser function
**							when activated). [It's now initialized in main]
*/

void	minishell_init(t_minishell *m)
{
	int	i;

	if (!(m->str_variables = malloc(sizeof(char *) * (1000 + 1))))
		return ;
	if (!(m->int_variables = malloc(sizeof(int *) * (1000 + 1))))
		return ;
	m->fixed_str_variables = m->str_variables;
	m->fixed_int_variables = m->int_variables;
	i = 0;
	while (i < 1000)
	{
		*(m->str_variables) = 0;
		*(m->int_variables) = 0;
		m->str_variables++;
		m->int_variables++;
		i++;
	}
}
