/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 18:16:09 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/02 00:43:19 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
size_t	gnl_ft_strlen(const char *s);
size_t	gnl_ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*gnl_ft_strjoin(char *s1, char const *s2);
char	*gnl_ft_strchr(const char *s, int c);

#endif
