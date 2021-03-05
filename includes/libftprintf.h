/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <hballaba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/29 18:17:55 by hballaba          #+#    #+#             */
/*   Updated: 2020/07/12 10:21:15 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H

# define LIBFTPRINTF_H

# include "../srcs/libft/libft.h"
# include <stdarg.h>

typedef struct	s_specifier
{
	int		flag;
	int		width;
	int		dot;
	int		precision;
	char	type;
	int		i;
	int		j;
}				t_sp;

int				ft_printf(const char *format, ...);
int				ft_proc_flag(char *format, int flag, int i);
int				ft_proc_width(char *format, int i, va_list arg, int width);
int				ft_proc_precision(char *format, int i, va_list arg, \
				int precision);
void			ft_type(t_sp *one, va_list arg, int *printed);
void			ft_c(t_sp *one, va_list arg, int *printed);
void			ft_s(t_sp *one, va_list arg, int *printed);
void			ft_d(t_sp *one, va_list arg, int *printed);
void			ft_u(t_sp *one, va_list arg, int *printed);
void			ft_x(t_sp *one, va_list arg, int *printed);
void			ft_xx(t_sp *one, va_list arg, int *printed);
void			ft_p(t_sp *one, va_list arg, int *printed);
int				ft_proc_x(size_t i, char **for_print, t_sp *one, char a);
int				ft_proc_xx(unsigned int i, char **for_print, t_sp *one, char a);
int				ft_len(long int number);
char			*ft_itoa_printf(long int n);
void			ft_sp(t_sp *one);
char			*ft_strjoin_printf(char *s1, char const *s2);
void			ft_free(char *for_print);
int				process(char *form, va_list arg, int *printed, t_sp *one);
int				work(char *format, va_list arg, int printed, t_sp *one);
void			ft_proc_x_precision(char *for_print, int *printed, t_sp *one, \
				int len);
void			ft_proc_x_width(char *for_print, int *printed, t_sp *one, \
				int len);
void			ft_proc_d_precision(long int i, int *printed, t_sp *one,
			int len);
void			ft_proc_d_width(long int i, int *printed, t_sp *one, int len);
void			ft_proc_p_precision(char *for_print, int *printed, t_sp *one, \
			int len);
void			ft_null_ptr(t_sp *one, int *printed);
void			ft_proc_p_width(char *for_print, int *printed, t_sp *one, \
			int len);
void			ft_0_0(t_sp *one, int *printed);

#endif
