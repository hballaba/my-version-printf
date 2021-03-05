/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x_xx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:37:55 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/12 12:09:33 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_proc_x_precision(char *for_print, int *printed, t_sp *one, \
			int len)
{
	while (one->precision > len)
	{
		write(1, "0", 1);
		one->precision--;
		*printed = *printed + 1;
	}
	if (one->i == 0 && one->dot == 1 && one->precision == 0)
	{
		write(1, " ", 1);
		len = 0;
		*printed = *printed + 1;
	}
	*printed = *printed + len;
	while (len > 0)
		write(1, &for_print[--len], 1);
	ft_free(for_print);
}

void		ft_proc_x_width(char *for_print, int *printed, t_sp *one, int len)
{
	int prec;

	prec = one->precision;
	if (prec <= len)
		one->width = one->width - len;
	else
		one->width = one->width - prec;
	if (one->flag > 1)
		ft_proc_x_precision(for_print, printed, one, len);
	while (one->width > 0)
	{
		if (one->flag == 0 && one->precision == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		*printed = *printed + 1;
		one->width--;
	}
	if (one->flag <= 1)
		ft_proc_x_precision(for_print, printed, one, len);
}

long int	check_arg_x(va_list arg)
{
	long int i;

	i = va_arg(arg, int);
	if (i < 0)
		i = 4294967295 + i + 1;
	return (i);
}

void		ft_x(t_sp *one, va_list arg, int *printed)
{
	long int	i;
	int			len;
	char		*for_print;

	if (!(for_print = (char*)ft_calloc(sizeof(char), 8)))
		return ;
	i = check_arg_x(arg);
	one->i = ft_proc_x(i, &for_print, one, 'a');
	len = ft_strlen(for_print);
	if (one->precision > len && one->precision >= one->width)
	{
		ft_proc_x_precision(for_print, printed, one, len);
		return ;
	}
	else if (one->width > len && one->precision < one->width)
	{
		ft_proc_x_width(for_print, printed, one, len);
		return ;
	}
	if (one->i == 0 && one->dot == 1 && one->precision == 0)
		len = 0;
	*printed = *printed + len;
	while (len > 0)
		write(1, &for_print[--len], 1);
	ft_free(for_print);
}

void		ft_xx(t_sp *one, va_list arg, int *printed)
{
	long int	i;
	int			len;
	char		*for_print;

	if (!(for_print = (char*)ft_calloc(sizeof(char), 8)))
		return ;
	i = check_arg_x(arg);
	one->i = ft_proc_xx(i, &for_print, one, 'a');
	len = ft_strlen(for_print);
	if (one->precision > len && one->precision >= one->width)
	{
		ft_proc_x_precision(for_print, printed, one, len);
		return ;
	}
	else if (one->width > len && one->precision < one->width)
	{
		ft_proc_x_width(for_print, printed, one, len);
		return ;
	}
	if (one->i == 0 && one->dot == 1 && one->precision == 0)
		len = 0;
	*printed = *printed + len;
	while (len > 0)
		write(1, &for_print[--len], 1);
	ft_free(for_print);
}
