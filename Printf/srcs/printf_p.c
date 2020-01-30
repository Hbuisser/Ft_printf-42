/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:53:58 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 16:38:17 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_ultoa_base(unsigned long n, int base)
{
	unsigned long int	tmpn;
	int					len;
	char				*str;
	char				*hex;

	str = NULL;
	hex = NULL;
	hex = "0123456789abcdef";
	tmpn = n;
	len = 2;
	while (tmpn /= base)
		len++;
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		if (base == 16)
			str[len] = hex[n % base];
		else
			str[len] = n % base + '0';
		n = n / base;
	}
	return (str);
}

int		convert_p2(int len, t_struct *db, char *new)
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
	ft_free_str(&new, 1);
	ft_free_str(&ret, 1);
	return (0);
}

int		convert_p(t_struct *db, va_list *pa)
{
	unsigned long	conv;
	char			*new;
	char			*tmp;
	int				base;
	int				len;

	base = 16;
	conv = va_arg(*pa, unsigned long);
	if (!(new = ft_ultoa_base(conv, base)))
		return (-1);
	tmp = new;
	if (!(new = ft_strjoin(db->add_ox, new)))
		return (-1);
	ft_free_str(&tmp, 1);
	len = ft_strlen(new);
	if (db->precise_dot > len || db->precise_star > len)
	{
		tmp = new;
		if (!(new = manage_precision(db, new, len)))
			return (-1);
		ft_free_str(&tmp, 1);
	}
	if (convert_p2(len, db, new) == (-1))
		return (-1);
	return (db->min_width);
}
