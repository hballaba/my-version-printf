/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 17:38:30 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/10 13:29:19 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_len(long int number)
{
	int		i;

	i = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number = number * (-1);
		i = 1;
	}
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_printf(long int n)
{
	long int	number;
	char		*str;
	size_t		i;

	number = n;
	i = ft_len(number);
	str = (char*)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (number == 0)
		str[0] = 48;
	if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		i--;
		str[i] = number % 10 + 48;
		number /= 10;
	}
	return (str);
}

char	*ft_strjoin_printf(char *s1, char const *s2)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;

	lens1 = ft_strlen((char*)s1);
	lens2 = 1;
	str = (char*)malloc(lens1 + lens2 + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, lens1 + 1);
	ft_strlcat(str, s2, lens2 + lens1 + 1);
	free(s1);
	s1 = NULL;
	return (str);
}

void	ft_free(char *for_print)
{
	free(for_print);
	for_print = NULL;
}
