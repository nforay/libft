/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:48:11 by nforay            #+#    #+#             */
/*   Updated: 2019/12/04 17:59:04 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	splitnbr(const char *str, char c)
{
	size_t	i;
	size_t	score;
	size_t	j;

	i = -1;
	score = 0;
	while (str[++i])
	{
		if (ft_strchr(&c, str[i]))
			continue ;
		j = i + 1;
		while (!(ft_strchr(&c, str[j])) && str[j])
			j++;
		score++;
		if (str[(i = j)] == '\0')
			return (score);
	}
	return (score);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**splitted;
	size_t	n;

	if (!s || !c)
		return (NULL);
	if (!(splitted = ft_calloc(splitnbr(s, c) + 1, sizeof(splitted))))
		return (NULL);
	n = 0;
	i = -1;
	while (s[++i])
		if (!(ft_strchr(&c, s[i])) && s[(i)] != '\0')
		{
			j = i + 1;
			while (!(ft_strchr(&c, s[j])))
				j++;
			splitted[n++] = ft_substr(s, i, j - i);
			i = (j - 1);
		}
    splitted[n] = NULL;
    return (splitted);
}
