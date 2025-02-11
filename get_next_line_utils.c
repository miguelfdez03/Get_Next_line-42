/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:42:40 by miguel-f          #+#    #+#             */
/*   Updated: 2025/02/10 17:58:38 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	if (c == '\0')
		return ((char *)s);
	else
		return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*new_str;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len])
		len++;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	const char	*src_start;
	size_t		src_len;
	size_t		i;

	src_start = src;
	src_len = 0;
	while (src_start[src_len] != '\0')
		src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len1;
	size_t	len2;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total_len = len1 + len2 + 1;
	result = (char *)malloc(total_len * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, total_len);
	ft_strlcpy(result + len1, s2, len2 + 1);
	return (result);
}
