/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchAndReplace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 20:47:04 by emanana           #+#    #+#             */
/*   Updated: 2019/07/24 21:50:52 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
void 		ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

char 	  	*search_and_replace(char *str, char s, char r)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == s)
		{
			str[i] = r;
		}
		i++;
	}
	return (str);
}

int	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 4)
		if (ft_strlen(argv[2]) == 1 && ft_strlen(argv[3]) == 1)
		ft_putstr(search_and_replace(argv[1], argv[2][0], argv[3][0]));
	write(1, "\n", 1);
	return (0);
}
