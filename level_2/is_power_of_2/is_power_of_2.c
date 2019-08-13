/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 04:51:49 by emanana           #+#    #+#             */
/*   Updated: 2019/07/25 05:08:04 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int		is_power_of_2(int n)
{
	if ( n == 0)
		return (0);
	while (n % 2 == 0)
		n = n/2;
	return (n == 1 ? 1 : 0);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		is_power_of_2(atoi(argv[1])) ? puts("yes") : puts("no");
	write(1, "\n", 1);
	return (0);
}
