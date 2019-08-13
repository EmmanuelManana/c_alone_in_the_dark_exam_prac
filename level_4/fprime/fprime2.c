/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 07:32:03 by emanana           #+#    #+#             */
/*   Updated: 2019/08/08 07:47:41 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void		fprime(int number)
{
	int div;

	div = 2;
	if (number == 1)
		printf("1");
	else if (number <= 0)
		return ;
	while (number >= div)
	{
		if (number % div == 0)
		{
			printf("%d", div);
			if (number == div)
				return ;
			printf("*");
			number = number /div;
			div = 1;
		}
		div++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
