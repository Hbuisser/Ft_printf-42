/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 15:31:39 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 15:34:49 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*convert_with_minus(int len, char *ret, char *new, t_struct *db)
{
	int i;

	i = 0;
	while (i < len)
	{
		ret[i] = new[i];
		i++;
	}
	while (i < db->min_width)
	{
		if (db->zero)
			ret[i] = '0';
		else
			ret[i] = ' ';
		i++;
	}
	return (ret);
}

char	*convert_without_minus(int len, char *ret, char *new, t_struct *db)
{
	int i;

	i = db->min_width;
	while (i-- > 0 && len-- > 0)
		ret[i] = new[len];
	if (db->zero)
	{
		while (i >= 0)
		{
			ret[i] = '0';
			i--;
		}
	}
	return (ret);
}

char	*cut_minus(char *str, t_struct *db, char *new)
{
	char	*s2;
	char	*tmp;
	int		i;

	s2 = NULL;
	tmp = new;
	if (!(s2 = (char *)malloc(sizeof(char) * ft_strlen(str))))
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		s2[i] = str[i + 1];
		i++;
	}
	s2[i] = '\0';
	db->check_minus = 1;
	ft_free_str(&tmp, 1);
	return (s2);
}

char	*add_minus2(char *s2, t_struct *db, char *tmp)
{
	if (s2[0] != ' ')
	{
		if (!(s2 = ft_strjoin(db->add_minus, s2)))
			return (NULL);
	}
	db->min_width += 1;
	ft_free_str(&tmp, 1);
	return (s2);
}

char	*add_minus(char *str, int len, t_struct *db)
{
	char	*s2;
	char	*s3;
	char	*tmp;

	if (!(s2 = ft_strdup(str)))
		return (NULL);
	tmp = s2;
	if (s2[0] == ' ')
	{
		if (!(s2 = ft_substr(s2, (db->min_width - len), len)))
			return (NULL);
		ft_free_str(&tmp, 1);
		tmp = s2;
		if (!(s2 = ft_strjoin(db->add_minus, s2)))
			return (NULL);
		ft_free_str(&tmp, 1);
		tmp = s2;
		if (!(s3 = ft_malloc(db->min_width - len)))
			return (NULL);
		if (!(s2 = ft_strjoin(s3, s2)))
			return (NULL);
		ft_free_str(&s3, 1);
	}
	return (add_minus2(s2, db, tmp));
}
