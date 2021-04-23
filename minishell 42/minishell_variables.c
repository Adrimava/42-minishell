/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_variables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:57:35 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 21:08:47 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*char		*variable_finder(t_minishell *m)
{
	int		var_pos;
	char	*str;
	
	str = strdup_from_to(*(m->tab), 0, '=');
	//printf("------%s------", str);////////////////
	m->str_variables = m->fixed_str_variables;
	while (*(m->str_variables) &&
	ft_strncmp(*(m->str_variables), str, ft_strlen(str)))
	{
		m->str_variables++;
		var_pos++;
	}
	free(str);
	return (var_pos);
}*/

/*
**	variable_counter function locates the position a variable was previously
**	defined, or first available position if it wasn't.
**	This function also set a pointer *(m->str_variables) to that very position.
*/

static int	variable_counter(t_minishell *m)
{
	int		var_pos;
	char	*str;
	
	str = strdup_from_to(*(m->tab), 0, '=');
	//printf("------%s------", str);////////////////
	m->str_variables = m->fixed_str_variables;
	while (*(m->str_variables) &&
	ft_strncmp(*(m->str_variables), str, ft_strlen(str)))
	{
		m->str_variables++;
		var_pos++;
	}
	free(str);
	return (var_pos);
}

/*
**	set_variables function stores every user defined variable,
**	replacing them if necessary with their latest defined value
*/

void		set_variables(t_minishell *m)
{
	char	*str;
	int		var_pos;

	if (!ft_strchr(*(m->tab), ' '))
	{
		m->parser_block = 1;
		var_pos = variable_counter(m);
		*(m->str_variables) = str_replace(*(m->str_variables), ((*(m->tab))));
	}
	else if ((str = ft_strchr(*(m->tab), ' ')))
	{
		*(m->tab) = str_replace(*(m->tab), ++str);
	}
}
