/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 10:00:00 by exam              #+#    #+#             */
/*   Updated: 2019/08/02 14:17:22 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int			ft_len(int number)
{
	int length;

	length = 0;
	if (number < 0)
	{
		number = number * -1;
		length++;
	}
	while (number)
	{
		number = number/10;
		length++;
	}
	return (length);
}

void	 ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

char	*ft_itoa(int nbr)
{
	int length;
	long temp;
	char *str;

	length = ft_len(nbr);
	temp = nbr;
	if (!(str = (char*)malloc(sizeof(char) * length + 1)))
		return (NULL);
	str[length] = '\0';
	if (temp == -2147483648)
		return ("-2147483648");
	if (temp == 2147483647)
		return ("2147483647");
	else if (temp == 0)
		str[0] = '0';
	else if (temp < 0)
	{
		str[0] = '-';
		temp = -1 * temp;
	}
	while (temp)
	{
		str[length - 1] = (temp % 10) + 48;
		temp = temp/10;
		length--;
	}
	return (str);
}

int			main(int argc, char **argv)
{
	if (argc == 2)
		ft_putstr(ft_itoa(atoi(argv[1])));
	write(1, "\n", 1);
	return (0);
}
