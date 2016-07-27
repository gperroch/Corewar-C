/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pilespin <pilespin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 15:39:53 by sdahan            #+#    #+#             */
/*   Updated: 2016/05/15 16:34:15 by pilespin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "libft.h"

# define TRUE			0x1
# define FALSE			0x0
# define STDIN			0x0
# define STDERR			0x2

# define OPT_EMPTY		(1<<0)
# define OPT_A			(1<<1)
# define OPT_C			(1<<2)
# define OPT_H			(1<<4)
# define OPT_BAD		(1<<3)

# define SIZE_BYTE_LINE	16
# define SIZE_OP		17

# define NAME_CODE		0x4
# define LABEL_CODE		0x5
# define COMMENT_CODE	0x6
# define OP_CODE		0x7
# define DLABEL_CODE	0x8
# define ILABEL_CODE	0x9

# define EMPTY			(-1)
# define REGISTER_CHAR	'r'

# define LEN_TAB 		15

/*
**	C_CODE for ft_strerror(int code) width message (below)
*/

# define C_OPEN_FAILED	(-1)
# define C_BAD_EXT		(-2)
# define C_MALLOC		(-3)
# define C_READ			(-4)
# define C_MISS_NAME	(-5)
# define C_MISS_COMMENT	(-6)
# define C_SYNTAX_NAME	(-7)
# define C_SYNTAX_COM	(-8)
# define C_SIZE_NAME	(-9)
# define C_SIZE_COMMENT	(-10)
# define C_EMPTY_FILE	(-11)
# define C_SIZE_CHAMP	(-12)
# define C_CREATE_FAIL	(-13)
# define C_NO_INSTRUCT	(-14)

/*
**	Message for ft_strerror(int code) width C_CODE
*/

# define M_OPEN_FAILED	"Can't read source file"
# define M_MALLOC		"error malloc"
# define M_READ			"error read"
# define M_BAD_EXT		"Bad extension, file must end by extension .s"
# define M_MISS_NAME	"Name of champion is mandatory"
# define M_MISS_COMMENT	"Comment of champion is mandatory"
# define M_SYNTAX_NAME	"Syntax error for the name champion"
# define M_SYNTAX_COM	"Syntax error for the comment champion"
# define M_SIZE_NAME	"Champion name too long"
# define M_SIZE_COMMENT	"Comment size too long"
# define M_EMPTY_FILE	"Empty file"
# define M_SIZE_CHAMP	"Champion size too long"
# define M_CREATE_FAIL	"Can't create bytecode file"
# define M_NO_INSTRUCT	"No instructions"

# define ASM_EXTENSION	".s"
# define FINAL_EXTENSON	".cor"

# define COMMENT_CHAR_2	';'
# define MAX_ELEMENTS	(MAX_ARGS_NUMBER + 2)

typedef unsigned int	t_ui;

# define YELLOW			"\033[33m"
# define DEFAULT		"\033[0m"
# define PURPLE			"\033[35m"
# define CYAN			"\033[36m"
# define RED			"\033[31m"
# define GREEN			"\033[32m"
# define RED_LIGHT		"\033[1;31m"
# define GREEN_LIGHT	"\033[1;32m"
# define BLUE_LIGHT		"\033[1;34m"

# define ERROR_TOKEN	(-1)
# define UNKNOW_TOKEN	"Unknow token"
# define UNKNOW_OPCODE	"Unknow opcode"
# define FORMAT_REG		"Wrong format register"
# define OVERFLOW_REG	"Bad number register"
# define SYNTAX_ERR_AF	"Syntax error after"
# define FORMAT_LABEL	"Wrong format label"
# define MANY_TOKEN		"Too many token"
# define NB_PARAMS		"Bad number parameter for"
# define BAD_PARAM		"Bad parameter"
# define SYNTAX_SEPARAT	"Syntax error separator"
# define LABEL_NO_SUCH	"No such label"

# define OK_WRITE		"Writing output program to"

# define ABS(x) ((x) < 0 ? -(x) : (x))

typedef struct		s_op
{
	char			*name;
	size_t			nb_param;
	char			params[MAX_ARGS_NUMBER];
	char			op_number;
	size_t			cycle_length;
	char			*description;
	int				ocp;
	int				carry_modif;
}					t_op;

typedef struct		s_token {
	int				type;
	int				index;
	t_ui			value;
	char			*lexeme;
}					t_token;

typedef struct		s_line {
	t_op			*op;
	t_list			*token;
	int				number;
	int				nb_byte;
	int				islabel;
	char			*data;
	char			bytecode[SIZE_BYTE_LINE];
}					t_line;

typedef struct		s_source {
	char			*name;
	int				options;
	t_list			*line;
	t_header		header;
}					t_source;

typedef struct		s_args
{
	char			*filename;
	char			*newname;
	struct s_args	*next;
}					t_args;

int					g_color;

static const t_op	g_optab[SIZE_OP] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

/*
**				PRINT.c
*/

int					ft_strerror(int code);
void				ft_perror(char *error);
void				ft_pcolor(char *msg, char *after, char *color);
int					ft_perror_after(char *error, char *after, int line);

/*
**				TOOLS.c
*/

t_ui				uint_swap(t_ui nb);
int					ft_isstrdigit(char *str);
int					ft_open(const char *name, int mode);
t_ui				ft_get_progsize(t_list *line);
size_t				ft_count_params(t_list *tokens);

/*
**				CHECK_LINE.c
*/

char				*ft_getlabel(char *line);
int					ft_isempty_line(char *line);
int					ft_iscomment_line(char *line);
int					ft_is_label_and_exec(char *line);

/*
**				FREE.c
*/

void				ft_free_list_args(t_args **arg);
void				ft_free_source(t_source *source);

/*
**				SAVE_SOURCE.C
*/

int					ft_save_source(t_source *source, char *name);

/*
**				LEXICAL_ANALYSIS.c
*/

int					ft_lexical_analysis(t_source *source);

/*
**				PARSE_PARAM.c
*/

int					ft_parse_type_param(t_line *line);
int					ft_parse_param(t_token *token, int line);
int					ft_check_separator(char *str, int nb_param, int line);

/*
**				PARSE_LEXEME.c
*/

int					ft_check_lexeme(t_line *line);
int					ft_parse_type(char *lexeme, int index, int line);

/*
**				SEMANTIC_ANALYSIS.c
*/

int					ft_getvalue_token(t_list *first_line, t_list *line);

/*
**				GET_SOURCE.c
*/

int					ft_get_source(t_source *source, int fd);

/*
**				PARSE_HEADER.c
*/

int					ft_parse_header(t_source *source);

/*
**				CREATE_BYTECODE.c
*/

int					ft_create_bytecode(t_source *source);

/*
**				WRITE_BYTECODE
*/

int					ft_write_bytecode(t_source *source);

/*
**				PARSE_OPTION.c
*/

t_args				*ft_parse_option(t_source *e, char **av);
void				ft_print_list_arg(t_args *arg);
void				ft_add_to_arg(t_args **arg, t_args *new);
t_args				*ft_create_arg(char *filename, char *newname);

/*
**				OPTION_DEBUG_CHAMPION.c
*/

void				ft_option_debug_champion(t_source *source);

/*
**				TOOLS_2.c
*/

char				*ft_strjoinf(char **s1, const char *s2);
void				ft_putstrc(int color, int background, char *str);
void				ft_align_text(int len, int offset);

/*
**				DEBUG
*/

void				ft_pcode(t_list *first);
void				ft_pbyte(char t[], int n);

#endif
