/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 07:55:53 by emanana           #+#    #+#             */
/*   Updated: 2019/07/25 08:20:23 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int 	confirm(char *str, char c, int len)
{
	int i;


	i = 0;
	while (i < len)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}
void		ft_putchar(char c)
{
	write(1, &c, 1);
}
void		ft_union(char *str1, char *str2)
{
	int i;
	int len;

	i = 0;
	while (str1[i])
	{
		if (confirm(str1, str1[i], i) == 1)
			ft_putchar(str1[i]);
		i++;
	}
	len = i;
	i = 0;
	while (str2[i])
	{
		if (confirm(str2, str2[i], i) == 1)
		{
			if (confirm(str1, str2[i], len) == 1)
				ft_putchar(str2[i]);
		}
		i++;
	}
}


int		main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	ft_putchar(10);
	return (0);
}
