/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op_infos.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/03 11:37:55 by kgrosjea     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/18 10:44:04 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

t_bool	op_exist(const char *name)
{
	int i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(name, g_op_tab[i].name))
			return (TRUE);
		i++;
	}
	return (FALSE);
}

t_bool	op_dir_size(const char *name)
{
	int i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(name, g_op_tab[i].name))
			return (g_op_tab[i].dir_size);
		i++;
	}
	return (FALSE);
}

t_bool	op_has_ocp(const char *name)
{
	int i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(name, g_op_tab[i].name))
			return (g_op_tab[i].ocp);
		i++;
	}
	return (FALSE);
}

int		op_param_count(const char *name)
{
	int i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(name, g_op_tab[i].name))
			return (g_op_tab[i].param_count);
		i++;
	}
	return (0);
}

int		op_code(const char *name)
{
	int i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(name, g_op_tab[i].name))
			return (g_op_tab[i].code);
		i++;
	}
	return (0);
}
