/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_command_na.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 13:57:35 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/25 15:43:28 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	command_not_found(t_minishell *m)
{
	printf("zsh: command not found: %s\n", *(m->tab));
	m->dollar_question = 127;
}
