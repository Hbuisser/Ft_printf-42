/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:34:42 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 16:32:35 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_utoa_base(unsigned int n, int base)
{
	long int	tmpn;
	int			len;
	char		*str;
	char		*hex;

	hex = "0123456789abcdef";
	str = NULL;
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

char	*convert_both_x_2(int len, t_struct *db, char *new)
{
	char	*ret;

	len = manage_len(db, len, new);
	manage_min_width(db, len);
	if (!(ret = ft_malloc(db->min_width)))
		return (NULL);
	if (db->minus)
		ret = convert_with_minus(len, ret, new, db);
	else
		ret = convert_without_minus(len, ret, new, db);
	ft_free_str(&new, 1);
	return (ret);
}

char	*convert_both_x(t_struct *db, va_list *pa, int base)
{
	unsigned int	conv;
	char			*new;
	char			*ret;
	char			*tmp;
	int				len;

	conv = va_arg(*pa, unsigned int);
	if (!(new = ft_utoa_base(conv, base)))
		return (NULL);
	len = ft_strlen(new);
	if ((db->min_width < 0) && db->zero)
		db->zero = 0;
	if (db->precise_dot > len || db->precise_star > len)
	{
		tmp = new;
		if (!(new = manage_precision(db, new, len)))
			return (NULL);
		ft_free_str(&tmp, 1);
	}
	if (!(ret = convert_both_x_2(len, db, new)))
		return (NULL);
	return (ret);
}

int		convert_x(t_struct *db, va_list *pa)
{
	char	*ret;
	int		base;

	base = 16;
	if (!(ret = convert_both_x(db, pa, base)))
		return (-1);
	write(1, ret, ft_strlen(ret));
	ft_free_str(&ret, 1);
	return (db->min_width);
}

int		convert_big_x(t_struct *db, va_list *pa)
{
	char	*ret;
	int		i;
	int		base;

	i = 0;
	base = 16;
	if (!(ret = convert_both_x(db, pa, base)))
		return (-1);
	while (ret[i] != '\0')
	{
		ret[i] = ft_toupper(ret[i]);
		i++;
	}
	write(1, ret, ft_strlen(ret));
	ft_free_str(&ret, 1);
	return (db->min_width);
}
