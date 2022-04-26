/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:26:18 by hrings            #+#    #+#             */
/*   Updated: 2022/03/02 13:49:24 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	atoi_hex(char *str);
static int	hexvalue(char c);
static void	getintvalues(char **line, t_fdf *fdf, t_altitude *row);
static void	free_line(char **line);

void	buildmap(t_fdf *fdf, t_list *head)
{
	int		row;
	t_list	*current;
	char	**line;

	fdf->row = ft_lstsize(head);
	current = head;
	fdf->map = (t_altitude **) malloc(fdf->row * sizeof(t_altitude *));
	row = 0;
	while (current)
	{
		line = ft_split(current->content, ' ');
		fdf->map[row] = (t_altitude *) malloc(fdf->column * sizeof(t_altitude));
		getintvalues(line, fdf, fdf->map[row++]);
		current = current->next;
		free_line(line);
	}
	ft_lstclear(&head, free);
}

static void	getintvalues(char **line, t_fdf *fdf, t_altitude *row)
{
	int		index;
	char	*colorvalue;

	index = 0;
	while (index < fdf->column)
	{
		row[index].z = atoi(line[index]);
		if (row[index].z < fdf->minz)
			fdf->minz = row[index].z;
		else if (row[index].z > fdf->maxz)
			fdf->maxz = row[index].z;
		colorvalue = ft_strchr(line[index], ',');
		if (colorvalue)
				row[index].color = atoi_hex(colorvalue);
		else
		{
			if (row[index].z == 0)
				row[index].color = 0xFFFFFF;
			else
				row[index].color = 0x999900;
		}
		index++;
	}
}

static int	atoi_hex(char *str)
{
	int	result;

	result = 0;
	if (*str == ',')
		str++;
	if (*str == '0')
		str++;
	if ((*str == 'x') | (*str == 'X'))
		str++;
	while (*str)
	{
		result = (result * 16) + hexvalue(*str);
		str++;
	}
	return (result);
}

static int	hexvalue(char c)
{
	if (c == 'a' || c == 'A')
		return (10);
	else if (c == 'b' || c == 'B')
		return (11);
	else if (c == 'c' || c == 'C')
		return (12);
	else if (c == 'd' || c == 'D')
		return (13);
	else if (c == 'e' || c == 'E')
		return (14);
	else if (c == 'f' || c == 'F')
		return (15);
	return (c - 48);
}

static void	free_line(char **line)
{
	int	index;

	index = 0;
	while (line[index] != NULL)
	{
		free(line[index]);
		index++;
	}
	free(line);
}
