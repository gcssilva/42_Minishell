/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 12:04:55 by gsilva            #+#    #+#             */
/*   Updated: 2023/10/06 16:01:36 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_fd(int nbr, int fd)
{
	long int	n;
	int			i;

	i = 0;
	n = nbr;
	if (n < 0)
	{
		i += ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n / 10 > 0)
		i += ft_putnbr_fd((n / 10), fd);
	i += ft_putchar_fd((n % 10) + 48, fd);
	return (i);
}
