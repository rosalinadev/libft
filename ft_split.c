/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvandepu <rvandepu@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:23:14 by rvandepu          #+#    #+#             */
/*   Updated: 2023/10/20 14:45:41 by rvandepu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_count_str(char const *str, char const charset)
{
	int	i;
	int	n;
	int	c;

	i = -1;
	n = 0;
	c = 1;
	while (str[++i] != '\0')
	{
		if (c && !(str[i] == charset || !str[i]))
		{
			n++;
			c = 0;
		}
		else if (str[i] == charset || !str[i])
			c = 1;
	}
	return (n);
}

static void	*ft_free_tab(void **tab, char const *s, char const c)
{
	int	n;

	n = ft_count_str(s, c);
	while (n--)
		if (tab[n])
			free(tab[n]);
	free(tab);
	return (NULL);
}

static char	**ft_malloc_tab(unsigned long *tab, char const *str, char const s)
{
	int	i;
	int	n;
	int	c;

	i = -1;
	n = 0;
	c = 1;
	while (i++ == -1 || str[i - 1] != '\0')
	{
		if (c && !(str[i] == s || !str[i]))
		{
			tab[n] = 2;
			c = 0;
		}
		else if (!(str[i] == s || !str[i]))
			tab[n]++;
		else if (!c && (str[i] == s || !str[i]) && ++c)
		{
			tab[n] = (unsigned long) malloc(tab[n]);
			if ((void *) tab[n++] == NULL)
				return ((char **) ft_free_tab((void **)tab, str, s));
		}
	}
	tab[n] = 0;
	return ((char **) tab);
}

static void	ft_strcpy_bis(char *dest, char const *src, char const charset)
{
	int	i;

	i = 0;
	while (!(src[i] == charset || !src[i]))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		n;
	int		d;
	char	**tab;

	tab = ft_calloc(ft_count_str(s, c) + (d = 1), sizeof (char *));
	if (tab == NULL)
		return (tab);
	tab = ft_malloc_tab((unsigned long *) tab, s, c + (n = 0) + ((i = -1) + 1));
	if (tab == NULL)
		return (tab);
	while (s[++i] != '\0')
	{
		if (d && !(s[i] == c || !s[i]))
		{
			ft_strcpy_bis(tab[n], s + i, c);
			d = 0;
		}
		else if (!d && (s[i] == c || !s[i]))
		{
			n++;
			d = 1;
		}
	}
	return (tab);
}
