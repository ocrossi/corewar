/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   corewar.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/26 11:46:08 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 14:06:35 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
** print_the_winner ecrit le nom du vainqueur
*/

static void	print_the_winner(t_data data)
{
	if (data.last_player_alive == -1)
	{
		ft_printf("Contestant %d, \"%s\", has won !\n",
			data.nb_champ,
			data.champs_data[data.nb_champ - 1].prog_name);
	}
	else
	{
		ft_printf("Contestant %d, \"%s\", has won !\n",
			data.last_player_alive + 1,
			data.champs_data[data.last_player_alive].prog_name);
	}
}

/*
** dump_zero est une petite fonction au cas ou le dump de memoire
** doit se faire au tour zero
*/

static void	dump_zero(t_data data)
{
	if (data.dump == 0)
	{
		ft_hexdump(data.arena, MEM_SIZE);
		clean_list(data.pchain);
		exit(0);
	}
}

/*
** intro_player appele chaque champion pour leur phrase d'introduction
*/

static void	intro_player(t_header dchamps[], unsigned int nb_player)
{
	unsigned int i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < nb_player)
	{
		ft_printf("* Player %u, weighing %u bytes, \"%s\" (\"%s\") !\n", i + 1,
			dchamps[i].prog_size, dchamps[i].prog_name, dchamps[i].comment);
		i++;
	}
}

/*
** set_data permet de donné des valeurs par default
** à la structure data nommé data
*/

static void	set_data(t_data *data, t_option arg_data)
{
	ft_bzero(data, sizeof(t_data));
	data->dump = arg_data.dump;
	data->verbose = (arg_data.verbose != -1) ? arg_data.verbose : 32;
	data->visu = arg_data.visu;
	data->a = arg_data.a;
	data->nb_champ = arg_data.nb_champ;
	data->living_process = arg_data.nb_champ;
	data->ids_process = arg_data.nb_champ;
	data->cycle_to_die = CYCLE_TO_DIE;
	data->last_player_alive = -1;
	process_champ(&arg_data, &data->champs_data, data->arena);
	ft_memcpy(&data->n, arg_data.n, sizeof(arg_data.n));
	generate_process_list(data, 0);
}

/*
** le main du programme
*/

int			main(int ac, char **av)
{
	t_data		data;
	t_option	arg_data;

	process_arg(&arg_data, ac - 1, &av[1]);
	set_data(&data, arg_data);
	if (data.visu && !init_sdl(av[0]))
	{
		clean_list(data.pchain);
		f_error(4);
		return (0);
	}
	data.visu ? init_foot_print(&data) : 0;
	intro_player(data.champs_data, data.nb_champ);
	dump_zero(data);
	cycle(&data);
	if (data.cycle != data.dump + 1)
		print_the_winner(data);
	if (data.visu)
		quit_sdl();
	return (0);
}
