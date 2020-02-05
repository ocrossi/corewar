/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   clean_process.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kgrosjea <kgrosjea@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/14 15:00:19 by matheme      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/03 12:30:36 by kgrosjea    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

/*
** free_process libere la memoire de 1 proccess
** en faisant appel à ft_memdel
*/

static void		free_process(void *data, size_t data_size)
{
	(void)data_size;
	ft_memdel(&data);
}

static void		kill_one_process(t_list *elem, t_list *prev, t_data **data)
{
	if (!prev)
		(*data)->pchain = elem->next;
	else
		prev->next = elem->next;
	ft_lstdelone(&elem, &free_process);
	(*data)->living_process--;
}

/*
** libere la memoire prise par la liste des process
** a appeler à la fin du programme
*/

void			clean_list(t_list *begin)
{
	void	(*pf)(void*, size_t);

	pf = &free_process;
	ft_lstdel(&begin, pf);
}

/*
** boucle dans la chaine de process et supprime les process
** ou leur valeur 'is_alive' est set à zero
*/

void			kill_dead_process(t_data *data)
{
	t_list		*current;
	t_list		*next;
	t_list		*prev;
	t_process	*proc;

	current = data->pchain;
	prev = NULL;
	while (current)
	{
		next = current->next;
		proc = (t_process *)(current->content);
		if (proc->is_alive == 0 || data->cycle_to_die <= 0)
		{
			if (data->verbose & VERBOSE_SHOW_DEATHS)
				ft_printf("Process %d hasn't lived for %ld cycles (CTD %d)\n",
				proc->id, data->cycle - proc->last_live, data->cycle_to_die);
			kill_one_process(current, prev, &data);
		}
		else
		{
			prev = current;
			proc->is_alive = 0;
		}
		current = next;
	}
}
