/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemarque <lemarque@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/27 08:53:10 by lemarque          #+#    #+#             */
/*   Updated: 2022/02/10 19:07:56 by lemarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen(str);
	while (len >= 0 && str[len] != (unsigned char)c)
		len--;
	if (!(len < 0))
		return ((char *)str + len);
	return (NULL);
}
