/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblmouh <ayblmouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 09:39:16 by ayblmouh          #+#    #+#             */
/*   Updated: 2026/11/08 14:06:47 by ayblmouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = len;
	while (end > start && ft_strchr(set, s1[end - 1]))
		end--;
	ptr = malloc(end - start + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s1 + start, end - start);
	ptr[end - start] = '\0';
	return (ptr);
}
