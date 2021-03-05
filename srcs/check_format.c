/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:28:49 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/12 13:47:44 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_proc_flag(char *format, int flag, int i)
{
	int	flag_new;

	flag_new = 0;
	if (format[i] == '0' && flag == 1)
		flag_new = 0;
	else if (format[i] == '-' && flag == 1 && format[i - 1] != '-')
		flag_new = 2;
	else if (format[i] == '-' && flag == 0 && format[i - 1] != '-')
		flag_new = 3;
	else if (format[i] == '0' && flag == 2)
		flag_new = 4;
	return (flag_new);
}

int		ft_proc_width(char *format, int i, va_list arg, int width)
{
	int width_new;

	if (format[i] == '*')
		width_new = va_arg(arg, int);
	else
		width_new = (width * 10) + (format[i] - 48);
	return (width_new);
}

int		ft_proc_precision(char *format, int i, va_list arg, int precision)
{
	int	precision_new;

	if (format[i] == '*')
		precision_new = va_arg(arg, int);
	else
		precision_new = (precision * 10) + (format[i] - 48);
	return (precision_new);
}

void	ft_type(t_sp *one, va_list arg, int *printed)
{
	if (one->type == 'd' || one->type == 'i')
		ft_d(one, arg, printed);
	else if (one->type == 'c')
		ft_c(one, arg, printed);
	else if (one->type == 's')
		ft_s(one, arg, printed);
	else if (one->type == 'u')
		ft_u(one, arg, printed);
	else if (one->type == 'x')
		ft_x(one, arg, printed);
	else if (one->type == 'X')
		ft_xx(one, arg, printed);
	else if (one->type == 'p')
		ft_p(one, arg, printed);
	else if (one->type == '%')
		ft_0_0(one, printed);
	else
		return ;
}

void	ft_0_0(t_sp *one, int *printed)
{
	while (one->width > 1 && one->flag == 0)
	{
		write(1, " ", 1);
		*printed = *printed + 1;
		one->width--;
	}
	write(1, "%", 1);
	*printed = *printed + 1;
	while (one->width > 1 && one->flag > 0)
	{
		write(1, " ", 1);
		*printed = *printed + 1;
		one->width--;
	}
}
