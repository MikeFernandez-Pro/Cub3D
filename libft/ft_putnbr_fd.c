/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 18:11:14 by mifernan          #+#    #+#             */
/*   Updated: 2019/10/26 18:11:19 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char temp;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		ft_putnbr_fd(n * -1, fd);
	}
	else if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	if (n != -2147483648 && n >= 0)
	{
		temp = (n % 10) + '0';
		write(fd, &temp, 1);
	}
}
