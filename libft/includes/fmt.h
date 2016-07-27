/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/13 16:20:58 by tpaulmye          #+#    #+#             */
/*   Updated: 2015/11/03 17:13:24 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FMT_H
# define FMT_H

/*
** header dedicated to ft_printf and its cousins
*/

# include <stdarg.h>
# include <wchar.h>

typedef enum		e_conv
{
	NOPE,
	HH,
	H,
	L,
	LL,
	J,
	Z
}					t_conv;

typedef struct		s_env
{
	va_list			ap;
	int				count;
	int				index;
	int				iparse;
	int				ipadding;
	int				iprec;
	int				iconv;
}					t_env;

typedef struct		s_arg
{
	char			type;
	int				is_u;
	int				padding;
	char			typepad;
	char			justif;
	int				prec;
	int				is_prec;
	int				sizearg;
	int				base;
	char			sign;
	int				prefix;
	t_conv			conv;
}					t_arg;

int					ft_printf(const char *format, ...);
int					is_flag(char c);
int					is_flag1(char c);
int					is_flag3(char c);
int					is_conv(char c);
void				init_arg(char c, t_arg *opt);
int					get_padding(char *format, t_arg *opt, t_env *e);
void				ft_malloc_failure(void);
void				parse_nb(char c, char *format, t_env *e);
void				parse_string(char c, char *format, t_env *e);
char				*get_null_string(t_arg *opt, t_env *e);
void				ft_printstr(t_env *e, t_arg *opt);
void				get_precision(char *format, t_arg *opt, t_env *e);
void				put_padding_left(int i, t_env *e, t_arg *opt);
void				put_padding_right(int i, t_env *e, t_arg *opt);
int					get_size_string(char *s, t_env *e, t_arg *opt);
char				*ft_itobase(unsigned long long n, unsigned long long base);
void				ft_print_nb(char *format, t_arg *opt, t_env *e);
void				get_flag3(char *format, t_arg *opt, t_env *e);
long long			get_nb(char c, t_arg *opt, t_env *e);
int					is_unsigned(char c);
int					get_size_number(long long nb, t_arg *opt, t_env *e,
					char **s);
void				put_padding_nb_left(t_env *e, t_arg *opt);
void				put_padding_nb_right(t_env *e, t_arg *opt);
void				ft_ustr(char *s);
char				*ft_lltoa(long long n);
char				*get_wc(wchar_t wc, t_arg *opt);
void				ft_printwstr(t_env *e, t_arg *opt);

/*
** typedef struct		s_arg
** {
**		char			type;		| type of conversion : sSxXoOduib etc.
**		int				is_u;		| unsigned or not
**		int				padding;	| number containing padding
**		char			typepad;	| type of padding : ' ' or '0'
**		char			justif;		| 'r' : padding at left, 'l' at right
**		int				prec;		| number containing precision
**		int				is_prec;	| bool to know if precision is set
**		int				sizearg;	| size of printed argument, used for padding
**		int				base;		| base to convert number : 10, 16, 8 or 2
**		char			sign;		| sign '+' or ' ' for positive numbers
**		int				prefix;		| prefix 0x ou 0X for hexas, 0 for octal
**		t_conv			conv;		| type of conversion : hh, h, l, ll, j, z
**	}					t_arg;
** The s_env structure contains the va_list, the return value count, and
** several indexes used in parsing functions to advance in format.
*/

#endif
