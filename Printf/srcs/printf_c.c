/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:55:25 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 14:18:15 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	convert_c(t_struct *db, va_list *pa)
{
	unsigned char	c;
	char			*ret;

	ret = NULL;
	c = va_arg(*pa, int);
	if (!db->min_width)
		db->min_width = 1;
	if (db->min_width < 0)
	{
		db->min_width = (db->min_width * -1);
		db->minus = 1;
		db->zero = 0;
	}
	if (!(ret = ft_malloc(db->min_width)))
		return (-1);
	if (db->minus)
		ret[0] = c;
	else
		ret[db->min_width - 1] = c;
	write(1, ret, db->min_width);
	ft_free_str(&ret, 1);
	return (db->min_width);
}
