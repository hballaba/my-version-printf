/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:37:22 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/10 11:48:43 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_c(t_sp *one, va_list arg, int *printed)
{
	char	i;

	i = va_arg(arg, unsigned int);
	while (one->flag == 1 && one->width-- > 1)
	{
		write(1, " ", 1);
		*printed = *printed + 1;
	}
	while (one->flag == 0 && one->width-- > 1)
	{
		write(1, "0", 1);
		*printed = *printed + 1;
	}
	write(1, &i, 1);
	*printed = *printed + 1;
	while (one->flag == 2 && one->width-- > 1)
	{
		write(1, " ", 1);
		*printed = *printed + 1;
	}
}

void	ft_write_space(int len, int *printed, t_sp *one)
{
	while (one->width-- > len)
	{
		write(1, " ", 1);
		*printed = *printed + 1;
	}
}

void	ft_s(t_sp *one, va_list arg, int *printed)
{
	char	*i;
	int		len;

	i = va_arg(arg, char*);
	if (!i)
	{
		i = ft_strdup("(null)");
		one->type = 'm';
	}
	len = ft_strlen(i);
	if (one->type == 'm' && one->precision < len)
		one->precision = 0;
	if (one->dot == 1 && len > one->precision)
		len = one->precision;
	if (one->flag == 1 && (one->width > len))
		ft_write_space(len, printed, one);
	write(1, *&i, len);
	*printed = *printed + len;
	if (one->flag == 2 && one->width > len)
		ft_write_space(len, printed, one);
	if (one->type == 'm')
		ft_free(i);
}
