/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:38:17 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/12 10:19:45 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_sp(t_sp *one)
{
	one->flag = 1;
	one->width = 0;
	one->dot = 0;
	one->precision = 0;
	one->i = 0;
	one->j = 0;
}

int		process(char *form, va_list arg, int *printed, t_sp *one)
{
	ft_sp(one);
	while (form[one->j] == '0' || form[one->j] == '-')
		one->flag = ft_proc_flag(form, one->flag, one->j++);
	while (form[one->j] == '*' || (form[one->j] >= '0' && form[one->j] <= '9'))
		one->width = ft_proc_width(form, one->j++, arg, one->width);
	if (form[one->j] == '.')
	{
		one->dot = 1;
		one->j++;
	}
	while (form[one->j] == '*' || (form[one->j] >= '0' && form[one->j] <= '9'))
		one->precision = ft_proc_precision(form, one->j++, arg, one->precision);
	one->type = form[one->j];
	if (one->width < 0)
	{
		one->width = one->width * -1;
		one->flag = 2;
	}
	if (one->precision < 0)
	{
		one->dot = 0;
		one->precision = 0;
	}
	ft_type(one, arg, printed);
	return (one->j);
}

int		work(char *format, va_list arg, int printed, t_sp *one)
{
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			printed++;
		}
		else if (*format == '%')
		{
			format++;
			format = format + (process((char*)format, arg, &printed, one));
		}
		if (*format)
			format++;
	}
	return (printed);
}
