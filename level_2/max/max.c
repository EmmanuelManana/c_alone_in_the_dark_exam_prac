/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:09:34 by emanana           #+#    #+#             */
/*   Updated: 2019/07/24 22:23:29 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int             max(int* tab, unsigned int len)
{
	unsigned int res;
	int i;


	res = tab[0];
	i = 0;
	while (i < len)
	{
		if (res < tab[i])
		{
			res = tab[i];
		}
		i++;
	}
	return (res);
}
