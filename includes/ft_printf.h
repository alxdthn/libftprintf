/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihail <mihail@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 15:27:31 by nalexand          #+#    #+#             */
/*   Updated: 2019/07/23 17:25:46 by mihail           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define FLAGS "# 0-+"
# define TYPES "cCsSpdDioOuUxXfF"
# define ALL_PARAM "# 0-+lhLzj.123456789*"
# define N_SIZE 16383
# define ACC 20
# define RUS "rus"
# define USA "usa"
# define EMS "ems"
# define RUS_WIDTH 60
# define RUS_SQR RUS_WIDTH * 15
# define CLR_COUNT 10
# define EOC "\033[0m"
# define BLC "\033[30m"
# define RED "\033[31m"
# define GRE "\033[32m"
# define YEL "\033[33m"
# define BLU "\033[34m"
# define MAG "\033[35m"
# define CYN "\033[36m"
# define WHI "\033[37m"
# include <stdarg.h>
# include "libft.h"

typedef	struct			s_flags
{
	char				sharp;
	char				zero;
	char				minus;
	char				plus;
	char				space;
}						t_flags;

typedef struct			s_size
{
	char				chr;
	size_t				value;
}						t_size;

typedef struct			s_ftask
{
	t_flags				flags;
	t_size				size;
	char				*clr;
	int					width;
	int					prc;
	char				type;
}						t_ftask;

typedef struct			s_res
{
	char				*str;
	ssize_t				len;
}						t_res;

typedef struct			s_out
{
	t_res				res;
	t_ftask				ftask;
}						t_out;

typedef	union			u_ems
{
	long double			ldbl;
	struct				s_ems
	{
		unsigned long	m : 64;
		unsigned short	e : 15;
		unsigned char	s : 1;
	}					ems;
}						t_ems;

typedef struct			s_lnbr
{
	ssize_t				len;
	int					vls[N_SIZE];
}						t_lnbr;

typedef union			u_unicode
{
	int					bits;
	struct				s_parts
	{
		unsigned int	a : 6;
		unsigned int	b : 6;
		unsigned int	c : 6;
		unsigned int	d : 6;
	}					parts;
}						t_unic;

int						parse_color(char **fmt, t_ftask *ftask, va_list *args);
int						solve_color(char *clr, va_list *args);
void					get_color(char **fmt, char **clr);

size_t					unicode_len(wchar_t *u_str, int count, int prc);
char					*get_uchar(char *buf, int uchar, int size);

t_res					solve_float(t_ftask *ftask, va_list *args);
void					get_ldbl(t_res *res, t_ftask *ftask, t_ems *uni);
void					get_float_div(t_lnbr *div, t_ems uni);
void					get_float_mod(t_lnbr *mod, t_ems uni, int prc);

t_lnbr					set_lnbr(char *str);
void					clear_lnbr(t_lnbr *lnbr);
void					multi_lnbr(t_lnbr *a, t_lnbr *b);
void					add_lnbr(t_lnbr *a, t_lnbr *b);
void					values_to_chars(char **data, size_t size);
void					pos_pow_of_two(t_lnbr *pow, t_lnbr *factor,
						int *max, char p);
void					neg_pow_of_two(t_lnbr *pow, t_lnbr *factor,
						int *max, char p);

void					out_new(t_out *out);

int						solve_fun(char *clr, va_list *args);
void					get_size(char **fmt, t_size *size);
void					get_prc(char **fmt, int *prc, va_list *args);
void					get_width(char **fmt, t_ftask *ftask, va_list *args);
int						get_flags(char fmt, t_ftask *ftask);

void					set_sign(t_res *res, t_ftask *ftask, long nbr);
void					set_prc(t_res *res, int prc);
void					set_width(t_res *res, t_ftask *ftask, char filler);
void					set_zero(t_res *res, int width);

t_res					pf_ltoa_base(unsigned long nbr,
						char base, t_ftask *ftask);
t_res					set_arg_digit(t_ftask *ftask, va_list *args);
t_res					set_arg_string(t_ftask *ftask, va_list *args);
t_res					solve_digit(t_ftask *ftask, long arg);
t_res					solve_uchar(t_ftask *ftask, wchar_t uchar);
t_res					solve_ustr(t_ftask *ftask, wchar_t *ustr);
t_res					solve_noconv(t_ftask *ftask);
t_res					solve_ptr(t_ftask *ftask, unsigned long ptr);
t_res					solve_bits(t_ftask *ftask, va_list *args);

int						find_type(char *fmt);
int						parse(char **fmt, t_out *out, va_list *args);
int						ft_printf(char *fmt, ...);

void					print_lnbr(t_lnbr nbr);
char					*show_lnbr(t_lnbr nbr);
int						print_ldbl_ems(t_ems ems, char param);

#endif
