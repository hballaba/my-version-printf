/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:37:30 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/10 10:15:54 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	int			printed;
	t_sp		*one;

	if (!(one = (t_sp*)malloc(sizeof(t_sp))))
		return (-1);
	printed = 0;
	va_start(arg, format);
	printed = work((char*)format, arg, printed, one);
	va_end(arg);
	free(one);
	return (printed);
}
