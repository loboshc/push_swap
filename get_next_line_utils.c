/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:11:19 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/19 19:17:59 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	unsigned long	i;
	const char		*cad;

	i = 0;
	cad = s;
	while (cad[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*pnt;
	int		i;
	int		j;
	int		x;

	if (!(s1 && s2))
		return (NULL);
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	pnt = (char *)malloc((i + j + 1) * sizeof(*pnt));
	if (pnt == NULL)
		return (NULL);
	x = 0;
	while (*s1)
	{
		pnt[x] = *s1++;
		x++;
	}
	while (*s2)
	{
		pnt[x] = *s2++;
		x++;
	}
	pnt[x] = '\0';
	return (pnt);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*cad;
	char	car;

	i = 0;
	cad = (char *)s;
	car = (char)c;
	while (cad[i] != car && cad[i] != '\0')
		i++;
	if (cad[i] == car)
		return (cad + i);
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*pnt;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	pnt = (char *)malloc((len + 1) * sizeof(char));
	if (pnt == NULL)
		return (NULL);
	if (!(start > strlen(s)))
	{
		while (j < len)
		{
			pnt[j] = s[i + start];
			i++;
			j++;
		}
	}
	pnt[j] = '\0';
	return (pnt);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*pnt;

	i = 0;
	while (s[i] != '\0')
		i++;
	i += 1;
	pnt = malloc(i * sizeof(char));
	if (pnt == NULL)
		return (NULL);
	while (i-- > 0)
		pnt[i] = s[i];
	return (pnt);
}
