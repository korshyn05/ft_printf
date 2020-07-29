/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:57:42 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 05:58:38 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		simplification_flags(t_flags *flag)
{
	if (flag->width < 0)
	{
		flag->minus = 1;
		flag->width *= -1;
	}
	if (flag->precsn < 0)
		flag->dot = 0;
	if (flag->minus)
		flag->zero = 0;
}