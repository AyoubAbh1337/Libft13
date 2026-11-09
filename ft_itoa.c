/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+      */
/*   By: ayblmouh <ayblmouh@student.1337.ma>       #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/26 17:22:24 by ayblmouh         #+#    #+#              */
/*   Updated: 2026/11/08 14:08:58 by ayblmouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(long n)
{
	int	p;

	p = 0;
	if (n < 0)
		p = 1;
	return (p);
}

static int	nbr_len(long n)
{
	int	counter;

	counter = 0;
	if (n < 0)
	{
		counter++;
		n = -n;
	}
	while (n > 0)
	{
		counter++;
		n /= 10;
	}
	if (counter == 0)
		return (1);
	return (counter);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*ptr;
	int		len;
	int		p;

	nb = n;
	len = nbr_len(nb);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	p = check_sign(nb);
	if (p == 1)
		nb = -nb;
	ptr[len] = '\0';
	while (len > p)
	{
		ptr[--len] = (nb % 10) + 48;
		nb = nb / 10;
	}
	if (p == 1)
		ptr[0] = '-';
	return (ptr);
}
