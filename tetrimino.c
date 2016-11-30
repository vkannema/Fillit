/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrandt <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:13:58 by bbrandt           #+#    #+#             */
/*   Updated: 2016/11/29 13:17:29 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

t_etri	*ft_new_tetri(int width, int height, char **pos, char letter)
{
	t_etri	*tetri;

	tetri = malloc(sizeof(t_etri));
	tetri->width = width;
	tetri->height = height;
	tetri->array = pos;
	tetri->letter = letter;
	return (tetri);
}

int		ft_check_last(int fd)
{
	int		i;
	int		count;
	char	buf[BUF_SIZE + 1];

	i = 0;
	count = read(fd, buf, BUF_SIZE);
	buf[count] = '\0';
	close(fd);
	while (buf[i])
		i++;
	i--;
	if (buf[i] == '\n' && (buf[i - 1] != '.' && buf[i - 1] != '#'))
		return (0);
	return (1);
}
