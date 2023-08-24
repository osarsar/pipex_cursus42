/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 23:36:35 by osarsar           #+#    #+#             */
/*   Updated: 2022/10/15 23:36:36 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*dest1;
	const unsigned char	*dest2;

	i = 0;
	dest1 = (const unsigned char *)s1;
	dest2 = (const unsigned char *)s2;
	while (i < n)
	{
		if (dest1[i] != dest2[i])
			return (dest1[i] - dest2[i]);
		i++;
	}
	return (0);
}
