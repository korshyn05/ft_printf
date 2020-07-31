/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tludwig <tludwig@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 02:32:28 by tludwig           #+#    #+#             */
/*   Updated: 2020/07/31 15:34:28 by tludwig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			precsn;
	int			star;
}				t_flags;

typedef struct	s_parameters
{
	va_list		ap;
	const char	*format;
	size_t		count;
	char		line;
	int			forward_zero;
	int			backward_zero;
	size_t		length;
}				t_parameters;

int				ft_printf(const char *frmt, ...);
void			ft_putchar(char c);
void			init_params(t_parameters *param, const char *frmt);
int				check_string(t_parameters prmtrs);
int				check_params(t_parameters *prmtrs);
void			init_flag(t_flags *flag);
void			init_parameter(t_parameters *prmtrs);
int				set_flag(t_flags *flag, char fl, t_parameters *prmtrs);
void			simplification_flags(t_flags *flag);
size_t			length_atoi(int n);
int				ft_atoi(const char *str, t_parameters *param);
char			*which_flag(t_flags flag, t_parameters *prmtrs);
char			*for_c(t_flags flag, t_parameters *prmtrs);
char			*malloc_char(int c);
char			*if_width(char *string, char ch, size_t counter);
int				is_type(int type);
int				is_flag_or_digit(int c);
void			write_if_null(char *str, t_parameters *prmtrs);
char			*align_left(char *ptr);
size_t			ft_strlen(const char *str);
int				ft_isdigit(int c);
char			*for_s(t_flags flag, t_parameters *prmtrs);
char			*for_precision(char *s, int count);
char			*ft_strdup(const char *src);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
char			*for_percent(t_flags flag);
char			*right_width(char *string, char ch, size_t counter);
char			*for_i_or_d(t_flags flag, t_parameters *prmtrs);
char			*ft_itoa(long n);
char			*precision_for_integer(char *ptr, t_flags flag, int sign);
char			*without_precision(char *ptr, t_flags flag, int sign);
char			*for_p(t_flags flag, t_parameters *prmtrs);
char			*ft_strjoin(char const *s1, char const *s2);
char			*small_x(t_flags flag, t_parameters *prmtrs);
char			*itoa_for_x(unsigned long long number);
char			*big_x(char *string);
char			*for_u(t_flags flag, t_parameters *prmtrs);
char			*precision_for_x(t_flags flag, char *ptr);
char			*x_without_precision(t_flags flag, char *ptr);
int				ft_toupper(int c);
char			*itoa_for_u(unsigned long long number);
char			*precision_u(t_flags flag, char *ptr);
char			*add_0x(char *string);
char			*precision_for_p(t_flags flag, char *ptr);
char			*p_without_precision(t_flags flag, char *ptr);

#endif
