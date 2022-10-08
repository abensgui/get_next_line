/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:37:44 by abensgui          #+#    #+#             */
/*   Updated: 2021/11/30 11:40:07 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static int	ft_alloc(int len, int sa, char const *s)
{
	int	ls;
	int	x;

	ls = ft_strlen(s);
	if (len > ls)
		x = ls - sa;
	else
		x = len;
	if (x < 0)
		return (0);
	return (x);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *sr)
{
	char	*p;
	int		i;
	char	*src;

	i = 0;
	if (sr)
	{
		src = (char *) sr;
		p = malloc((ft_strlen(src) + 1) * sizeof(char));
		if (!p)
			return (0);
		while (src[i])
		{
			p[i] = src[i];
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	s = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	if (s1)
	{	
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[k])
			s[i++] = s2[k++];
	}
	s[i] = '\0';
	free((char *)s1);
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ss;
	size_t	i;
	size_t	ls;

	if (s)
	{
		ls = ft_strlen(s);
		ss = malloc((ft_alloc(len, start, s) + 1) * sizeof(char));
		if (!ss)
			return (NULL);
		i = 0;
		while (s[i] && i < len && start < ls && i < ls - start)
		{
			ss[i] = s[i + start];
			i++;
		}
		ss[i] = '\0';
		return (ss);
	}
	return (0);
}
