/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:01:53 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 07:53:09 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	write_if_null(char *str, t_parameters *prmtrs)
{
	char zero;

	zero = '\0';
	if (prmtrs->forward_zero)
	{
		write(1, &zero, 1);
		prmtrs->length++;
	}
	if (str)
	{
		while (*str)
		{
			write(1, str, 1);
			str++;
		}
	}
	if (prmtrs->backward_zero)
	{
		write(1, &zero, 1);
		prmtrs->length++;
	}
}
