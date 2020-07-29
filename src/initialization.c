/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:36:58 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 15:46:32 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_params(t_parameters *param, const char *frmt)
{
	param->count = 0;
	param->length = 0;
	param->format = frmt;
}

void		init_flag(t_flags *flag)
{
	flag->dot = 0;
	flag->minus = 0;
	flag->width = 0;
	flag->zero = 0;
	flag->precsn = 0;
}

void	init_parameter(t_parameters *prmtrs)
{
	prmtrs->forward_zero = 0;
	prmtrs->backward_zero = 0;
}

int			set_flag(t_flags *flag, char ch, t_parameters *prmtrs)
{
	if (ch == '.')
		flag->dot = 1;
	if (ch == '0')
		flag->zero = 1;
	if (ch == '-')
		flag->minus = 1;
	if (ch >= '1' && ch <= '9')
	{
		if (flag->dot)
			flag->precsn = ft_atoi(&(prmtrs->format[prmtrs->count]), prmtrs);
		else
			flag->width = ft_atoi(&(prmtrs->format[prmtrs->count]), prmtrs);
	}
	if (ch == '*')
	{
		if (flag->dot)
			flag->precsn = (int)va_arg(prmtrs->ap, int);
		else
			flag->width = (int)va_arg(prmtrs->ap, int);
	}
	return (0);
}