/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:12:13 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/27 11:18:07 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_in_set(char c, char const *set)
{
	int i;

	i = 0;
	if (!(set))
		return (0);
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static	int	ft_len_cpy(char const *s, char const *set)
{
	int i;
	int cpt;

	i = 0;
	cpt = 0;
	if (!(set))
		return (ft_strlen((char*)s));
	while (ft_in_set(s[i], set) == 1)
	{
		cpt++;
		i++;
	}
	if (!(s[i]))
		return (0);
	while (s[i])
		i++;
	i--;
	while (i >= 0 && ft_in_set(s[i], set) == 1)
	{
		cpt++;
		i--;
	}
	return (ft_strlen((char*)s) - cpt);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;
	int		len_max;

	i = 0;
	j = 0;
	if (!(s1))
		return (NULL);
	len_max = ft_len_cpy(s1, set);
	if (!(str = (char*)malloc(sizeof(char) * (ft_len_cpy(s1, set) + 1))))
		return (NULL);
	while (ft_in_set(s1[i], set))
		i++;
	while (j < len_max)
	{
		str[j] = s1[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
