/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:59:25 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/16 23:09:28 by rda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	count_words(char *s, char c)
{
	int		count;
	bool	inside_word;

	count = 0;
	while (*s)
	{
		inside_word = false;
		while (*s == c)
			++s;
		while (*s != c && *s)
		{
			if (!inside_word)
			{
				++count;
				inside_word = true;
			}
			++s;
		}
	}
	return (count);
}

static char	*get_next_word(char *s, char c, int *cursor)
{
	int		len;
	int		i;
	char	*next_word;

	len = 0;
	while (s[*cursor] == c)
		(*cursor)++;
	while (s[*cursor + len] && s[*cursor + len] != c)
		len++;
	next_word = malloc(len + 1);
	if (!next_word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		next_word[i] = s[(*cursor)];
		i++;
		(*cursor)++;
	}
	next_word[i] = '\0';
	return (next_word);
}

static char	**free_result_array(char **result_array, int i)
{
	while (--i >= 0)
		free(result_array[i]);
	free(result_array);
	return (NULL);
}

char	**split(char *s, char c)
{
	int		word_count;
	char	**result_array;
	int		cursor;
	int		i;

	word_count = count_words(s, c);
	if (!s || word_count == 0)
		return (NULL);
	result_array = malloc((word_count + 1) * sizeof(char *));
	if (!result_array)
		return (NULL);
	cursor = 0;
	i = 0;
	while (i < word_count)
	{
		result_array[i] = get_next_word(s, c, &cursor);
		if (!result_array[i])
			return (free_result_array(result_array, i));
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}
