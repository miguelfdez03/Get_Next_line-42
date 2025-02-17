/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miguel-f <miguel-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:43:03 by miguel-f          #+#    #+#             */
/*   Updated: 2025/02/17 22:04:22 by miguel-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/*
 * BUFFER_SIZE: Tamaño del buffer de lectura.
 * Se puede modificar durante la compilación usando -D BUFFER_SIZE=n
 * Por defecto es 42 si no se especifica otro valor
 */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*
 * Función principal que lee una línea de un archivo
 * @param fd: Descriptor del archivo a leer
 * @return: La línea leída o NULL si hay error o fin de archivo
 */
char	*get_next_line(int fd);

/*
 * Funciones auxiliares para el manejo de cadenas
 * ft_strdup: Crea una copia de una cadena
 * ft_strjoin: Une dos cadenas
 * ft_strchr: Busca un carácter en una cadena
 * ft_substr: Extrae una parte de una cadena
 * ft_strlcpy: Copia una cadena de forma segura
 * ft_strlen: Calcula la longitud de una cadena
 */
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

#endif
