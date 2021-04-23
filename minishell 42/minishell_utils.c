/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaza-va <amaza-va@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 20:19:19 by amaza-va          #+#    #+#             */
/*   Updated: 2020/01/26 19:22:09 by amaza-va         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	int				num;

	num = 0;
	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0') && (num == 0 && i < n))
	{
		num += (unsigned char)s1[i] - (unsigned char)s2[i];
		i++;
	}
	if (num == 0 && i < n)
	{
		num = (unsigned char)s1[i] - (unsigned char)s2[i];
	}
	return (num);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;

	i = 0;
	s = 0;
	if (dst == 0)
		return (dstsize);
	while (src[s] != '\0')
		s++;
	if (dstsize > 0)
	{
		while (src[i] != 0 && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (s);
}

char	*ft_strdup(const char *str)
{
	int					i;
	char				*s;

	i = 0;
	if (!(s = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = 0;
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (!(str = malloc(sizeof(char *) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

/*
**	str_flip function receives a memory allocated string and it returns another
**	one, also memory allocated, but flipped.
*/

char	*str_flip(char *s)
{
	char	*str;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		str[i] = s[len - 1 - i];
		i++;
	}
	str[i] = 0;
	free(s);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (*s == c)
		return (s);
	return (NULL);
}

/*
**	str_replace function receives one memory allocated string (s_in)
**	which is freed, and a second string (s_out).
**	It returns a memory allocated copy of the second string (s_out).
*/

char	*str_replace(char *s_in, char *s_out)
{
	s_out = ft_strdup(s_out);
	free(s_in);
	return (s_out);
}

/*
**	strdup_from_to function returns an allocated memory string from a
**	starting position (start) of another string (s), to a certain
**	character (c) or the end of the string if it can't find it.
*/

char	*strdup_from_to(char *s, int start, int c)
{
	int		len;
	int		i;
	char	*str;

	len = 0;
	if (!s)
		return (NULL);
	while (s[start + len] && s[start + len] != c)
		len++;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
