/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amylle <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 17:38:53 by amylle            #+#    #+#             */
/*   Updated: 2023/11/18 17:17:42 by amylle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int			i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strjoin(char *str, char const *buff)
{
	int		j;
	int		i;
	char	*res;

	if (!str)
		str = ft_calloc(1, 1);
	if (!str || !buff)
		return (NULL);
	res = (char *)malloc((ft_strlen(str) + ft_strlen(buff) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	if (str)
		while (str[++i])
			res[i] = str[i];
	j = -1;
	while (buff[++j])
		res[i + j] = buff[j];
	res[i + j] = '\0';
	free (str);
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*res;
	size_t		i;

	if (!s || ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	if (start + len < ft_strlen(s))
		res = (char *)malloc((len + 1) * sizeof(*s));
	else
		res = (char *)malloc(((ft_strlen(s)) - start + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	unsigned char	*s;
	unsigned int	i;

	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	s = ptr;
	i = 0;
	while (i < nmemb * size)
	{
		s[i] = 0;
		i++;
	}
	return (ptr);
}
