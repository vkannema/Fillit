/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 16:19:43 by vkannema          #+#    #+#             */
/*   Updated: 2016/11/29 13:17:27 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int		ft_valid_place(t_map *map, t_etri *tetri, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (map->array[y + j][x + i] != '.' && tetri->array[j][i] == '#')
				return (0);
			j++;
		}
		i++;
	}
	ft_insert_piece(map, tetri, tetri->letter, ft_new_point(x, y));
	return (1);
}

void	ft_insert_piece(t_map *map, t_etri *tetri, char letter, t_point *point)
{
	int	i;
	int	j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->array[j][i] == '#')
				map->array[point->y + j][point->x + i] = letter;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&point);
}

int		ft_backtracking(t_map *map, t_list *list)
{
	t_etri	*tetri;
	int		x;
	int		y;

	if (list == NULL)
		return (1);
	tetri = (t_etri *)(list->content);
	y = 0;
	while (y <= map->size - tetri->height)
	{
		x = 0;
		while (x <= map->size - tetri->width)
		{
			if (ft_valid_place(map, tetri, x, y) == 1)
			{
				if (ft_backtracking(map, list->next) == 1)
					return (1);
				else
					ft_insert_piece(map, tetri, '.', ft_new_point(x, y));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_high_sqrt(int n)
{
	int i;

	i = 2;
	while (i * i < n)
		i++;
	return (i);
}

void	ft_solve(t_list *list)
{
	int		size;
	t_map	*map;

	size = ft_high_sqrt((ft_lstlen(list) - 1) * 4);
	map = ft_new_map(size);
	while (ft_backtracking(map, list) == 0)
	{
		size++;
		ft_free_map(map);
		map = ft_new_map(size);
	}
	ft_print_map(map);
	ft_free_map(map);
}
