/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpaulmye <tpaulmye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 10:49:05 by gperroch          #+#    #+#             */
/*   Updated: 2016/05/19 09:56:20 by tpaulmye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "op.h"
# include "libft.h"
# include <ncurses.h>
# define BUFSIZE (65535)
# define COREWAR_MAGIC_LE (0xf383ea00)
# define ABS(x) ((x) < 0 ? -(x) : (x))
# define NCURSE_REFRESH	(10)
# define NCURSE_SLEEP	(50000)
# define DEBUG_OFFSET   (20)

/*
**	error codes
*/

# define OPT_DUMP (1)
# define OPT_S (1<<1)
# define OPT_V (1<<2)
# define OPT_N (1<<3)
# define OPT_C (1<<4)
# define CHAMP_TOO_SMALL (-1)
# define CHAMP_TOO_BIG	 (-2)
# define OPEN_FAILED	 (-3)
# define READ_FAILED	 (-4)
# define INVALID_CHAMP	 (-5)
# define NO_CHAMPS		 (-6)
# define TOO_MANY_CHAMPS (-7)

typedef struct			s_op
{
	char				*name;
	size_t				nb_param;
	char				params[MAX_ARGS_NUMBER];
	char				op_number;
	size_t				cycle_length;
	char				*description;
	int					ocp;
	int					use_index;
}						t_op;

/*
** struct used in ncurse to display messages alongisde the box of the game
*/

typedef struct			s_proc
{
	char				carry;
	int					regs[REG_NUMBER];
	int					pc;
	size_t				cycles;
	size_t				cyclelimit;
	int					current_op;
	int					live;
	int					last_live;
	struct s_warrior	*owner;
	int					color;
}						t_proc;

typedef struct			s_warrior
{
	int					number;
	char				name[PROG_NAME_LENGTH + 1];
	unsigned int		size;
	char				comment[COMMENT_LENGTH + 1];
	char				code[CHAMP_MAX_SIZE + 1];
	t_list				*procs;
	size_t				nbprocs;
	int					color;
}						t_warrior;

typedef struct			s_core
{
	int					options;
	int					*warriors_numbers;
	int					lives_total[MAX_PLAYERS];
	int					lives_tmp[MAX_PLAYERS];
	int					last_warrior;
	char				**warriors_path;
	int					dumps;
	int					sdumps;
	unsigned int		verbose_level;
	size_t				nb_warriors;
	t_list				*warriors;
	int					ncycles_tmp;
	int					ncycles;
	size_t				totalprocs;
	int					cycle_to_die;
	char				mem[MEM_SIZE];
	char				memcolor[MEM_SIZE];
	WINDOW				*game;
	WINDOW				*log;
	size_t				ncurse_refresh;
	int					debug_mode;
}						t_core;

int						load_champion(t_core *c, char *file, int nb, int color);
int						init_memory(t_core *c);
void					dump_mem(t_core *c);
void					parse_options(t_core *c, int argc, char **argv);
int						ft_isnumber(char *str);
void					ft_double_number(int *champ_numbers, int nb_champ);
char					**ft_tabjoin_str(char ***tab, int length, char *str);
char					**ft_tabjoin_int(int **tab, int length, int nbr);
void					usage(void);
int						init_proc(t_warrior *w, int pc);
int						print_error(char *filename, int code);
unsigned int			int_swap(unsigned int nb);
short					short_swap(short nb);
void					cycles_execution(t_core *c);
void					process_execution(t_core *c, t_proc *process);
void					op_execution(t_core *c, t_proc *process);
int						still_alive(t_core *c);
void					op_functions_init(int (*op_function[17])(t_core*,
						t_proc*, char));
void					inc_pc(t_proc *p, int nb);
int						get_int(t_core *c, t_proc *p);
int						get_int_from(t_core *c, int addr);
short					get_short(t_core *c, t_proc *p);
void					kill_process(t_core *c, t_warrior *w, t_proc *p);
void					write_int(t_core *c, int color, int towrite, int addr);
t_warrior				*get_champ_by_nb(t_core *c, int nb);
int						modulo(int a, int b);
int						init_ncurses(t_core *c);
void					dump_mem_ncurses(t_core *c, WINDOW *win);
int						init_memory_ncurses(t_core *c, t_warrior *w,
						size_t offset);
void					write_at_ncurse(t_core *c, int addr, int color,
						char towrite);
void					update_ncurses(t_core *c);
void					update_pc_ncurses(t_core *c, int old, int pc);
void					refresh_screen(t_core *c);
void					pause_menu(t_core *c);
void					get_out(void);
void					update_screen(t_core *c, int wait);
int						debug_process(t_core *c, int from);
void					display_champ_ncurse(t_core *c, int from);
int						get_lives_by_champ(t_core *c, int nb);
void					verification_cycle(t_core *c, int *nbr_checks);
void					end_game(t_core *c);

/*
** op funcs
*/

int						op_live(t_core *c, t_proc *process, int op_addr);
int						op_ld(t_core *c, t_proc *process, int op_addr);
int						op_st(t_core *c, t_proc *process, int op_addr);
int						op_add(t_core *c, t_proc *process, int op_addr);
int						op_sub(t_core *c, t_proc *process, int op_addr);
int						op_and(t_core *c, t_proc *process, int op_addr);
int						op_or(t_core *c, t_proc *process, int op_addr);
int						op_xor(t_core *c, t_proc *process, int op_addr);
int						op_zjmp(t_core *c, t_proc *process, int op_addr);
int						op_ldi(t_core *c, t_proc *process, int op_addr);
int						op_sti(t_core *c, t_proc *process, int op_addr);
int						op_fork(t_core *c, t_proc *process, int op_addr);
int						op_lld(t_core *c, t_proc *process, int op_addr);
int						op_lldi(t_core *c, t_proc *process, int op_addr);
int						op_lfork(t_core *c, t_proc *process, int op_addr);
int						op_aff(t_core *c, t_proc *process, int op_addr);

typedef struct			s_op_func
{
	int					op_number;
	int					(*f)(t_core *c, t_proc *process, int op_addr);
}						t_op_func;

static const t_op_func	g_op_function[] =
{
	{1, &(op_live)},
	{2, &(op_ld)},
	{3, &(op_st)},
	{4, &(op_add)},
	{5, &(op_sub)},
	{6, &(op_and)},
	{7, &(op_or)},
	{8, &(op_xor)},
	{9, &(op_zjmp)},
	{10, &(op_ldi)},
	{11, &(op_sti)},
	{12, &(op_fork)},
	{13, &(op_lld)},
	{14, &(op_lldi)},
	{15, &(op_lfork)},
	{16, &(op_aff)}
};

static const t_op		g_op_tab[17] =
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

static const char *const g_colors[5] =
{
	"",
	"\033[31m",
	"\033[32m",
	"\033[33m",
	"\033[36m"
};

#endif
