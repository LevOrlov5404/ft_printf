/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnita <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 19:06:31 by pnita             #+#    #+#             */
/*   Updated: 2019/04/26 22:23:03 by pnita            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	char					*s;
	unsigned long long int	i;
	int						sign;
	int						sz;

	s = (char*)str;
	sign = 1;
	while (*s == '\t' || *s == '\n'
			|| *s == '\v' || *s == '\f' || *s == '\r' || *s == ' ')
		s++;
	if (*s == '-' || *s == '+')
		if (*(s++) == '-')
			sign = -1;
	i = 0;
	sz = 0;
	while (*s >= '0' && *s <= '9')
	{
		i = i * 10 + *(s++) - '0';
		++sz;
		if ((i > 9223372036854775807 || sz > 19) && sign == -1)
			return (0);
		else if ((i > 9223372036854775807 || sz > 19) && sign == 1)
			return (-1);
	}
	return ((int)i * sign);
}