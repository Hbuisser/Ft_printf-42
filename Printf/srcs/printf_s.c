/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 14:56:44 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 16:25:11 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	convert_s(t_struct *db, va_list *pa)
{
	char	*ret;
	char	*new;
	int		len;

	new = (char *)va_arg(*pa, const char *);
	if (!new)
		new = "(null)";
	if (db->precise_null > 0)
		new = "";
	len = ft_strlen(new);
	if ((db->precise_dot > (-1)) && (db->precise_dot < len))
		len = db->precise_dot;
	else if ((db->precise_star > (-1)) && (db->precise_star < len))
		len = db->precise_star;
	manage_min_width(db, len);
	if (!(ret = ft_malloc(db->min_width)))
		return (-1);
	if (db->minus)
		convert_with_minus(len, ret, new, db);
	else
		convert_without_minus(len, ret, new, db);
	write(1, ret, db->min_width);
	ft_free_str(&ret, 1);
	return (db->min_width);
}
