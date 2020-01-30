/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 09:20:03 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 16:39:24 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_utoa(unsigned int n)
{
	long int	tmpn;
	int			len;
	char		*str;

	tmpn = n;
	len = 2;
	str = NULL;
	while (tmpn /= 10)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	return (str);
}

int		convert_u2(int len, t_struct *db, char *new)
{
	char *ret;

	len = manage_len(db, len, new);
	manage_min_width(db, len);
	if (!(ret = ft_malloc(db->min_width)))
		return (-1);
	if (db->minus)
		ret = convert_with_minus(len, ret, new, db);
	else
		ret = convert_without_minus(len, ret, new, db);
	write(1, ret, ft_strlen(ret));
	ft_free_str(&ret, 1);
	ft_free_str(&new, 1);
	return (1);
}

int		convert_u(t_struct *db, va_list *pa)
{
	unsigned int	conv;
	char			*new;
	char			*tmp;
	int				len;

	conv = va_arg(*pa, unsigned int);
	if (!(new = ft_utoa(conv)))
		return (-1);
	len = ft_strlen(new);
	if ((db->min_width < 0) && db->zero)
		db->zero = 0;
	if (db->precise_dot > len || db->precise_star > len)
	{
		tmp = new;
		if (!(new = manage_precision(db, new, len)))
			return (-1);
		ft_free_str(&tmp, 1);
	}
	if (convert_u2(len, db, new) == (-1))
		return (-1);
	return (db->min_width);
}
