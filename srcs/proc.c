/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:38:39 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/10 19:42:18 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_proc_x(size_t i, char **for_print, t_sp *one, char a)
{
	one->i = i;
	if (i == 0 && one->precision >= 0)
		*for_print = ft_strjoin_printf(*for_print, "0");
	while (i > 0)
	{
		a = i % 16;
		if (a == 10)
			a = 'a';
		else if (a == 11)
			a = 'b';
		else if (a == 12)
			a = 'c';
		else if (a == 13)
			a = 'd';
		else if (a == 14)
			a = 'e';
		else if (a == 15)
			a = 'f';
		else
			a = a + 48;
		*for_print = ft_strjoin_printf(*for_print, &a);
		i = i / 16;
	}
	return (one->i);
}

int	ft_proc_xx(unsigned int i, char **for_print, t_sp *one, char a)
{
	one->i = i;
	if (i == 0 && one->precision >= 0)
		*for_print = ft_strjoin_printf(*for_print, "0");
	while (i > 0)
	{
		a = i % 16;
		if (a == 10)
			a = 'A';
		else if (a == 11)
			a = 'B';
		else if (a == 12)
			a = 'C';
		else if (a == 13)
			a = 'D';
		else if (a == 14)
			a = 'E';
		else if (a == 15)
			a = 'F';
		else
			a = a + 48;
		*for_print = ft_strjoin_printf(*for_print, &a);
		i = i / 16;
	}
	return (one->i);
}
