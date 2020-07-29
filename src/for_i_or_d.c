/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_i_or_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 07:54:00 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 16:49:20 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*for_i_or_d(t_flags flag, t_parameters *prmtrs)
{
	char	*ptr;
	long	p;
	int		sign;

	sign = 1;
	p = (long)va_arg(prmtrs->ap, int);
	if (p < 0)
	{
		sign = -1;
		p = -p; //fix
	}
	ptr = ft_itoa(p);
	if (flag.dot)
		if (!(ptr = precision_for_integer(ptr, flag, sign)))
			return (NULL);
	if (!flag.dot)
		if (!(ptr = without_precision(ptr, flag, sign)))
			return (NULL);
	return (ptr);
}