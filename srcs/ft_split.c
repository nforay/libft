/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:48:11 by nforay            #+#    #+#             */
/*   Updated: 2019/12/03 16:06:34 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	splitnbr(const char *str, char c)
{
	size_t	i;
	size_t	score;
	size_t	j;

	i = 0;
	score = 0;
	while (str[i])
	{
		if (ft_strchr(&c, str[i]))
				i++;
		else
		{
			j = i + 1;
			while (ft_strchr(&c, str[j]) == 0 && str[j] != '\0')
				j++;
			score++;
			if (str[j] == '\0')
				return (score);
			else
				i = j;
		}
	}
	return (score);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**splitted;
	size_t	a;

	a = 0;
	i = 0;
	if (!s || !c)
		return (NULL);
	if (!(splitted = malloc(sizeof(char *) * (splitnbr(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (!(ft_strchr(&c, s[i])))
		{
			j = i + 1;
			while (ft_strchr(&c, s[j]) == 0 && s[j] != '\0')
				j++;
			splitted[a++] = ft_substr(s, i, j - i);
			i = j;
		}
		i++;
	}
    splitted[a] = NULL;
    return (splitted);
}
