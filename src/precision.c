/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 07:15:59 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/31 15:27:34 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*for_precision(char *s, int count)
{
	char *str;

	if (!(str = malloc((count + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(str, s, count + 1);
	free(s);
	return (str);
}

char		*sign_func(char *string, int sign)
{
	char *str;

	if (sign == -1)
	{
		if (!(str = ft_strjoin("-", string)))
			return (NULL);
		free(string);
		return (str);
	}
	return (string);
}

char		*find_precision(char *string, int counter)
{
	char *str;

	if (!(str = malloc((counter + 1) * sizeof(char))))
		return (NULL);
	ft_strlcpy(str, string, counter + 1);
	free(string);
	return (str);
}

char		*precision_for_integer(char *ptr, t_flags flag, int sign)
{
	if (flag.precsn == 0 && ptr[0] == '0')
		ptr[0] = '\0';
	else
	{
		if (!(ptr = if_width(ptr, '0', flag.precsn)))
			return (NULL);
	}
	if (!(ptr = sign_func(ptr, sign)))
		return (NULL);
	if (flag.width)
		if (!(ptr = if_width(ptr, ' ', flag.width)))
			return (NULL);
	if (flag.minus)
		if (!(ptr = align_left(ptr)))
			return (NULL);
	return (ptr);
}

char		*without_precision(char *ptr, t_flags flag, int sign)
{
	char	ch;
	int		i;

	i = 0;
	if (flag.minus)
	{
		if (!(ptr = sign_func(ptr, sign)))
			return (NULL);
		return (right_width(ptr, ' ', flag.width));
	}
	ch = (flag.zero) ? '0' : ' ';
	if (!(ptr = sign_func(ptr, sign)))
		return (NULL);
	if (!(ptr = if_width(ptr, ch, flag.width)))
		return (NULL);
	while (ptr[i] != '\0' && ptr[i] != '-' && ptr[i] != '+')
		i++;
	if (i && ptr[0] == '0' && ptr[i] != '\0')
	{
		ptr[0] = ptr[i];
		ptr[i] = '0';
	}
	return (ptr);
}
