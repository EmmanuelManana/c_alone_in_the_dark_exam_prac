/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 06:47:16 by emanana           #+#    #+#             */
/*   Updated: 2019/08/01 07:14:27 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void		fprime(char *str)
{
	int 	div;
	int number;

	div = 2;
	number = atoi(str);
	if (number == 1)
		printf("1");
	if (number <= 0)
		return ;
	while (div <= number)
	{
		if (number % div == 0)
		{
			printf("%d", div);
			if (number == div)
				return ;
			printf("*");
			number = number/div;
			div = 1;
		}
		div++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fprime(argv[1]);
	printf("\n");
	return (0);
}
