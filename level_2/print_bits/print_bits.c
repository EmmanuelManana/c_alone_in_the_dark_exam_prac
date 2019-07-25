/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 03:56:31 by emanana           #+#    #+#             */
/*   Updated: 2019/07/25 04:12:59 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int res;
	res = 0;
	while (*str)
	{
		res = (res * 10) + (*str - '0');
		str++;
		ft_atoi(str);
	}
	return (res);
}
void		ft_putchar(char c)
{
	write(1, &c, 1);
}
void		print_bits(unsigned char octet)
{
	int	counter;
	int	bits[8];
	int	num;
	int	z;

	num = octet;
	counter = 0;
	while (counter < 8)
	{
		bits[counter] = num % 2;
		num = num / 2;
		counter++;
	}
	counter--;
	while (counter >= 0)
	{
		z = bits[counter] + '0';
		ft_putchar(z);
		counter--;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		print_bits(ft_atoi(argv[1]));
	ft_putchar(10);
	return (0);
}
