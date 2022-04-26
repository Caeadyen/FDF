/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:50:33 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 09:57:11 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <libft.h>
#include <fcntl.h>

int	readmap(t_fdf *fdf)
{
	t_list	*head;
	int		fd;

	fd = open(fdf->filename, O_RDONLY);
	if (fd < 0)
	{
		perror(fdf->filename);
		return (1);
	}
	head = readfile(fdf, fd);
	if (!head)
		return (1);
	fdf->minz = 0;
	fdf->maxz = 0;
	buildmap(fdf, head);
	return (0);
}

t_list	*readfile(t_fdf *fdf, const int fd)
{
	char	*line;
	t_list	*head;
	t_list	*current;
	int		tmp;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	fdf->column = columnlength(line);
	head = ft_lstnew(line);
	line = get_next_line(fd);
	while (line)
	{
		tmp = columnlength(line);
		if (tmp < fdf->column)
			fdf->column = tmp;
		current = ft_lstnew(line);
		ft_lstadd_back(&head, current);
		line = get_next_line(fd);
	}
	close(fd);
	return (head);
}
