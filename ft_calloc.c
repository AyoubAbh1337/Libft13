/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblmouh <ayblmouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 15:02:21 by ayblmouh          #+#    #+#             */
/*   Updated: 2026/11/07 15:02:24 by ayblmouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	res;

	if (nmemb != 0 && size > (size_t) - 1 / nmemb)
		return (NULL);
	res = nmemb * size;
	if (res == 0)
		res = 1;
	ptr = malloc(res);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, res);
	return (ptr);
}
