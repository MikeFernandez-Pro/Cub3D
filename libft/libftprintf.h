/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifernan <mifernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:38:05 by mifernan          #+#    #+#             */
/*   Updated: 2020/03/03 11:43:47 by mifernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdarg.h>
# include "libft.h"
# include "get_next_line.h"

int			ft_numlen(long int nb, int base);
long int	ft_convert_ld(long int nb);
char		*ft_convert_d(long int nb);
char		*ft_convert_xmin(long int nb);
char		*ft_convert_ptr(long int nb);
char		*ft_convert_xmaj(long int nb);
char		*ft_convert_u(long int nb);
int			ft_flags_valid(char *flags);
int			ft_is_conv(char c);
void		ft_free_tab(char **tab);
char		*ft_find_flags(const char *str);
char		**ft_split_flags(const char *str);
int			ft_putconv(char *flags, va_list *args);
int			ft_printf(const	char *src, ...);
char		ft_find_flag(char *str);
int			ft_find_pos_prec(char *str);
int			ft_find_width(char *str, va_list *args);
int			ft_find_width_prec(char *str, va_list *args, int i);
int			ft_find_precision(char *str, va_list *args);
char		*ft_init_strwidth(int width, char *cpy, char *flag);
char		*ft_init_pustr(char *cpy, int prec);
int			ft_put_printf(const char *src, int *i);
int			ft_while_printf(const char *src, char **flags, va_list *args);
int			ft_isneg(char *cpy);
char		*ft_find_pos_neg(char *cpy);
char		*ft_init_dprec(int prec, char *cpy, char *flag);
char		*ft_init_dwidth(int width, char *cpy, char *flag, int prec);
int			ft_putd_c(char *flags, va_list *args);
int			ft_putu_c(char *flags, va_list *args);
int			ft_putxmin_c(char *flags, va_list *args);
int			ft_putxmaj_c(char *flags, va_list *args);
char		*ft_init_ptrwidth(int width, char *flag, char *cpy);
int			ft_putptr_c(char *flags, va_list *args);
int			ft_putstr_c(char *flags, va_list *args);
char		*ft_convert_char(int c);
char		*ft_init_charwidth(int width, char *flag);
int			ft_putchar_c(char *flags, va_list *args);
int			ft_len_src(const char *src);

#endif
