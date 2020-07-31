/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 02:32:45 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/31 01:55:10 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int		ft_printf(const char *frmt, ...)
{
	t_parameters	param;

	init_params(&param, frmt);
	va_start(param.ap, frmt);
	while (param.format[param.count] != '\0')
	{
		if (param.format[param.count] == '%')
		{
			if (check_params(&param))
			{
				ft_putchar(param.format[param.count]);
				param.length++;
			}
		}
		else
		{
			ft_putchar(param.format[param.count]);
			param.length++;
		}
		(param.count)++;
	}
	va_end(param.ap);
	return (param.length);
}
