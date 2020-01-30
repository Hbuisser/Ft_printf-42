/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbuisser <hbuisser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:28:08 by hbuisser          #+#    #+#             */
/*   Updated: 2020/01/23 15:40:07 by hbuisser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	check_convertor(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (c);
	return (0);
}

int	check_fmt(char *f)
{
	int	i;

	i = 0;
	if (!f)
		return (-1);
	while (*f != '\0')
	{
		if (*f == '%' && i == 0)
			i = 1;
		else if (check_convertor(*f) && i == 1)
			i = 0;
		f++;
	}
	if (i == 1)
		return (0);
	return (1);
}
