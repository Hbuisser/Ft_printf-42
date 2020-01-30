/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:31:53 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 15:34:18 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	manage_min_width(t_struct *db, int len)
{
	if (!db->min_width)
		db->min_width = len;
	if (db->min_width < 0)
	{
		db->min_width = (db->min_width * -1);
		db->minus = 1;
	}
	if ((len > db->min_width) && (db->min_width > 0))
		db->min_width = len;
	if (db->check_minus && (db->min_width > len))
		db->min_width -= 1;
	if (db->precise_dot > 0 || db->precise_star > 0)
		db->zero = 0;
	if ((db->precise_null == 1) && db->zero)
		db->zero = 0;
	if (db->precise_dot == 0 || db->precise_star == 0)
		db->zero = 0;
}

char	*manage_precision(t_struct *db, char *new, int len)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	j = 0;
	i = 0;
	k = db->precise_dot;
	if (db->precise_star > (-1))
		k = db->precise_star;
	if (!(str = ft_malloc(k)))
		return (NULL);
	while (i < (k - len))
	{
		str[i] = '0';
		i++;
	}
	while (i < k)
	{
		str[i] = new[j];
		i++;
		j++;
	}
	return (str);
}

int		manage_len(t_struct *db, int len, char *new)
{
	len = ft_strlen(new);
	if ((db->precise_dot == 0) && (new[0] == '0'))
		len = 0;
	if ((db->precise_star == 0) && (new[0] == '0'))
		len = 0;
	if ((db->precise_null == 1) && (new[0] == '0'))
		len = 0;
	return (len);
}

char	*ft_malloc(int size)
{
	char	*new_s;
	int		i;

	i = 0;
	new_s = NULL;
	if (!(new_s = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (size--)
	{
		new_s[i] = ' ';
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}

int		ft_free_str(char **str, int result)
{
	if (*str)
	{
		free(*str);
		*str = 0;
	}
	return (result);
}
