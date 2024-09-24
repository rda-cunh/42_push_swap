/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:59:25 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/24 14:30:48 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//count number of words in the argument provided
static int	count_words(char *str, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			words++;
		while (str[i] && str[i] != sep)
			i++;
	}
	return (words);
}

//copies each number from the arg string to its position in array of strings
static char	*ft_strcpy(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	s1 = (char *)malloc(sizeof(char) * (n + 1));
	if (!s1)
		return (NULL);
	while (s2[i] && i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

//initualize and allocates memory for the array of strings
static char	**res_init(char *str, char sep)
{
	char	**res;

	res = (char **)malloc(sizeof(char *) * (count_words(str, sep) + 2));
	if (!res)
		return (NULL);
	res[0] = ft_strcpy(res[0], "a.out", 5);
	return (res);
}

//split argument provided (str) into an array of strings
char	**split(char *str, char sep)
{
	int		i;
	int		j;
	int		k;
	char	**res;

	i = 0;
	j = 0;
	k = 1;
	res = res_init(str, sep);
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		j = i;
		while (str[i] && str[i] != sep)
			i++;
		if (i > j)
		{
			res[k] = ft_strcpy(res[k], &str[j], i - j);
			k++;
		}
	}
	res[k] = NULL;
	return (res);
}
