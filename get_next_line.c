/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlobos-m <dlobos-m@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 19:18:27 by dlobos-m          #+#    #+#             */
/*   Updated: 2021/04/22 01:07:02 by dlobos-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

int	print_line(char **file, char **line, int i)
{
	char	*temp;
	int		x;

	if (i == 0 && !file)
	{
		*line = ft_strdup("");
		return (0);
	}
	x = 0;
	temp = 0;
	while ((*file)[x] != '\n' && (*file)[x])
		x++;
	*line = ft_substr(*file, 0, x);
	if ((*file)[x] == '\n')
		temp = ft_strdup(ft_strchr(*file, '\n') + 1);
	free(*file);
	*file = temp;
	if (!temp)
		return (0);
	else
		return (1);
}

int	get_next_line(int fd, char **line)
{
	int			i;
	static char	*file[4096];
	char		*temp;
	char		buf[1 + 1];

	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, 1);
		if (i < 0)
			return (-1);
		buf[i] = '\0';
		if (file[fd] == NULL)
			file[fd] = ft_strdup("");
		temp = ft_strjoin(file[fd], buf);
		free(file[fd]);
		file[fd] = temp;
		if (ft_strchr(file[fd], '\n'))
			break ;
	}
	return (print_line(&file[fd], line, i));
}
