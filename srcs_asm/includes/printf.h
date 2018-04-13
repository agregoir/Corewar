/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 18:27:55 by fel-mazo          #+#    #+#             */
/*   Updated: 2017/03/18 00:27:09 by fel-mazo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <stdlib.h>

/*
** No effort will be put in the handeling of undefined behavior
** The goal of the project isn't to have a perfect reproduction of the
** original printf.
** I make the assumption that the format string is valid, and no validation
** effort will be made. It is simply not worth the time investment, and
** I think I'm smart enough to use my printf proprely
*/

/*
** the flags will be recorded as a multiplication of prime numbers
** we need 5 to encode the 5 flags : '-' '+' ' ' '0' '#'
** so (2 -> '-') (3 -> '+') (5 -> ' ') (7 -> '0') (11 -> '#')
** why would it work ? because 2*3*5*7*11 = 2310 which fits
** comfortably in an int
*/

/*
** the length will be encoded in a char, 'h' for h and 'h' + 1 for hh
** ll = m ; hh = i;
** so I'll need to test for h, l, i, m, j, z
*/

# define FLAGS_STR "-+ 0#"
# define LEN_STR "hljz"
# define BUFF_SIZE_PF 4096
# define MAX(x,y) (x) > (y) ? (x) : (y)
# define MIN(x,y) (x) > (y) ? (y) : (x)
# define ABS(x) (x) >= 0 ? (x) : - (x)
# define B16 "0123456789abcdef"
# define B16M "0123456789ABCDEF"

typedef unsigned int		t_ui;
typedef unsigned char		t_uc;
typedef unsigned short		t_us;
typedef unsigned long		t_ul;
typedef unsigned long long	t_ull;

typedef struct				s_job
{
	char					*start;
	char					*end;
	int						flags;
	t_ui					minw;
	ssize_t					prec;
	char					len;
	char					type;
	struct s_job			*prev;
	struct s_job			*next;
}							t_job;

typedef struct				s_pf
{
	char					buff[BUFF_SIZE_PF];
	char					err;
	char					*pos;
	int						fd;
	t_job					*job;
	char					*format;
	size_t					left;
	size_t					ret;
}							t_pf;

typedef struct				s_pf_op
{
	char					type;
	void					(*p)(t_pf *pf, va_list args);
}							t_pf_op;

int							ft_printf(const char *format, ...);
int							ft_vprintf(const char *format, va_list ap);
int							ft_vfprintf(int fd, const char *format, va_list ap);

/*
** Utility functions, I know I'm poluting the namespace.
** I'll either find a way to fix it
** or forget about it. The things we do for the sake of the style guide
*/
t_pf						*pf_init(int fd, const char *format, va_list args);

size_t						calc_size(t_pf *pf, va_list args);

char						*flush_buff(t_pf *pf);

void						clean_up(t_pf *pf, t_job *head);

void						update_nums(t_pf *pf, size_t len);
void						pf_putc(t_pf *pf, char c, size_t n);
void						pf_puts(t_pf *pf, char *s, ssize_t n);
size_t						pf_wclen(wchar_t c);
size_t						pf_wcslen(wchar_t *s);
void						pf_putwc(t_pf *pf, wchar_t c);
void						pf_putws(t_pf *pf, wchar_t *s, size_t n);

char						*get_len(char *str, t_job *job);
char						*get_prec(char *str, t_job *job, va_list args);
char						*get_minw(char *str, t_job *job, va_list args);
char						*get_flags(char *str, t_job *job);

t_job						*make_job();
void						popul(char	*str, t_job *job, va_list args);
t_job						*parse(const char *format, va_list args);
int							do_jobs(t_pf *pf, va_list args);
void						append_s(t_pf *pf, char *s, size_t len);

/*
** the handler functions
*/
void						pf_s(t_pf *pf, va_list args);
void						pf_ws(t_pf *pf, va_list args);
void						pf_di(t_pf *pf, va_list args);
void						pf_x(t_pf *pf, va_list args);
void						pf_u(t_pf *pf, va_list args);
void						pf_o(t_pf *pf, va_list args);
void						pf_c(t_pf *pf, va_list args);
void						pf_mc(t_pf *pf, va_list args);
void						pf_p(t_pf *pf, va_list args);
void						pf_pct(t_pf *pf, va_list args);

/*
** handler helpers
*/
void						handle_pds(t_pf *pf, size_t len);
void						handle_pdms(t_pf *pf, size_t len);
intmax_t					pf_fetch_d(t_pf *pf, va_list args);
uintmax_t					pf_fetch_u(t_pf *pf, va_list args);
size_t						pf_nb_size(uintmax_t nbr, uintmax_t base);
void						pf_putint(t_pf *pf, intmax_t nbr, char *base);
void						pf_putuint(t_pf *pf, uintmax_t nbr, char *base);
void						handle_pdd(t_pf *pf, int num, size_t len);
void						handle_pdmd(t_pf *pf, int num, size_t len);

/*
** My function pointer array with corresponding type
*/

static t_pf_op	g_ops[] = {
	{'s', &pf_s},
	{'S', &pf_ws},
	{'d', &pf_di},
	{'D', &pf_di},
	{'i', &pf_di},
	{'x', &pf_x},
	{'X', &pf_x},
	{'u', &pf_u},
	{'U', &pf_u},
	{'o', &pf_o},
	{'O', &pf_o},
	{'c', &pf_c},
	{'C', &pf_mc},
	{'p', &pf_p},
	{'%', &pf_pct},
	{-1, NULL}
};
#endif
