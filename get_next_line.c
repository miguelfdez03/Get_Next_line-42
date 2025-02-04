/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:42:28 by miguel-f          #+#    #+#             */
/*   Updated: 2025/02/04 14:23:33 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	str[BUFFER_SIZE];
	int			bytes_read;
	static int	counter = 0;

	bytes_read = read(fd, str + counter, BUFFER_SIZE - counter - 1);
	if (bytes_read <= 0)
	{
		return (NULL);
	}
	counter += bytes_read;
	str[counter] = '\0';
	return (str);
}
