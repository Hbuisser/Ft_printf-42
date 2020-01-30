/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:06:13 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 16:24:58 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	manage_min_width_with_percent(t_struct *db, int len)
{
	if (!db->min_width)
		db->min_width = len;
	if (db->min_width < 0 && (db->minus || db->zero))
	{
		db->min_width = (db->min_width * -1);
		db->minus = 1;
		db->zero = 0;
	}
	if (len > db->min_width)
		db->min_width = len;
	if (db->check_minus && (db->min_width > len))
		db->min_width -= 1;
}

int		convert_percent(t_struct *db)
{
	char	*new;
	char	*ret;
	int		len;

	new = "%";
	ret = NULL;
	len = 1;
	manage_min_width_with_percent(db, len);
	if (!(ret = ft_malloc(db->min_width)))
		return (-1);
	if (db->minus)
		ret = convert_with_minus(len, ret, new, db);
	else
		ret = convert_without_minus(len, ret, new, db);
	write(1, ret, ft_strlen(ret));
	ft_free_str(&ret, 1);
	return (db->min_width);
}
