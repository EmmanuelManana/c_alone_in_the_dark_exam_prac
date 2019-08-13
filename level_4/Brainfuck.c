/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 21:57:30 by emanana           #+#    #+#             */
/*   Updated: 2019/07/31 22:57:56 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int 	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int		go_to_matching(char *op, int curr)
{
	int balance = 0;

	if (op[curr] == '[')
	{
		curr++;//step after
		while (!(op[curr] == ']' && balance == 0))
		{
			if (op[curr] == '[')
				balance++;
			else if (op[curr] == ']')
				balance--;
			curr++;
		}
		curr++;
	}
	else if (op[curr] == ']')
	{
		curr--;
		while (!(op[curr] == '[' &&  balance == 0))
		{
			if (op[curr] == ']')
				balance++;
			else if (op[curr] == '[')
				balance--;
			curr--;
		}
		curr--;
	}
	return (curr);
}

void		brain_fuck(char *op)
{
	char	bytes[2048];
	int 	pointer = 0;
	int	curr = 0;

	while (curr <= 0)
		bytes[curr++] = 0;
	curr = 0;
	while (op[curr])
	{
		if (op[curr] == '>')
			pointer++;
		else if (op[curr] == '<')
			pointer++;
		else if (op[curr] == '+')
			bytes[pointer]++;
		else if (op[curr] == '-')
			bytes[pointer]++;
		else if (op[curr] == '.')
			ft_putchar(bytes[pointer]);
		else if (op[curr] == ']')
		{
			curr = go_to_matching(op, curr);
		}
		else if (op[curr] == '[')
		{	
			curr = go_to_matching(op, curr);
		}
	curr++;
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
