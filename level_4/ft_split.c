/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emanana <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 23:35:10 by emanana           #+#    #+#             */
/*   Updated: 2019/08/07 23:58:51 by emanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char 	**ft_split(char *str)
{
	char **split;
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	split = NULL;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	if (!(split == (char**)malloc(sizeof(char*) * 256)))
		return (NULL);
	while (str[i])
	{
		j = 0;
		if (!(split[k] = (char*)malloc(sizeof(char) * 1000)))
			return (NULL);
		while (str[i] != ' ' && str[i] && str[i] != '\t'  && str[i] != '\n')
			split[k][j++] = str[i++];
		while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
			i++;
		split[k][j] = '\0';
		k++;
	}
	split[k] = NULL;
	return (split);
}











