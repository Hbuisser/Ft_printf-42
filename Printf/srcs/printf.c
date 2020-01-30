/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 15:31:12 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 16:59:57 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		print_without_convertion(char c)
{
	write(1, &c, 1);
	return (1);
}

int		print_convertion(t_struct *db, va_list *pa)
{
	if (db->convert == 'c')
		return (convert_c(db, pa));
	else if (db->convert == 's')
		return (convert_s(db, pa));
	else if (db->convert == 'd')
		return (convert_d(db, pa));
	else if (db->convert == 'i')
		return (convert_d(db, pa));
	else if (db->convert == 'x')
		return (convert_x(db, pa));
	else if (db->convert == 'X')
		return (convert_big_x(db, pa));
	else if (db->convert == 'p')
		return (convert_p(db, pa));
	else if (db->convert == '%')
		return (convert_percent(db));
	else if (db->convert == 'u')
		return (convert_u(db, pa));
	else if (!(check_convertor(db->convert)))
		return (-1);
	else
		return (0);
}

int		parse_percentage(t_struct *db, va_list *pa, char *f)
{
	int		digit;
	char	*begin;

	digit = 0;
	begin = NULL;
	begin = f;
	init_struct(db);
	get_attributes(db, &f);
	get_min_width(db, &f, pa, digit);
	if (*f == '.')
		get_precision(db, &f, pa, digit);
	db->convert = *f++;
	return (f - begin);
}

int		parse_format(char *f, va_list *pa)
{
	int			i;
	int			j;
	int			count;
	int			count_parse;
	t_struct	db;

	i = 0;
	j = 0;
	count = 0;
	while (f[i] != '\0')
	{
		if (f[i] == '%')
		{
			count_parse = parse_percentage(&db, pa, f + i + 1);
			if ((j = print_convertion(&db, pa)) == (-1))
				return (-1);
			count = count + j;
			i = i + count_parse;
		}
		else
			count = count + print_without_convertion(f[i]);
		i++;
	}
	return (count);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	pa;
	int		count;
	char	*f;

	f = (char *)fmt;
	if (!check_fmt(f))
		return (0);
	va_start(pa, fmt);
	if ((count = parse_format(f, &pa)) == (-1))
		return (-1);
	va_end(pa);
	return (count);
}
