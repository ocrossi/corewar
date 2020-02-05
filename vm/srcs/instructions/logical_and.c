/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   logical_and.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 18:21:39 by kgrosjea     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 14:31:39 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void		logical_and(t_process *proc, t_data *data, int verbose)
{
	get_params(data, proc);
	if (!compute_params(data, proc))
		return ;
	proc->reg[proc->param[2] - 1] = proc->param_value[0] & proc->param_value[1];
	proc->carry = proc->reg[proc->param[2] - 1] == 0 ? 1 : 0;
	if (verbose & VERBOSE_SHOW_OPERATIONS)
		ft_printf("P %4d | and %d %d r%d\n", proc->id,
			proc->param_value[0], proc->param_value[1], proc->param[2]);
}
