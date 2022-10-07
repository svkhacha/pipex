/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svkhacha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 17:53:02 by svkhacha          #+#    #+#             */
/*   Updated: 2022/07/25 14:16:30 by svkhacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**check_malloc(char **tab)
{
	if (!tab)
		return (NULL);
	return (tab);
}

static char	**free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	wordcount(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0' && str[i] == c)
		i++;
	if (str[i++] != '\0')
		count = 1;
	while (str[i])
	{
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	return (count);
}

static int	wordlen(char *str, char c, int index)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = 0;
	while (str[i] == c)
		i++;
	if (str[i++] != '\0')
		count = 1;
	while (str[i])
	{
		while (index == count - 1 && str[i - 1] && str[i - 1] != c)
		{
			len++;
			i++;
		}
		if (str[i] != c && str[i - 1] == c)
			count++;
		i++;
	}
	return (len);
}

char	**ft_split(char *str, char c)
{
	int		i;
	int		j;
	int		wc;
	char	**tab;

	if (!str)
		return (NULL);
	i = -1;
	wc = wordcount(str, c);
	tab = (char **)malloc(sizeof(char *) * (wc + 1));
	check_malloc(tab);
	while (++i < wc)
	{
		tab[i] = (char *)malloc(sizeof(char) * (wordlen(str, c, i) + 1));
		if (!tab[i])
			return (free_tab(tab));
		while (*str == c)
			str++;
		j = 0;
		while (*str != c && *str)
			tab[i][j++] = *str++;
		tab[i][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
