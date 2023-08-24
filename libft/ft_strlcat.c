/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:42:09 by osarsar           #+#    #+#             */
/*   Updated: 2022/10/16 09:42:10 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;
	size_t	j;

	i = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	j = dst_len;
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[i] != '\0' && j < dstsize - 1 && dstsize != 0)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
