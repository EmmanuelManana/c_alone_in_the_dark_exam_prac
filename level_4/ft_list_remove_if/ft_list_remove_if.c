/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 07:57:22 by emanana           #+#    #+#             */
/*   Updated: 2019/08/08 08:04:18 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list 		*temp;
	t_list		*i;

	while (*begin_list && (*cmp)((*begin_list)->data, data_ref) == 0)
	{
		temp = (*begin_list)
		(*begin_list) = (*begin_list)->next;
		free(temp);
	}
	i = *begin_list;
	while (i && i->next)
	{
		if ((*cmp)(i->next->data, data_ref) == 0)
		{
			temp = i->next;
			i->next = temp->next;
			free(temp);
		}
		if (i->next)
			i = i->next;
	}
}
