/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:42:28 by miguel-f          #+#    #+#             */
/*   Updated: 2025/02/17 21:56:37 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	copy_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	copy_len = len;
	if (copy_len > s_len - start)
		copy_len = s_len - start;
	substr = (char *)malloc((copy_len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s + start, copy_len + 1);
	return (substr);
}

static char	*read_and_store(int fd, char *stored_text, char *read_buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	while (1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stored_text);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		read_buffer[bytes_read] = '\0';
		if (!stored_text)
			stored_text = ft_strdup("");
		if (!stored_text)
			return (NULL);
		tmp = stored_text;
		stored_text = ft_strjoin(tmp, read_buffer);
		free(tmp);
		if (!stored_text || ft_strchr(stored_text, '\n'))
			break ;
	}
	return (stored_text);
}

static char	*extract_line(char *current_line)
{
	int		i;
	char	*stored_text;

	i = 0;
	while (current_line[i] != '\n' && current_line[i] != '\0')
		i++;
	if (current_line[i] == '\0')
		return (NULL);
	stored_text = ft_substr(current_line, i + 1, ft_strlen(current_line) - i);
	if (!stored_text || *stored_text == '\0')
	{
		free(stored_text);
		return (NULL);
	}
	current_line[i + 1] = '\0';
	return (stored_text);
}

char	*get_next_line(int fd)
{
	static char	*stored_text[MAX_FD];
	char		*current_line;
	char		*read_buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		free(stored_text[fd]);
		stored_text[fd] = NULL;
		return (NULL);
	}
	read_buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!read_buffer)
	{
		free(stored_text[fd]);
		stored_text[fd] = NULL;
		return (NULL);
	}
	current_line = read_and_store(fd, stored_text[fd], read_buffer);
	free(read_buffer);
	stored_text[fd] = NULL;
	if (!current_line)
		return (NULL);
	stored_text[fd] = extract_line(current_line);
	return (current_line);
}

/* # include <stdio.h>

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error al abrir el archivo\n");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Line: %s\n", line);
		free(line);
	}
	close(fd);
	return (0);
} */