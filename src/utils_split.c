/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rda-cunh <rda-cunh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:59:25 by rda-cunh          #+#    #+#             */
/*   Updated: 2024/09/14 02:03:46 by rda-cunh         ###   ########.fr       */
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
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[*cursor] == c)
		++(*cursor);
	while ((s[*cursor + len] != c) && s[*cursor + len])
		++len;
	next_word = malloc((size_t)(len + 1) * sizeof(char));
	if (next_word == NULL)
		return (NULL);
	while ((s[*cursor] != c) && s[*cursor])
		next_word[i++] = s[(*cursor)++];
	next_word[i] = '\0';
	return (next_word);
}

static char	**allocate_result_array(int word_count)
{
	char	**result_array;

	result_array = malloc(sizeof(char *) * (size_t)(word_count + 1));
	if (result_array == NULL)
		return (NULL);
	return (result_array);
}

static void	free_memory(char **result_array, int i)
{
	while (i-- > 0)
	{
		free(result_array[i]);
		result_array[i] = NULL;
	}
	free(result_array);
}

char	**split(char *s, char c)
{
	int		word_count;
	char	**result_array;
	int		i;
	int		cursor;

	if (s == NULL)
		return (NULL);
	i = 0;
	cursor = 0;
	word_count = count_words(s, c);
	if (word_count == 0)
		return (NULL);
	result_array = allocate_result_array(word_count);
	while (i < word_count)
	{
		result_array[i] = get_next_word(s, c, &cursor);
		if (result_array[i] == NULL)
		{
			free_memory(result_array, i);
			return (NULL);
		}
		i++;
	}
	result_array[i] = NULL;
	return (result_array);
}
