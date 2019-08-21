/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rpn_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 18:27:22 by emanana           #+#    #+#             */
/*   Updated: 2019/08/21 19:02:26 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define ERROR -1
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int		check_num(char *str)
{
	int 	i;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] >= '0' && '9' >= str[i])
		return (1);
	return (0);
}

int 		check_op(char op)
{
	return (op == '/' || op == '+' || op == '*' || op == '%' || op == '-');
}

int		operate(int a, int b, char op)
{
	if (op == '+')
		return (a + b);
	if (op == '-')
		return (a - b);
	if (op == '*')
		return (a * b);
	if (op == '/')
	{
		if (b == 0)
			return (ERROR);
		return (a / b);
	}
	if (op == '%')
	{
		if (b == 0)
			return (ERROR);
		return (a % b);
	}
	return (ERROR);
}

int		rpn_calc(char *str, int *stack)
{
	int	i;
	int 	top;

	i = 0;
	top = -1;
	while (str[i] != '\0')
	{
		if (check_num(&str[i]))
		{
			top++;
			stack[top] = atoi(&str[i]);
			/*   str[i + 1] != '\0';*/ 
			while (str[i] != ' ' && str[i + 1] != '\0')
				i++;
		}
		if (check_op(str[i]))
		{
			if (top > 0)
			{
				if ((stack[top - 1] = operate(stack[top - 1], stack[top], str[i])) == 						ERROR)
					return (write(1, "Error\n", 6));
				top--;
			}
			else 
				return (write(1, "Error\n", 6));
		}
		i++;
	}
	if (top == 0)
		printf("%i\n", stack[top]);
	else
		write(1, "Error\n", 6);
	return (0);
}

int		main(int argc, char **argv)
{
	int stack[512];

	if (argc == 2)
		rpn_calc(argv[1], stack);
	else
		write(1, "Error\n", 6);
	return (0);
}
