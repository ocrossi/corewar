/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   compute_param.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 15:51:33 by kgrosjea     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 12:37:17 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

static t_bool	valid_arg_type(t_arg_type type, const char *name,
											int arg, t_data **data)
{
	int i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (!ft_strcmp(name, g_op_tab[i].name))
		{
			if ((g_op_tab[i].param_type[arg] & type) > 0)
				return (TRUE);
			else
				error_exit(ft_sprintf("Invalid parameter %d type %s for \
instruction %s", arg, param_type(type), name), data);
		}
		i++;
	}
	error_exit(ft_sprintf("Invalid instruction %s", name), data);
	return (FALSE);
}

static void		set_reg_param(t_param **param, t_data **data,
								t_command *command, int arg)
{
	if (valid_arg_type(T_REG, command->op, arg, data))
	{
		(*param)->type = T_REG;
		(*param)->code = REG_CODE;
		(*param)->size = 1;
	}
}

static void		set_dir_param(t_param **param, t_data **data,
								t_command *command, int arg)
{
	if (valid_arg_type(T_DIR, command->op, arg, data))
	{
		if ((*param)->str[1] == LABEL_CHAR &&
			!label_exists((*param)->str + 2, (*data)->champ->command_list))
			error_exit(ft_sprintf("Label doesn't exist : %s",
									(*param)->str + 2), data);
		(*param)->type = T_DIR;
		(*param)->code = DIR_CODE;
		(*param)->size = op_dir_size(command->op) ? 2 : 4;
	}
}

static void		set_ind_param(t_param **param, t_data **data,
								t_command *command, int arg)
{
	if (valid_arg_type(T_IND, command->op, arg, data))
	{
		if ((*param)->str[0] == LABEL_CHAR &&
			!label_exists((*param)->str + 1, (*data)->champ->command_list))
			error_exit(ft_sprintf("Label doesn't exist : %s",
									(*param)->str + 1), data);
		(*param)->type = T_IND;
		(*param)->code = IND_CODE;
		(*param)->size = 2;
	}
}

void			compute_param(t_param *param, t_data **data,
								t_command *command, int arg_pos)
{
	if (ft_strlen(param->str) > 0)
	{
		if (param->str[0] == 'r' &&
			ft_strlen(param->str) > 1 &&
			ft_strlen(param->str) < 4 &&
			str_only_ctn(param->str + 1, "0123456789"))
			set_reg_param(&param, data, command, arg_pos);
		else if (param->str[0] == DIRECT_CHAR && ft_strlen(param->str) > 1 &&
			((param->str[1] == LABEL_CHAR && ft_strlen(param->str) > 2) ||
			(param->str[1] == '-' && ft_strlen(param->str) > 2 &&
			str_only_ctn(param->str + 2, "0123456789")) ||
			str_only_ctn(param->str + 1, "0123456789")))
			set_dir_param(&param, data, command, arg_pos);
		else if ((param->str[0] == LABEL_CHAR && ft_strlen(param->str) > 1) ||
			(param->str[0] == '-' && ft_strlen(param->str) > 1 &&
			str_only_ctn(param->str + 1, "0123456789")) ||
			str_only_ctn(param->str, "0123456789"))
			set_ind_param(&param, data, command, arg_pos);
		else
			error_exit(ft_sprintf("Invalid parameter : %s", param->str), data);
	}
	else
		error_exit(ft_sprintf("A parameter is missing !"), data);
}
