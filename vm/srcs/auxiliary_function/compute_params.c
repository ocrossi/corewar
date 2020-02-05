/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compute_params.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 11:37:15 by kgrosjea     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 18:16:57 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static int		get_index(t_data *data, t_process *proc, int val)
{
	int	res;
	int	pos;

	res = 0;
	if (proc->opc_curr != 10 && proc->opc_curr != 13 && proc->opc_curr != 14)
		val %= IDX_MOD;
	pos = (proc->pc + val) % MEM_SIZE;
	while (pos < 0)
		pos += MEM_SIZE;
	if (proc->opc_curr == 13)
	{
		res |= (unsigned char)data->arena[pos] << 8;
		res |= (unsigned char)data->arena[(pos + 1) % MEM_SIZE];
		if ((unsigned char)data->arena[pos] > 127)
			res += 0xFFFF0000;
	}
	else
	{
		res |= (unsigned char)data->arena[pos] << 24;
		res |= (unsigned char)data->arena[(pos + 1) % MEM_SIZE] << 16;
		res |= (unsigned char)data->arena[(pos + 2) % MEM_SIZE] << 8;
		res |= (unsigned char)data->arena[(pos + 3) % MEM_SIZE];
	}
	return (res);
}

static t_bool	compute_registers(t_process *proc)
{
	int i;

	i = 0;
	while (i < g_op_tab[proc->opc_curr - 1].param_count)
	{
		if (get_param_type(proc->ocp_curr, i + 1) == REG_CODE)
		{
			if (proc->param[i] < 1 || proc->param[i] > REG_NUMBER)
				return (FALSE);
			proc->param_value[i] = proc->reg[proc->param[i] - 1];
		}
		i++;
	}
	return (TRUE);
}

static void		compute_directs(t_process *proc)
{
	int i;

	i = 0;
	while (i < g_op_tab[proc->opc_curr - 1].param_count)
	{
		if (get_param_type(proc->ocp_curr, i + 1) == DIR_CODE)
			proc->param_value[i] = proc->param[i];
		i++;
	}
}

static void		compute_indirects(t_data *data, t_process *proc)
{
	int i;

	i = 0;
	while (i < g_op_tab[proc->opc_curr - 1].param_count)
	{
		if (get_param_type(proc->ocp_curr, i + 1) == IND_CODE)
			proc->param_value[i] = get_index(data, proc, proc->param[i]);
		i++;
	}
}

t_bool			compute_params(t_data *data, t_process *proc)
{
	if (!compute_registers(proc))
		return (FALSE);
	compute_indirects(data, proc);
	compute_directs(proc);
	return (TRUE);
}
