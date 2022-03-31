/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgerace <sgerace@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 15:32:56 by sgerace           #+#    #+#             */
/*   Updated: 2022/03/31 18:13:16 by sgerace          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_w(char const *s, char c)
{
	int	num;
	int	index;

	num = 0;
	index = 0;
	while (*s)
	{
		if (ft_strchr(s, c) && index == 0)
		{
			index = 1;
			num++;
		}
		else
			index = 0;
		s++;
	}
	return (num);
}

char	*actually_fill_matrix(char const *s, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *) malloc(sizeof(char *) * (finish - start + 1));
	if (!word)
		return (NULL);
	word[finish - start + 1] = '\0';
	while (start < finish)
		word[i++] = s[start++];
	return (word);
}

char	**fill_matrix(char const *s, char c, char **matrix, int len)
{
	int	i;
	int	j;
	int	index;

	i = 0;
	j = 0;
	index = -1;
	while (i < len)
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == len) && index >= 0)
		{
			matrix[j++] = actually_fill_matrix(s, index, i);
			index = -1;
		}
		i++;
	}
	return (matrix);
}

char	**ft_split(char const *s, char c)
{
	int		len;
	char	**matrix;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	matrix = (char **) malloc(sizeof(char *) * (count_w(s, c) + 1));
	if (!matrix)
		return (NULL);
	return (fill_matrix(s, c, matrix, len));
}
