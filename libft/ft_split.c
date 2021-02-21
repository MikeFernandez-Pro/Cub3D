/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:11:40 by mifernan          #+#    #+#             */
/*   Updated: 2019/12/06 12:08:34 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_w(char const *s, char sep, int i)
{
	int cpt;

	cpt = 0;
	while (s && s[i] != sep && s[i])
	{
		cpt++;
		i++;
	}
	return (cpt);
}

static int	ft_nb_words(char const *s, char sep)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	while (s && s[i])
	{
		if ((i == 0 && s[i] != sep) ||
		(i > 0 && s[i - 1] == sep && s[i] != sep))
		{
			while (s[i] != sep && s[i])
				i++;
			cpt++;
		}
		else
			i++;
	}
	return (cpt);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	int		word;
	int		letter;
	char	**new;

	i = 0;
	word = 0;
	if (!(new = (char**)malloc(sizeof(char*) * (ft_nb_words(s, c) + 1))))
		return (NULL);
	while (s && s[i] && ft_nb_words(s, c) > 0)
	{
		letter = 0;
		while (s[i] == c && s[i])
			i++;
		if (!(new[word] = (char*)malloc(sizeof(char) * (len_w(s, c, i) + 1))))
			return (NULL);
		while (s[i] != c && s[i])
			new[word][letter++] = s[i++];
		new[word][letter] = '\0';
		while (i < (size_t)ft_strlen(s) && s[i] == c)
			i++;
		word++;
	}
	new[word] = NULL;
	return (new);
}
