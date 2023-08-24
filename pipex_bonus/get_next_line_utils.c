/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <osarsar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:06:05 by osarsar           #+#    #+#             */
/*   Updated: 2023/05/01 23:26:52 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen1(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup1(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc((ft_strlen1(src) + 1) * sizeof(char));
	if (!dest)
		return (0);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strchr1(char *str, int c)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (c == '\0')
		return (&str[ft_strlen1(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (str);
		i++;
	}
	return (0);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*string;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (0);
	if (!s2)
		return (ft_strdup1(s1));
	if (!s1)
		return (ft_strdup1(s2));
	string = malloc((ft_strlen1(s1) + ft_strlen1(s2)) + 1);
	if (!string)
		return (0);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	while (s2[j])
		string[i++] = s2[j++];
	string[i] = '\0';
	return (string);
}
