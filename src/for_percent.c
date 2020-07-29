/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_percent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 07:21:13 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 08:02:23 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*for_percent(t_flags flag)
{
	char	*ptr;

	if (!(ptr = ft_strdup("%")))
		return (NULL);
	if (flag.width && !flag.minus)
		if (!(ptr = if_width(ptr, ' ', flag.width)))
			return (NULL);
	if (flag.minus)
		if (!(ptr = right_width(ptr, ' ', flag.width)))
			return (NULL);
	return (ptr);
}