/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:21:56 by osarsar           #+#    #+#             */
/*   Updated: 2023/04/30 01:29:32 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

size_t	ft_strlen1(char *str);
char	*ft_strdup1(char *str);
char	*ft_strchr1(char *str, int c);
char	*ft_strjoin1(char *s1, char *s2);
char	*split_line(char *str);
char	*static_line(char *str);
char	*get_next_line(int fd);

#endif