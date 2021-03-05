/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 20:48:46 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/12 12:04:52 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_proc_d_precision(long int i, int *printed, t_sp *one, int len)
{
	char	*sitoa;

	if (i < 0)
	{
		write(1, "-", 1);
		i = i * -1;
		len--;
		*printed = *printed + 1;
	}
	while (one->precision > len)
	{
		write(1, "0", 1);
		one->precision--;
		*printed = *printed + 1;
	}
	sitoa = ft_itoa_printf(i);
	len = ft_len(i);
	if (i == 0 && one->dot == 1 && one->precision == 0)
	{
		write(1, " ", 1);
		len = 0;
	}
	write(1, sitoa, len);
	ft_free(sitoa);
	*printed = *printed + len;
}

void	ft_proc_d_width(long int i, int *printed, t_sp *one, int len)
{
	int	prec;

	prec = one->precision;
	one->width = (prec <= len) ? one->width - len : one->width - prec;
	if (one->flag > 1)
		ft_proc_d_precision(i, printed, one, len);
	if (i < 0 && prec > len)
		one->width = one->width - 1;
	while (one->width > 0)
	{
		if (i < 0 && one->flag < 1 && one->precision == 0)
		{
			write(1, "-", 1);
			i = i * -1;
		}
		if (one->flag == 0 && one->precision == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		*printed = *printed + 1;
		one->width--;
	}
	if (one->flag <= 1)
		ft_proc_d_precision(i, printed, one, len);
}

void	ft_d(t_sp *one, va_list arg, int *printed)
{
	long int	i;
	int			len;
	char		*sitoa;

	i = va_arg(arg, int);
	len = ft_len(i);
	if (one->precision > len && one->precision >= one->width)
	{
		ft_proc_d_precision(i, printed, one, len);
		return ;
	}
	else if (one->width > len && one->precision < one->width)
	{
		ft_proc_d_width(i, printed, one, len);
		return ;
	}
	sitoa = ft_itoa_printf(i);
	if (i == 0 && one->dot == 1 && one->precision == 0)
	{
		ft_free(sitoa);
		return ;
	}
	write(1, sitoa, len);
	ft_free(sitoa);
	*printed = *printed + len;
}

void	ft_u(t_sp *one, va_list arg, int *printed)
{
	long int	i;
	int			len;
	char		*sitoa;

	i = va_arg(arg, int);
	if (i < 0)
		i = 4294967295 + i + 1;
	len = ft_len(i);
	if (one->precision > len && one->precision >= one->width)
	{
		ft_proc_d_precision(i, printed, one, len);
		return ;
	}
	else if (one->width > len && one->precision < one->width)
	{
		ft_proc_d_width(i, printed, one, len);
		return ;
	}
	if (i == 0 && one->dot == 1 && one->precision == 0)
		return ;
	sitoa = ft_itoa_printf(i);
	write(1, sitoa, len);
	ft_free(sitoa);
	*printed = *printed + len;
}
