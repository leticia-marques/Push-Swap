/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 15:51:20 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/12 15:52:13 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

long	ft_atol(const char *str)
{
	signed char		sign;
	unsigned long	num;

	sign = 1;
	num = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	while (ft_isdigit(*str))
		num = (num * 10) + (*(str++) - '0');
	return (num * sign);
}
