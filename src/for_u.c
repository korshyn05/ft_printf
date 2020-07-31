/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 13:03:34 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/31 15:29:21 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*for_u(t_flags flag, t_parameters *prmtrs)
{
	char			*ptr;
	unsigned int	p;

	p = va_arg(prmtrs->ap, unsigned int);
	ptr = itoa_for_u(p);
	if (flag.dot)
	{
		if (!(ptr = precision_u(flag, ptr)))
			return (NULL);
		if (flag.minus)
			return (if_width(ptr, ' ', flag.width));
	}
	else
	{
		if (flag.zero)
			if (!(ptr = if_width(ptr, '0', flag.width)))
				return (NULL);
		if (flag.minus)
			return (right_width(ptr, ' ', flag.width));
		if (flag.width)
			if (!(ptr = if_width(ptr, ' ', flag.width)))
				return (NULL);
	}
	return (ptr);
}

char	*itoa_for_u(unsigned long long number)
{
	int		length;
	char	str[11];
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = -1;
	if (number == 0)
		return (ft_strdup("0"));
	while (number != 0)
	{
		str[i++] = (char)(number % 10 + 48);
		number /= 10;
	}
	str[i] = '\0';
	length = ft_strlen(str);
	if (!(string = (char *)malloc((length + 1) * sizeof(char))))
		return (NULL);
	while (++j < length)
		string[j] = str[length - j - 1];
	string[j] = '\0';
	return (string);
}

char	*precision_u(t_flags flag, char *ptr)
{
	if (flag.precsn == 0 && ptr[0] == '0')
		ptr[0] = '\0';
	else
	{
		if (!(ptr = if_width(ptr, '0', flag.precsn)))
			return (NULL);
	}
	if (!(ptr = if_width(ptr, '0', flag.precsn)))
		return (NULL);
	if (flag.width)
		if (!(ptr = if_width(ptr, ' ', flag.width)))
			return (NULL);
	if (flag.minus)
		if (!(ptr = align_left(ptr)))
			return (NULL);
	return (ptr);
}
