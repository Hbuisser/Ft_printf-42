/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:26:39 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/22 18:34:04 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	get_precision(t_struct *db, char **f, va_list *pa, int digit)
{
	int check_minus_one;

	check_minus_one = 0;
	while (!check_convertor(**f))
	{
		if (**f == '*')
		{
			digit = va_arg(*pa, int);
			db->precise_star = digit;
			if (digit == (-1))
				check_minus_one = 1;
		}
		else if (ft_isdigit(**f))
		{
			digit = (digit * 10) + (**f - '0');
			db->precise_dot = digit;
		}
		(*f)++;
	}
	if ((db->precise_dot == (-1)) && (db->precise_star == (-1))
			&& (check_minus_one == 0))
		db->precise_null = 1;
}

void	get_min_width(t_struct *db, char **f, va_list *pa, int digit)
{
	while (**f != '.' && !check_convertor(**f))
	{
		if (ft_isdigit(**f))
		{
			digit = (digit * 10) + (**f - '0');
			db->min_width = digit;
		}
		else if (**f == '*')
		{
			digit = va_arg(*pa, int);
			db->min_width = digit;
		}
		else
			break ;
		(*f)++;
	}
}

void	get_attributes(t_struct *db, char **f)
{
	while (**f == '-' || **f == '0' || **f == ' ')
	{
		if (**f == '-')
			db->minus = 1;
		else if (**f == '0')
			db->zero = 1;
		(*f)++;
	}
}

void	init_struct(t_struct *db)
{
	db->minus = 0;
	db->zero = 0;
	db->min_width = 0;
	db->precise_dot = -1;
	db->precise_star = -1;
	db->precise_null = -1;
	db->convert = 0;
	db->check_minus = 0;
	db->add_minus = "-";
	db->add_ox = "0x";
}
