/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:50:28 by cdahlia           #+#    #+#             */
/*   Updated: 2022/05/16 14:50:35 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_parser(char *file, t_data *data)
{
	int		fd_file;

	init_data(data);
	if (!check_extension(file, 0))
		print_error(data, ERROR_EXTENSION);
	fd_file = open(file, O_RDONLY, 0644);
	if (fd_file == -1)
		print_error(data, ERROR_OPEN_FILE);
	else
	{
		reaplace_file(data, fd_file);
		close(fd_file);
	}
	handling_data(data);
}
