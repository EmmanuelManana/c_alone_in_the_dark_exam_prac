/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_wstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 20:35:35 by emanana           #+#    #+#             */
/*   Updated: 2019/07/31 20:56:18 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int 		is_space(char chr)
{
	return (chr == ' ' || chr == '\t' || chr == '\v');
}
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
void		rev_wstr(char *str)
{
	int 	length;
	int 	current;
	int 	kept;

	length  = ft_strlen(str) - 1;
	current = length;
	kept    = length;
	while (length >= 0)
	{
		current = length;
		kept    = length;
		while ( length >= 0 && !is_space(str[length]))
		{
			length--;
		}
		length++;
		current = length;
		while (current <= kept)
		{
			ft_putchar(str[current]);
			current++;
		}
		if (length >= 0)
			ft_putchar(' ');
		length--;
		length--;
	}
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	rev_wstr("    hello world     ***  )) __:");
	ft_putchar(10);
	return (0);
}
