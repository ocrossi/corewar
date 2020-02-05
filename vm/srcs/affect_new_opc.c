/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   affect_new_opc.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/08 17:45:00 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 16:25:49 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	affect_new_opc(t_process *proc, t_data *data)
{
	if (data->arena[proc->pc] >= 0x01 && data->arena[proc->pc] <= 0x10)
	{
		proc->opc_curr = data->arena[proc->pc];
		proc->cycle = g_op_tab[proc->opc_curr - 1].cycles;
		affect_new_ocp(proc, data);
		return ;
	}
	proc->to_move = FALSE;
	proc->valid_op = FALSE;
	proc->opc_curr = 0;
	proc->cycle = 1;
}
