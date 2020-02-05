/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   indirect_load.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 11:11:19 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 12:29:04 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static void	print_verbose(t_process *proc, int verbose, int pos)
{
	if (verbose & VERBOSE_SHOW_OPERATIONS)
	{
		ft_printf("P %4d | ldi %d %d r%hhd\n", proc->id, proc->param_value[0],
								proc->param_value[1], (char)proc->param[2]);
		print_space_for_indirect(proc->id);
		ft_printf("| -> load from %d + %d = %d (with pc and mod %d)\n",
				proc->param_value[0], proc->param_value[1],
				proc->param_value[0] + proc->param_value[1], proc->pc + pos);
	}
}

void		indirect_load(t_process *proc, t_data *data, int verbose)
{
	int pos;

	get_params(data, proc);
	if (!compute_params(data, proc))
		return ;
	pos = (proc->param_value[0] + proc->param_value[1]) % IDX_MOD;
	ft_memcpy_memsize(&(proc->param_value[2]), &data->arena,
				(proc->pc + pos) % MEM_SIZE, 4);
	proc->param_value[2] = unsigned_int_reverse_octet(proc->param_value[2]);
	proc->reg[proc->param[2] - 1] = proc->param_value[2];
	print_verbose(proc, verbose, pos);
}
