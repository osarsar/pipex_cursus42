/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:27:35 by osarsar           #+#    #+#             */
/*   Updated: 2022/10/15 22:27:39 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*b;
	int		i;
	int		len;

	b = (char *)s;
	len = ft_strlen(b);
	i = 0;
	while (i <= len)
	{
		if (*b == (char)c)
			return (b);
		i++;
		b++;
	}
	return (NULL);
}
