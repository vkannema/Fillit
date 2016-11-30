/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:17:26 by vkannema          #+#    #+#             */
/*   Updated: 2016/11/29 13:17:13 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

t_point	*ft_new_point(int x, int y)
{
	t_point *point;

	point = malloc(sizeof(t_point));
	point->x = x;
	point->y = y;
	return (point);
}

t_map	*ft_new_map(int size)
{
	int		i;
	int		j;
	t_map	*map;

	i = 0;
	map = malloc(sizeof(t_map));
	map->size = size;
	map->array = malloc(sizeof(char *) * size);
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

void	ft_print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

t_list	*ft_free_list(t_list *list)
{
	t_etri *tetri;
	t_list *next;

	while (list)
	{
		tetri = (t_etri *)list->content;
		next = list->next;
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void	ft_free_map(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}
