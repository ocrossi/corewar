/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aff.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 11:14:47 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 16:25:02 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	aff(t_process *process, t_data *data, int verbose)
{
	char r1;
	char c;

	ft_memcpy_memsize(&r1, &data->arena, process->pc + 2, 1);
	(void)verbose;
	if (data->a && r1 > 0 && r1 < 17)
	{
		ft_printf("Aff: ");
		c = process->reg[r1 - 1] % 256;
		write(1, &c, 1);
		ft_printf("\n");
	}
}
