/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 14:53:06 by vkannema          #+#    #+#             */
/*   Updated: 2016/11/29 15:23:52 by bbrandt          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

void	ft_min_max(t_point *min, t_point *max, char *grid)
{
	int	i;

	i = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '#')
		{
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
		}
		i++;
	}
}

t_etri	*ft_put_tetri(char *grid, char letter)
{
	t_point *min;
	t_point *max;
	char	**pos;
	int		i;
	t_etri	*tetri;

	i = 0;
	min = ft_new_point(3, 3);
	max = ft_new_point(0, 0);
	ft_min_max(min, max, grid);
	pos = malloc(sizeof(char *) * (max->y - min->y + 1));
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], grid + min->x + (i + min->y) * 5,
				max->x - min->x + 1);
		i++;
	}
	tetri = ft_new_tetri(max->x - min->x + 1, max->y - min->y + 1, pos, letter);
	return (tetri);
}

int		ft_check_tetri(char *grid)
{
	int i;
	int bloc;

	i = 0;
	bloc = 0;
	while (grid[i])
	{
		if (grid[i] == '#')
		{
			if (grid[i + 1] == '#')
				bloc++;
			if (grid[i + 5] == '#')
				bloc++;
			if (grid[i - 1] == '#')
				bloc++;
			if (grid[i - 5] == '#')
				bloc++;
		}
		i++;
	}
	if (bloc != 6 && bloc != 8)
		return (0);
	return (1);
}

int		ft_check_grid(char *grid, int count)
{
	int i;
	int bloc;

	bloc = 0;
	i = 0;
	while (i <= 21 || grid[i] != '\0')
	{
		if (grid[i] == '.')
			bloc = bloc + 21;
		if (grid[i] == '#')
			bloc--;
		i++;
	}
	if (bloc != 248 || ft_check_tetri(grid) == 0)
		return (0);
	i = 4;
	while (i <= 21)
	{
		if (grid[i] != '\n')
			return (0);
		i = i + 5;
	}
	if (count == 21 && grid[20] != '\n')
		return (0);
	return (1);
}

t_list	*ft_read_and_check(int fd)
{
	char	*buf;
	int		count;
	t_list	*list;
	char	letter;

	letter = 'A';
	list = NULL;
	buf = ft_strnew(21);
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (ft_check_grid(buf, count) == 0)
		{
			ft_memdel((void **)&buf);
			ft_free_list(list);
			return (NULL);
		}
		ft_lstadd(&list, ft_lstnew(ft_put_tetri(buf, letter), sizeof(t_etri)));
		letter++;
	}
	if (count != 0)
		return (ft_free_list(list));
	ft_memdel((void **)&buf);
	ft_lstrev(&list);
	return (list);
}
