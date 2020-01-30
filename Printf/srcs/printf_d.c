/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 12:39:54 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 16:31:10 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		convert_d2(int len, t_struct *db, char *new)
{
	char	*ret;
	char	*tmp;

	len = manage_len(db, len, new);
	manage_min_width(db, len);
	if (!(ret = ft_malloc(db->min_width)))
		return (-1);
	if (db->minus)
		ret = convert_with_minus(len, ret, new, db);
	else
		ret = convert_without_minus(len, ret, new, db);
	if (db->check_minus)
	{
		tmp = ret;
		if (!(ret = add_minus(ret, len, db)))
			return (-1);
		ft_free_str(&tmp, 1);
	}
	write(1, ret, ft_strlen(ret));
	ft_free_str(&ret, 1);
	ft_free_str(&new, 1);
	return (0);
}

int		convert_d(t_struct *db, va_list *pa)
{
	int		len;
	char	*new;
	char	*tmp;

	if (!(new = ft_itoa(va_arg(*pa, int))))
		return (-1);
	len = ft_strlen(new);
	if (new[0] == '-' && (db->minus || db->zero ||
			db->precise_dot >= len || db->precise_star >= len))
		if (!(new = cut_minus(new, db, new)))
			return (-1);
	len = ft_strlen(new);
	if ((db->min_width < 0) && db->zero)
		db->zero = 0;
	if ((db->precise_dot > len) || (db->precise_star > len))
	{
		tmp = new;
		if (!(new = manage_precision(db, new, len)))
			return (-1);
		ft_free_str(&tmp, 1);
	}
	if ((convert_d2(len, db, new) == (-1)))
		return (-1);
	return (db->min_width);
}
