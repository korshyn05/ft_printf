/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:10:53 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 13:40:49 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


char			*for_p(t_flags flag, t_parameters *prmtrs)
{
	char	*ptr;
	void	*p;

	p = va_arg(prmtrs->ap, void *);
	if (p)
	{
		if (!(ptr = itoa_for_x((unsigned long long)p)))
			return (NULL);
	}
	else
	{
		if (!(ptr = ft_strdup("0")))
			return (NULL);
	}
	if (flag.dot)
		if (!(ptr = precision_for_p(flag, ptr)))
			return (NULL);
	if (!flag.dot)
		if (!(ptr = p_without_precision(flag, ptr)))
			return (NULL);
	return (ptr);
}

char		*add_0x(char *string)
{
	char *str;

	if (!(str = ft_strjoin("0x", string)))
		return (NULL);
	free(string);
	return (str);
}

char		*precision_for_p(t_flags flag, char *ptr)
{
	if (!(ptr = if_width(ptr, '0', flag.precsn)))
		return (NULL);
	if (!(ptr = add_0x(ptr)))
		return (NULL);
	if (flag.width)
		if (!(ptr = if_width(ptr, ' ', flag.width)))
			return (NULL);
	if (flag.minus)
		if (!(ptr = align_left(ptr)))
			return (NULL);
	return (ptr);
}

char		*p_without_precision(t_flags flag, char *ptr)
{
	if (flag.minus)
	{
		if (!(ptr = add_0x(ptr)))
			return (NULL);
		return (right_width(ptr, ' ', flag.width));
	}
	if (!flag.zero)
	{
		if (!(ptr = add_0x(ptr)))
			return (NULL);
		if (!(ptr = if_width(ptr, ' ', flag.width)))
			return (NULL);
	}
	if (flag.zero)
	{
		if (!(ptr = right_width(ptr, '0', flag.width - 2)))
			return (NULL);
		if (!(ptr = add_0x(ptr)))
			return (NULL);
	}
	return (ptr);
}