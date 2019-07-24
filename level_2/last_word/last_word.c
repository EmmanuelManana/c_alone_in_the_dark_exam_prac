/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 22:28:45 by emanana           #+#    #+#             */
/*   Updated: 2019/07/24 22:37:26 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		last_word(char *str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		if ((str[i] == ' ' || str[i] == '\t') &&
			(str[i + 1] >= 33 && str[i + 1] <= 127))
		{
			j = i + 1;
		}
		i++;
	}
	while (str[j] >= 33 && str[j] <= 127)
	{
		write(1, &str[j], 1);
		j++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
