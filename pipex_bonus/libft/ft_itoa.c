/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: osarsar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 10:06:43 by osarsar           #+#    #+#             */
/*   Updated: 2022/10/16 10:06:45 by osarsar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
	{
		i++;
		return (i);
	}
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}	

char	*ft_itoa(int n)
{
	char		*p;
	int			s;
	long int	nb;

	nb = n;
	s = size(nb);
	p = (char *)malloc(sizeof(char) * (s + 1));
	if (p == 0)
		return (NULL);
	*(p + s) = '\0';
	if (nb == 0)
		*(p + 0) = '0';
	if (nb < 0)
	{
		*(p + 0) = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		*(p + s - 1) = (nb % 10) + 48;
		nb = nb / 10;
		s--;
	}
	return (p);
}
