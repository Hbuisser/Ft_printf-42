/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:56:56 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 10:03:53 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct	s_struct
{
	int			minus;
	int			zero;
	long int	min_width;
	int			precise_dot;
	int			precise_star;
	int			precise_null;
	int			convert;
	int			check_minus;
	char		*add_minus;
	char		*add_ox;
}				t_struct;

int				ft_printf(const char *fmt, ...);
int				parse_format(char *f, va_list *pa);
int				parse_percentage(t_struct *db, va_list *pa, char *f);
int				print_convertion(t_struct *db, va_list *pa);
int				print_without_convertion(char c);

void			get_min_width(t_struct *db, char **f, va_list *pa, int digit);
void			get_precision(t_struct *db, char **f, va_list *pa, int digit);
void			get_attributes(t_struct *db, char **f);
void			init_struct(t_struct *db);

int				convert_c(t_struct *db, va_list *pa);
int				convert_s(t_struct *db, va_list *pa);
int				convert_d(t_struct *db, va_list *pa);
int				convert_x(t_struct *db, va_list *pa);
int				convert_big_x(t_struct *db, va_list *pa);
char			*convert_both_x(t_struct *db, va_list *pa, int base);
int				convert_p(t_struct *db, va_list *pa);
int				convert_percent(t_struct *db);
int				convert_u(t_struct *db, va_list *pa);
int				convert_d2(int len, t_struct *db, char *new);
int				convert_p2(int len, t_struct *db, char *new);
int				convert_u2(int len, t_struct *db, char *new);
char			*convert_both_x_2(int len, t_struct *db, char *new);

char			*ft_malloc(int size);
int				ft_free_str(char **str, int result);
char			*ft_free_str_string(char **str, char *result);
int				check_convertor(char c);
int				check_fmt(char *f);
char			*manage_precision(t_struct *db, char *new, int len);
void			manage_min_width(t_struct *db, int len);
char			*convert_with_minus(int len, char *ret, char *new,
					t_struct *db);
char			*convert_without_minus(int len, char *ret, char *new,
					t_struct *db);
char			*cut_minus(char *str, t_struct *db, char *new);
char			*add_minus(char *str, int len, t_struct *db);
int				manage_len(t_struct *db, int len, char *new);

#endif
