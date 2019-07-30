/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:51:05 by emanana           #+#    #+#             */
/*   Updated: 2019/07/30 13:08:57 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

char 	is_space(char c)
{
	return (c == ' ' || c == '\t');
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void		rev_wstr(char *str)
{
	int		length;
	int		current;
	int		keep; 

	length = ft_strlen(str) - 1;
	current = length;
	keep = length;
	while (length >= 0)
	{
		keep = length;
		current = length;
		while (length >= 0 && !is_space(str[length]))
		{
			length--;
		}
		length++;
		current = length;
		while (current <= keep)
		{
			ft_putchar(str[current]);
			current++;
		}
		if (length > 0)
			ft_putchar(' ');
		length--;
		length--;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		rev_wstr(argv[1]);
	ft_putchar(10);
	return (0);
}
