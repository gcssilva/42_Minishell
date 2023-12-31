/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva <gsilva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:42:19 by gsilva            #+#    #+#             */
/*   Updated: 2023/10/06 16:00:11 by gsilva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str && (unsigned char)*str != (unsigned char)c)
		str++;
	if ((unsigned char)*str != (unsigned char)c)
		return (NULL);
	return ((char *)str);
}
