/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayblmouh <ayblmouh@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 18:29:55 by ayblmouh          #+#    #+#             */
/*   Updated: 2026/11/09 18:30:04 by ayblmouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	wordcount(const char *word, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (word[i] != '\0')
	{
		while (word[i] && word[i] == sep)
			i++;
		if (word[i] && word[i] != sep)
			count++;
		while (word[i] && word[i] != sep)
			i++;
	}
	return (count);
}

static int	countchar(const char *word, int i, char sep)
{
	int	counter;

	counter = 0;
	while (word[i] && word[i] != sep)
	{
		counter++;
		i++;
	}
	return (counter);
}

static char	**free_tab(char **tab, int j)
{
	while (j > 0)
		free(tab[--j]);
	free(tab);
	return (NULL);
}

static char	**fill_tab(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = countchar(s, i, c);
			tab[j] = ft_substr(s, i, len);
			if (!tab[j])
				return (free_tab(tab, j));
			i += len;
			j++;
		}
	}
	tab[j] = NULL;
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((wordcount(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	return (fill_tab(tab, s, c));
}
