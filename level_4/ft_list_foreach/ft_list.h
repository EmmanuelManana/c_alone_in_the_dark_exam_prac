/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 07:41:22 by emanana           #+#    #+#             */
/*   Updated: 2019/08/01 07:43:25 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_LIST_H_
# define _FT_LIST_H_
typedef struct  	  	s_list
{
	struct s_list 		*next;
	void          		*data;
}                 		t_list;


void    			ft_list_foreach(t_list *begin_list, void (*f)(void *));
#endif 
