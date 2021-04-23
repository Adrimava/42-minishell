/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_ft_split.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:59:15 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/24 18:56:58 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		ft_rows(char const *s, char c)
{
	int i;
	int j;
	int rows;

	i = 0;
	j = 0;
	rows = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] && s[i] != c)
			j = 1;
		if (s[i] == c)
		{
			while (s[i] && s[i] == c)
				i++;
			if (s[i])
				rows++;
		}
		else
			i++;
	}
	return (rows + j);
}

static	char	*delete_front_spaces(char *str)
{
	char	*aux;
	char	*s;

	aux = str;
	while (*str == ' ')
		str++;
	s = ft_strdup(str);
	free(aux);
	return(s);
}

static	char	*ft_str_malloc(char const *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

char			**ft_split(char const *s, char c)
{
	int		rows;
	int		i;
	char	**tab;

	if (!s)
		return (NULL);
	rows = ft_rows(s, c);
	i = -1;
	if (!(tab = malloc(sizeof(char *) * (rows + 1))))
		return (NULL);
	while (++i < rows)
	{
		while (*s == c)
			s++;
		if (!(tab[i] = ft_str_malloc(s, c)))
		{
			while (i > 0)
				free(tab[i--]);
			free(tab);
			return (NULL);
		}
		s += ft_strlen(tab[i]);
	}
	tab[i] = 0;
	return (tab);
}
