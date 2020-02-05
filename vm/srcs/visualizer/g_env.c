/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   g_env.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: matheme <matheme@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/23 17:44:55 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/23 17:45:25 by matheme     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "visu_corewar.h"

t_env	*g_env(t_env *env_src)
{
	static t_env *env = NULL;

	if (env == NULL)
		env = env_src;
	return (env);
}
