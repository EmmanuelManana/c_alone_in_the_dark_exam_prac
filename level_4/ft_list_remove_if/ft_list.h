/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 07:53:12 by emanana           #+#    #+#             */
/*   Updated: 2019/08/08 07:56:52 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LIST_H_
# define _FT_LIST_H_
# include <unistd.h>

typedef struct s_list
{
	struct s_list *next;
	void		*data;

}		t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
#endif 
