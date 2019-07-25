/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 08:24:55 by emanana           #+#    #+#             */
/*   Updated: 2019/07/25 08:37:14 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_atoi(char *str)
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
void		print_hex(int n)
{
	if (n >= 16)
		print_hex( n / 16);
	else if ((n % 16) < 10)
		ft_putchar((n % 16) + 48);
	else
		ft_putchar((n % 16) - 10 + 97);
}

int	main(void)
{
	print_hex(10);
	return (0);
}
