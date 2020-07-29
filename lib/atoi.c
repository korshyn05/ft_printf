/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 05:29:42 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/29 16:48:23 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t		length_atoi(int n)
{
	size_t	i;

	if (n > 0)
		i = 0;
	else
		i = 1;
	while (1)
	{
		i++;
		n /= 10;
		if (!n)
			break ;
	}
	return (i);
}

int		ft_atoi(const char *str, t_parameters *param)
{
	int				i;
	int				znak;
	unsigned long	iota;

	i = 0;
	znak = 1;
	iota = 0;
	if (str[0] == '\0')
		return (0);
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			znak = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		iota = iota * 10 + str[i++] - '0';
	param->count += length_atoi((int)iota * znak) - 1;
	return ((int)iota * znak);
}

static char		*negative(char *string)
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

char			*ft_itoa(long n)
{
	char	str[11];
	int		znak;
	int		i;

	znak = (n < 0) ? -1 : 1;
	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n = (n < 0) ? (n * znak) : n;
	while (n)
	{
		str[i++] = (char)(n % 10 + 48);
		n /= 10;
	}
	if (znak == -1)
		str[i++] = '-';
	str[i] = '\0';
	return (negative(str));
}
