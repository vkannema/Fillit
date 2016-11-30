/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:46:36 by vkannema          #+#    #+#             */
/*   Updated: 2016/11/29 13:17:50 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../Library/libft.h"
# include <fcntl.h>
# define BUF_SIZE 546

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_tetri
{
	char		**array;
	int			height;
	int			width;
	char		letter;
}				t_etri;

typedef struct	s_map
{
	char		**array;
	int			size;
}				t_map;

t_list			*ft_read_and_check(int fd);
int				ft_check_grid(char *grid, int count);
int				ft_check_tetri(char *grid);
t_etri			*ft_put_tetri(char *grid, char letter);
t_list			*ft_free_list(t_list *list);
int				ft_backtracking(t_map *map, t_list *list);
int				ft_hight_sqrt(int n);
void			ft_solve(t_list *list);
void			ft_insert_piece(t_map *map, t_etri *tetri,
				char letter, t_point *point);
int				ft_valid_place(t_map *map, t_etri *tetri, int x, int y);
t_point			*ft_new_point(int x, int y);
void			ft_print_map(t_map *map);
t_map			*ft_new_map(int size);
void			ft_min_max(t_point *min, t_point *max, char *grid);
t_etri			*ft_new_tetri(int width, int height, char **pos, char letter);
void			ft_free_map(t_map *map);
int				ft_check_last(int fd);
#endif
