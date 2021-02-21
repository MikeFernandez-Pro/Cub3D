/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:11:51 by mifernan          #+#    #+#             */
/*   Updated: 2019/11/22 13:04:17 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_join(char *s1, char *s2, int mod)
{
	if (mod == 1)
		ft_strdel(&s1);
	else if (mod == 2)
		ft_strdel(&s2);
	else if (mod == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
}

char	*ft_strjoin_free(char *s1, char *s2, int mod)
{
	char	*str;
	int		total;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	total = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char*)malloc(sizeof(char) * (total + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	ft_free_join(s1, s2, mod);
	return (str);
}
