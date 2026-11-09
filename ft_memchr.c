/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblmouh <ayblmouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 10:12:17 by ayblmouh          #+#    #+#             */
/*   Updated: 2026/11/08 13:58:55 by ayblmouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*p = s;

	i = 0;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if (p[i] == (unsigned char) c)
			return ((void *)(p + i));
		i++;
	}
	return (NULL);
}
