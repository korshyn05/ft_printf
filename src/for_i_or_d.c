/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_i_or_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 07:54:00 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 13:37:12 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*for_i_or_d(t_flags flag, t_parameters *prmtrs)
{
	char	*ptr;
	long	p;
	int		sign;

	sign = 1;
	p = (long)va_arg(prmtrs->ap, int);
	if (p < 0)
	{
		sign = -1;
		p = -p; //fix
	}
	ptr = ft_itoa(p);
	if (flag.dot)
		if (!(ptr = precision_for_integer(ptr, flag, sign)))
			return (NULL);
	if (!flag.dot)
		if (!(ptr = without_precision(ptr, flag, sign)))
			return (NULL);
	return (ptr);
}

/*static char		*negative(char *string)
{
	int		length;
	int		i;
	char	*line;

	length = ft_strlen(string);
	i = -1;
	if (!(line = malloc((length + 1) * sizeof(char))))
		return (NULL);
	while (++i < length)
		line[i] = string[length - i - 1];
	line[i] = '\0';
	return (line);
}

char			*ft_itoa(long number)
{
	char	str[11];
	int		znak;
	int		i;

	znak = (number < 0) ? -1 : 1;
	i = 0;
	if (number == 0)
		return (ft_strdup("0"));
	if (number == -2147483648)
		return (ft_strdup("-2147483648"));
	number = (number < 0) ? (number * znak) : number;
	while (number)
	{
		str[i++] = (char)(number % 10 + 48);
		number /= 10;
	}
	if (znak == -1)
		str[i++] = '-';
	str[i] = '\0';
	return (negative(str));
}*/

unsigned int	int_length(long n)
{
	unsigned int	i;

	i = 0;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char				*ft_itoa(int n)
{
	char				*str;
	unsigned int		i;
	unsigned int		size;
	long int			new_n;

	size = int_length(n);
	if (!(str = (char *)malloc(sizeof(char) * (size + 1 + (n < 0 ? 1 : 0)))))
		return (NULL);
	new_n = n;
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		size++;
		new_n *= -1;
	}
	i = size - 1;
	while (new_n >= 10)
	{
		str[i--] = (char)(new_n % 10 + '0');
		new_n /= 10;
	}
	str[i] = (char)(new_n % 10 + '0');
	str[size] = '\0';
	return (str);
}

