/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nforay <nforay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 23:34:30 by nforay            #+#    #+#             */
/*   Updated: 2019/12/02 22:37:50 by nforay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char 		*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*ptr;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len = ft_strlen(&s1[i]);
	while (len && ft_strchr(set, s1[(i + (len - 1))]))
		len--;
	if (!(ptr = (char*)malloc(len + 1)))
		return (NULL);
	j = 0;
	while (len--)
		{
			ptr[j] = s1[i + j];
			j++;
		}
	ptr[j] = '\0';
	return (ptr);
}
