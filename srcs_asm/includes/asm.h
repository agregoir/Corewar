/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fel-mazo <fel-mazo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:30:39 by fel-mazo          #+#    #+#             */
/*   Updated: 2018/04/07 17:02:24 by icampill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "printf.h"
# include "get_next_line.h"

# define _

# define TKN_NAN		0
# define TKN_LBL		1
# define TKN_INS		2
# define TKN_PAR		3

# define COM_C			'#'
# define L_C			':'
# define D_C			'%'
# define SEP			','

typedef struct			s_line
{
	size_t				nu;
	char				*line;
	struct s_line		*next;
}						t_line;

typedef struct			s_token
{
	char				*str;
	char				type;
	int					info;
	size_t				lnu;
	size_t				i;
	struct s_token		*next;
}						t_token;

typedef struct			s_op
{
	char				*label;
	unsigned int		num_params;
	unsigned int		types;
	unsigned int		op_code;
	unsigned int		coding_param;
	unsigned int		short_dir;
}						t_op;

typedef struct			s_ins
{
	t_op				*op;
	t_token				*tkn;
	size_t				ocp;
	int					params[3];
	int					para_size[3];
	size_t				size;
	int					offset;
	struct s_ins		*next;
}						t_ins;

typedef struct			s_file
{
	int					fd;
	t_line				*lines;
	t_token				*tokens;
	t_ins				*ins;
	t_header			header;
}						t_file;

t_file					*make_file(char *path);
size_t					sw(t_line *line, size_t *i);
char					is_label_char(char c);
char					is_param_char(char c);
t_token					*token_label(t_token *last, t_line *line, size_t *i);
t_token					*token_ins(t_token *last, t_line *line, size_t *i);
void					check_ins(t_file *file);
void					check_param(t_file *file);
t_token					*token_param(t_token *last, t_line *line, size_t *i);
t_token					*tokenize(t_file *file);
void					del_comments(t_file *file);
t_line					*read_lines(int fd);
t_token					*is_label(t_token *head, char *label);

extern t_op				g_op_tab[17];

void					parse_params(t_token *h, t_token *p, t_ins *i);
t_ins					*ins(t_token *tkn);
t_ins					*gen_ins(t_file *file);
void					put_params(t_file *file);
void					write_file(t_file *file, char *name);
int						rev_end(int value, int size);

void					print_lines(t_file *file);
void					print_tokens(t_token *head);
void					print_line(t_line *lines, size_t lnu);
void					print_ins(t_ins *ins, t_line *lines);
int						ext_comment(char **s);
int						ext_name(char **s);
void					check_rest(char *s);
int						clear_stuff(t_file *file, char *target);
void					check_comment(char *s, t_line *l, char *c, t_file *f);
void					free_file(t_file *file);

#endif
