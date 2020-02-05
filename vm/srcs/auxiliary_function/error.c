/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   error.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/30 08:37:24 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 12:30:36 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
** indique comment utilisé le programme corewar
*/

void		usage(void)
{
	ft_printf("usage: ./corewar [-vg] [-d nbr_cycles][-n number]\
champion.cor (Max: 4)\n");
	exit(0);
}

/*
** fonction de gestion des erreurs
*/

static void	ft_strerror(int err_nb)
{
	const char *tab[] = {
		"malloc crashed\n", "a file is not a corewar_champs\n",
		"a corewar_champs is too big\n", "a corewar_champs is corrupt\n",
		"impossible to load corewar_assets\n"
	};

	ft_putstr(tab[err_nb]);
}

void		f_error(int err_nb)
{
	ft_strerror(err_nb);
	exit(0);
}
