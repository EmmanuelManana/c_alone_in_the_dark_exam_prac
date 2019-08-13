/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 18:59:56 by emanana           #+#    #+#             */
/*   Updated: 2019/08/13 19:44:33 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int match_brackets(char a, char b)
{
	return ((a == '[' && ']' == b) || (a == '{' && '}' == b) || (a == '(' && ')' == b));
}


static int     check_brackets(char *str)
{
	int i;
	int top;
	int stack[4083];

	i = 0;
	top = 0;
	while (str[i])
	{
		if (str[i] == '[' || str[i] == '{' || str[i] == '(')
		{
			top++;
			stack[top] = str[i];
		}
		if (str[i] == ']' || str[i] == '}' || str[i] == ')')
		{
			if (!match_brackets(stack[top--], str[i]))
				return (0);
		}
		i++;
	}
	return (!top);
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
		write(1, "\n", 1);
	while (--argc)
	{
		if (check_brackets(argv[++i]))
		{
			write(1, "OK\n", 3);
		}
		else 
			write(1, "Error\n", 6);
	}
	return (0);
}
