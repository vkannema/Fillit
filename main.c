/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkannema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 12:42:44 by vkannema          #+#    #+#             */
/*   Updated: 2016/11/29 13:53:06 by vkannema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fillit.h"

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc != 2)
	{
		ft_putendl("usage : fillit input_file");
		return (0);
	}
	if (ft_check_last(open(argv[1], O_RDONLY)) == 0)
	{
		ft_putendl("error");
		return (0);
	}
	list = ft_read_and_check(open(argv[1], O_RDONLY));
	if (list == NULL)
	{
		ft_putendl("error");
		return (0);
	}
	ft_solve(list);
	ft_free_list(list);
	return (0);
}
