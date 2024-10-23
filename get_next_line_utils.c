/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpyciarz <jpyciarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 10:28:25 by jpyciarz          #+#    #+#             */
/*   Updated: 2024/05/27 17:24:16 by jpyciarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	j;
	size_t	s_len;
	size_t	max_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (s_len - start < len)
		max_len = s_len - start;
	else
		max_len = len;
	new_str = (char *)malloc(max_len + 1);
	if (!new_str)
		return (NULL);
	i = start;
	j = 0;
	while (s[i] && j < max_len)
		new_str[j++] = s[i++];
	new_str[j] = '\0';
	return (new_str);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char const *s, int c)
{
	int		i;
	char	let;

	i = 0;
	let = (char)c;
	while (s[i])
	{
		if (s[i] == let)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == let)
	{
		return ((char *)&s[i]);
	}
	else
		return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
