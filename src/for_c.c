/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:03:47 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 14:37:31 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*for_c(t_flags flag, t_parameters *prmtrs)
{
	int		ch;
	char	*ptr;

	ch = va_arg(prmtrs->ap, int);
	if (!(ptr = malloc_char(ch)))
		return (NULL);
	if (flag.width)
		if (!(ptr = if_width(ptr, ' ', flag.width + ft_strlen(ptr) - 1)))
			return (NULL);
	if (flag.minus)
		if (!(ptr = align_left(ptr)))
			return (NULL);
	if (ch == 0)
	{
		if (flag.minus)
			prmtrs->forward_zero = 1;
		else
			prmtrs->backward_zero = 1;
	}
	return (ptr);
}

char		*malloc_char(int c)
{
	char	*s;

	if (!(s = (char *)malloc(2)))
		return (NULL);
	s[0] = (char)c;
	s[1] = '\0';
	return (s);
}
