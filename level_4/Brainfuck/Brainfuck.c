/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 23:11:11 by emanana           #+#    #+#             */
/*   Updated: 2019/08/06 17:42:29 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>


void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		brain_fuck(char *str)
{
	int i;
	char *ptr;

	i = 0;
	ptr = (char*)malloc(sizeof(char) * 2048);
	while (str[i])
	{
		/*incremet & decrement the pointer if '>/<' = str[ii*/
		*ptr += str[i] == '+' ? 1 : 0;
		*ptr -= str[i] == '-' ? 1 : 0;
		/*incre/decre the pointed byte*/
		ptr += str[i] == '>' ? 1 : 0;
		ptr -= str[i] == '<' ? 1 : 0;
		if (str[i] == '[' && *ptr == 0)
			while (str[i] != ']')
				i++;/*look to the right to find a match*/
		else if (str[i] == ']' && *ptr != 0)
			while (str[i] != '[')
				i--;/*look to the left to find a match*/
		else if (str[i] == '.')
			ft_putchar(*ptr);
		i++;
	}
}
int		main(int argc, char **argv)
{
	if (argc == 2)
		brain_fuck(argv[1]);
	else
		ft_putchar(10);
	return (0);
}
	
