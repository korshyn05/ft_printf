/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aligned.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 06:09:53 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/31 01:58:21 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*if_width(char *string, char ch, size_t counter)
{
	char	*str;
	size_t	i;

	i = 0;
	if (ft_strlen(string) >= counter)
		return (string);
	if (!(str = malloc((counter + 1) * sizeof(char))))
		return (NULL);
	while (i++ < counter)
		str[i - 1] = ch;
	str[counter] = '\0';
	i = ft_strlen(string);
	while (i-- > 0)
		str[--counter] = string[i];
	free(string);
	return (str);
}

char	*align_left(char *ptr)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (ptr[i] != '\0' && ptr[i] == ' ')
		i++;
	if (ptr[i] == '\0' || !i)
		return (ptr);
	while (ptr[i] != '\0')
		ptr[counter++] = ptr[i++];
	while ((ptr[counter]) != '\0')
		ptr[counter++] = ' ';
	return (ptr);
}

char	*right_width(char *string, char ch, size_t counter)
{
	char	*str;
	size_t	i;

	i = 0;
	if (ft_strlen(string) >= counter)
		return (string);
	if (!(str = malloc((counter + 1) * sizeof(char))))
		return (NULL);
	while (i++ < counter)
		str[i - 1] = ch;
	str[counter] = '\0';
	i = ft_strlen(string);
	while (i-- > 0)
		str[i] = string[i];
	free(string);
	return (str);
}
