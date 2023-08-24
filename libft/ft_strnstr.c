/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:37:04 by osarsar           #+#    #+#             */
/*   Updated: 2022/10/16 09:37:06 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*need;
	char	*hay;

	hay = (char *)haystack;
	need = (char *)needle;
	if (*need == '\0')
		return (hay);
	i = 0;
	while (hay[i] && i < len)
	{
		j = 0;
		if (hay[i] == need[j])
		{
			while (i + j < len && need[j] == hay[i + j])
			{
				if (need[j + 1] == '\0')
					return (hay + i);
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
