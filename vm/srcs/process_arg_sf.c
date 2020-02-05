/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_arg_sf.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/09/27 13:28:58 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 18:32:58 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
** get_value_for reçois l'argument actuel à traiter et la traite comme étant
** unt nombre.
** la fonction verifie le max && min int et stock la valeur au bonne endroit
** dans la struct arg_data.
** modifie: l'expected_arg
*/

void		get_value_for(char *str, t_option *data)
{
	long	val;
	int		i;

	i = -1;
	val = ft_atol(str);
	if (((val < 0 || val > 2147483647) && data->expected_arg == 2) ||
		((val < 0 || val > 31) && data->expected_arg == 3) ||
		((val <= 0 || val > 4294967295) && data->expected_arg == 1))
		data->expected_arg = -1;
	if (data->expected_arg == 1)
	{
		if (data->nb_champ >= MAX_PLAYERS && (data->expected_arg = -1))
			return ;
		while (++i < data->nb_champ)
			if (val == data->n[i])
				val = -2;
		data->n[data->nb_champ] = val;
		data->expected_arg = 4;
	}
	else
	{
		data->dump = (data->expected_arg == 2) ? val : data->dump;
		data->verbose = (data->expected_arg == 3) ? val : data->verbose;
		data->expected_arg = (data->expected_arg != -1) ? 0 : -1;
	}
}

/*
** liste des options traiter
** pour rajouter une option il suffit de recopier le patern suivant
** modifie: l'expected_arg
*/

static void	ft_listing_option(char c, char *expected_arg, t_bool *visu,
															t_bool *a)
{
	c == 'g' ? *visu = TRUE : 0;
	c == 'a' ? *a = TRUE : 0;
	c == 'v' ? *expected_arg = 3 : 0;
	c == 'd' ? *expected_arg = 2 : 0;
	c == 'n' ? *expected_arg = 1 : 0;
}

/*
** get_option reçois l'argument actuel à traiter et la traite comme étant
** une option ou des options.
** avance dans la string tant que expected_arg est egal à 0
** et que les differentes options sont connus
*/

void		get_option(char *str, t_option *arg_data)
{
	int i;

	i = 1;
	while (str[i])
	{
		if (ft_strchr(LIST_OPTION, str[i]) == NULL || arg_data->expected_arg)
		{
			arg_data->expected_arg = -1;
			break ;
		}
		ft_listing_option(str[i], &arg_data->expected_arg, &arg_data->visu,
																&arg_data->a);
		i++;
	}
}

/*
** check_champ_path
** verifie que le nom du fichier se termine bien par .cor
*/

static int	check_champ_path(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	if (i <= 4)
		return (0);
	i--;
	if (s[i] != 'r' || s[i - 1] != 'o' || s[i - 2] != 'c' || s[i - 3] != '.')
		return (0);
	return (1);
}

/*
** get_champ eçois l'argument actuel à traiter et la traite comme étant
** un fichier de champion.
** verifie la validiter du fichier (ouverture/lecture)
** et le stock au bonne endroit dans la structure arg_data
** modifie: l'expected_arg
** augmente le nombre de champion de +1
*/

void		get_champ(char *champ_path, t_option *arg_data)
{
	if (!check_champ_path(champ_path))
	{
		arg_data->expected_arg = -1;
		return ;
	}
	if (arg_data->nb_champ >= MAX_PLAYERS)
	{
		arg_data->expected_arg = -1;
		return ;
	}
	arg_data->fd[arg_data->nb_champ] = open(champ_path, O_RDONLY);
	if (arg_data->fd[arg_data->nb_champ] != -1 &&
		read(arg_data->fd[arg_data->nb_champ], NULL, 0) < 0)
	{
		close(arg_data->fd[arg_data->nb_champ]);
		arg_data->expected_arg = -1;
		return ;
	}
	arg_data->nb_champ += 1;
	arg_data->expected_arg = 0;
}
