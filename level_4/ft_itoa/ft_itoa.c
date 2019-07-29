/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:24:36 by emanana           #+#    #+#             */
/*   Updated: 2019/07/29 17:04:03 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int 		ft_itoa_len(int number)
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
		number = number /10;
		length++;
	}
	return (length);
}

char 		*ft_itoa(int nbr)
{
	char *str;
	int len;
	int temp;
	
	if (nbr == -2147483648)
		return ("-2147483648");
	temp = nbr;
	len = ft_itoa_len(nbr);
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	len--;
	str[len] = '\0';
	if (temp == 0)
		str[0] = '0';
	if (temp < 0)
	{
		str[0] = '-';
		temp = temp * -1;
	}
	while (temp)
	{
		str[len] = (temp % 10) + '0';
		temp = temp/10;
		len--;
	}
	return (str);
}

int 		ft_atoi(char *str)
{
	int i;
	
	i = 0;
	while (*str)
	{
		i = (i * 10) + (*str - '0');
		str++;
		ft_atoi(str);
	}
	return (i);
}

int		main(int argc, char **argv)
{
	char *str;

	(void)argc;
	str = ft_itoa(atoi(argv[1]));
	puts(str);
	return (0);
}
