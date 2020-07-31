/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 07:33:41 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/31 15:31:07 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*small_x(t_flags flag, t_parameters *prmtrs)
{
	char			*ptr;
	unsigned int	p;

	p = va_arg(prmtrs->ap, unsigned int);
	if (!(ptr = itoa_for_x(p)))
		return (NULL);
	if (flag.dot)
		if (!(ptr = precision_for_x(flag, ptr)))
			return (NULL);
	if (!flag.dot)
		if (!(ptr = x_without_precision(flag, ptr)))
			return (NULL);
	return (ptr);
}

char		*precision_for_x(t_flags flag, char *ptr)
{
	if (flag.precsn == 0 && ptr[0] == '0')
		ptr[0] = '\0';
	else
	{
		if (!(ptr = if_width(ptr, '0', flag.precsn)))
			return (NULL);
	}
	if (flag.width)
		if (!(ptr = if_width(ptr, ' ', flag.width)))
			return (NULL);
	if (flag.minus)
		if (!(ptr = align_left(ptr)))
			return (NULL);
	return (ptr);
}

char		*x_without_precision(t_flags flag, char *ptr)
{
	if (flag.minus)
		return (right_width(ptr, ' ', flag.width));
	if (!flag.zero)
		if (!(ptr = if_width(ptr, ' ', flag.width)))
			return (NULL);
	if (flag.zero)
		if (!(ptr = if_width(ptr, '0', flag.width)))
			return (NULL);
	return (ptr);
}

char		*itoa_for_x(unsigned long long number)
{
	char	str[20];
	size_t	i;
	char	*x;
	size_t	j;
	char	*string;

	x = "0123456789abcdef";
	i = 0;
	j = -1;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		str[i] = x[number % 16];
		number = number / 16;
		i++;
	}
	str[i] = '\0';
	if (!(string = (char *)malloc((ft_strlen(str) + 1) * sizeof(char))))
		return (NULL);
	while (++j < ft_strlen(str))
		string[j] = str[ft_strlen(str) - j - 1];
	string[j] = '\0';
	return (string);
}

char		*big_x(char *string)
{
	int i;

	i = 0;
	while (string[i] != '\0')
	{
		string[i] = (char)ft_toupper(string[i]);
		i++;
	}
	return (string);
}
