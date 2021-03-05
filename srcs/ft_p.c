/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 20:49:03 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/11 12:27:11 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_proc_p_precision(char *for_print, int *printed, t_sp *one, int len)
{
	while (one->precision > len)
	{
		write(1, "0", 1);
		one->precision--;
		*printed = *printed + 1;
	}
	write(1, "0x", 2);
	*printed = *printed + len + 2;
	while (len > 0)
		write(1, &for_print[--len], 1);
	ft_free(for_print);
}

void	ft_null_ptr(t_sp *one, int *printed)
{
	while (one->width > 3 && one->flag < 2)
	{
		write(1, " ", 1);
		*printed = *printed + 1;
		one->width--;
	}
	write(1, "0x0", 3);
	*printed = *printed + 3;
	while (one->width > 3 && one->flag > 1)
	{
		write(1, " ", 1);
		*printed = *printed + 1;
		one->width--;
	}
}

void	ft_proc_p_width(char *for_print, int *printed, t_sp *one, int len)
{
	int prec;

	if (*for_print == '0' && one->i == 0)
	{
		ft_null_ptr(one, printed);
		ft_free(for_print);
		return ;
	}
	prec = one->precision;
	if (prec <= len)
		one->width = one->width - len;
	else
		one->width = one->width - prec;
	if (one->flag > 1)
		ft_proc_p_precision(for_print, printed, one, len);
	while (one->width > 2)
	{
		write(1, " ", 1);
		*printed = *printed + 1;
		one->width--;
	}
	if (one->flag <= 1)
		ft_proc_p_precision(for_print, printed, one, len);
}

void	ft_p(t_sp *one, va_list arg, int *printed)
{
	long int	i;
	int			len;
	char		*for_print;

	if (!(for_print = (char*)ft_calloc(sizeof(char), 12)))
		return ;
	i = va_arg(arg, size_t);
	ft_proc_x(i, &for_print, one, 'a');
	len = ft_strlen(for_print);
	if (one->precision > len && one->precision >= one->width)
	{
		ft_proc_p_precision(for_print, printed, one, len);
		return ;
	}
	else if (one->width > len && one->precision < one->width)
	{
		ft_proc_p_width(for_print, printed, one, len);
		return ;
	}
	write(1, "0x", 2);
	*printed = *printed + len + 2;
	while (len > 0)
		write(1, &for_print[--len], 1);
	ft_free(for_print);
}
