/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:27:57 by gsilva            #+#    #+#             */
/*   Updated: 2023/10/06 16:01:33 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putnbr_base(unsigned long n, char *base)
{
	int	printed;

	printed = 0;
	if (n / 16 > 0)
		printed += (ft_putnbr_base((n / ft_strlen(base)), base));
	printed += ft_putchar_fd(base[n % 16], 1);
	return (printed);
}
