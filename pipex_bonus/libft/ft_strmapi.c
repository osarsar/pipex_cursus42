/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 22:28:34 by osarsar           #+#    #+#             */
/*   Updated: 2022/10/15 22:28:37 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*p;
	int		i;

	if (s == 0 || f == 0)
		return (NULL);
	p = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (p == 0)
		return (NULL);
	i = 0;
	while (*(s + i) != '\0')
	{
		*(p + i) = f(i,*(s + i));
		i++;
	}
	*(p + i) = '\0';
	return (p);
}
