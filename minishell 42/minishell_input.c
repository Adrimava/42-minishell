/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 11:09:47 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 13:47:05 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	free_tab function receives an array of strings and frees all
**	its content, it means every string, and the array itself.
*/

void		free_tab(char **tab)
{
	char	**fixed_tab;

	fixed_tab = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(fixed_tab);
}

/*
**	tab_remove_front_spaces function receives an aray of strings and
**	return that very same array but with its content modified.
**	Now every string which started with one or several spaces
**	starts without them.
*/

static char	**tab_remove_front_spaces(char **tab)
{
	char	**fixed_tab;
	char	*str;
	char	*aux;

	fixed_tab = tab;
	while (*tab)
	{
		aux = *tab;
		while (**tab == ' ' || **tab == '\t')
			(*tab)++;
		str = ft_strdup(*tab);
		free(aux);
		*tab = str;
		tab++;
	}
	return (fixed_tab);
}

/*
**	tab_remove_spaces function receives an aray of strings and
**	return that very same array but with its content modified.
**	Now every string which doesn't have more than one word
**	has all its spaces removed, and those strings with more than
**	one word, has only one space between the first and the second one.
*/

static char	**tab_remove_middle_spaces(char **t, char **fixed_t)
{
	char	*str;
	char	*aux;
	int		i;

	while (*t)
	{
		i = 0;
		aux = *t;
		while ((*t)[i] && (*t)[i] != ' ')
			i++;
		if ((*t)[i] == ' ' && (*t)[i + 1] == ' ')
		{
			(*t)[i++] = 0;
			while ((*t)[i] == ' ' && (!(*t)[i + 1] || (*t)[i + 1] == ' '))
				i++;
			str = ft_strjoin(*t, (*t) + i);
		}
		else
			str = ft_strdup(*t);
		free(aux);
		*t = str;
		t++;
	}
	return (fixed_t);
}

/*
**	tab_remove_last_spaces function receives an aray of strings and
**	return that very same array but with its content modified.
**	Now every string which finished with one or several spaces
**	finishes without them.
*/

static char	**tab_remove_last_spaces(char **tab, char **fixed_tab)
{
	while (*tab)
	{
		*tab = str_flip(*tab);
		tab++;
	}
	tab = tab_remove_front_spaces(fixed_tab);
	while (*tab)
	{
		*tab = str_flip(*tab);
		tab++;
	}
	return (fixed_tab);
}

/*
**	user_input function receives the pointer to an array of strings and it will
**	fill it with the user input read, it is a tab instead of a string because
**	the user can write many commands separated with ";" and the terminal must
**	execute them separately.
**	The function returns a pointer to that tab.
*/

char		**user_input(char ***tab)
{
	int		sz;
	char	input[ARG_MAX];

	write(1, "-> $ ", 5);
	if ((sz = read(0, input, ARG_MAX)) < 0)
	{
		printf("Error: unable to read the input.\n");
		return (NULL);
	}
	else
	{
		input[sz - 1] = 0;
		*tab = tab_remove_front_spaces(ft_split(input, ';'));
		*tab = tab_remove_middle_spaces(*tab, *tab);
		*tab = tab_remove_last_spaces(*tab, *tab);
	}
	return (*tab);
}
