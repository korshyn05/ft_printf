/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:20:31 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/31 01:56:09 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*for_s(t_flags flag, t_parameters *prmtrs)
{
	char	*ptr;

	if (!(ptr = va_arg(prmtrs->ap, char *)))
	{
		if (!(ptr = ft_strdup("(null)")))
			return (NULL);
	}
	else
	{
		if (!(ptr = ft_strdup(ptr)))
			return (NULL);
	}
	if (flag.dot)
		if (!(ptr = for_precision(ptr, flag.precsn)))
			return (NULL);
	if (flag.width)
		if (!(ptr = if_width(ptr, ' ', flag.width)))
			return (NULL);
	if (flag.minus)
		ptr = align_left(ptr);
	return (ptr);
}
