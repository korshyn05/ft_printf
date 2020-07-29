/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:35:54 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 19:17:02 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		check_params(t_parameters *prmtrs)
{
	t_flags	flag;
	char	*str;

	init_flag(&flag);
	init_parameter(prmtrs);
	if (check_string(*prmtrs))
		return (1);
	while (prmtrs->format[++(prmtrs->count)] != '\0' &&  //| TODO: Не забыть
		is_flag_or_digit(prmtrs->format[prmtrs->count]))
		set_flag(&flag, prmtrs->format[prmtrs->count], prmtrs);
	simplification_flags(&flag);
	if (!(str = which_flag(flag, prmtrs)))
		return (1);
	else
	{
		write_if_null(str, prmtrs);
		prmtrs->length += ft_strlen(str);
		free(str);
	}
	return (0);
}

int		check_string(t_parameters prmtrs)
{
	size_t	local_count;
	size_t	i;

	local_count = prmtrs.count;
	i = 0;
	while (prmtrs.format[++local_count] != '\0'
	&& (!(is_type(prmtrs.format[local_count]))))
	{
		if (i && prmtrs.format[local_count] == '.')
			return (1);
		if (prmtrs.format[local_count] == '.')
			i = 1;
		if (!(is_flag_or_digit(prmtrs.format[local_count])))
			return (1);
	}
	if (prmtrs.format[local_count] == '\0')
		return (1);
	return (0);
}

int		is_type(int type)
{
	if ((type == 'c') || (type == 's') || (type == 'p') || (type == 'd') ||
	(type == 'i') || (type == 'u') || (type == 'x') || (type == 'X') ||
	(type == '%'))
		return (1);
	return (0);
}

int			is_flag_or_digit(int c)
{
	if ((c == '.') || (c == '-') || (c == '*') || (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*which_flag(t_flags flag, t_parameters *prmtrs)
{
	char *ptr;

	prmtrs->line = prmtrs->format[prmtrs->count];
	if (prmtrs->format[prmtrs->count] == 'd' ||
	prmtrs->format[prmtrs->count] == 'i')
		return (for_i_or_d(flag, prmtrs));
	if (prmtrs->format[prmtrs->count] == 'c')
		return (for_c(flag, prmtrs));
	if (prmtrs->format[prmtrs->count] == 's')
		return (for_s(flag, prmtrs));
	if (prmtrs->format[prmtrs->count] == 'x')
		return (small_x(flag, prmtrs));
	if (prmtrs->format[prmtrs->count] == 'X')
	{
		if (!(ptr = small_x(flag, prmtrs)))
			return (NULL);
		return (big_x(ptr));
	}
	if (prmtrs->format[prmtrs->count] == 'u')
		return (for_u(flag, prmtrs));
	if (prmtrs->format[prmtrs->count] == 'p')
		return (for_p(flag, prmtrs));
	if (prmtrs->format[prmtrs->count] == '%')
		return (for_percent(flag));
	return (NULL);
}