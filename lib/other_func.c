/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 07:47:38 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/31 01:54:48 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c + 65 - 97);
	return (c);
}
