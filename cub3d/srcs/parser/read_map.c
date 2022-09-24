/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meourea <meourea@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:51:09 by cdahlia           #+#    #+#             */
/*   Updated: 2022/05/16 15:42:12 by meourea          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_map_size(int i, t_data *data)
{
	int	size;
	int	save;

	size = 0;
	save = 1;
	while (i < ft_strlen(data->repfile))
	{
		if (data->repfile[i] == '\n' || i == ft_strlen(data->repfile) - 1)
			++size;
		++i;
	}
	--i;
	while (i >= 0 && (data->repfile[i] == ' ' || data->repfile[i] == '\n'
			|| data->repfile[i] == '\t'))
	{
		--i;
		if (data->repfile[i] == '\n')
			++save;
	}
	return (size - save);
}

static int	check_n(int i, t_data *data, char **map_elem)
{
	int	start;

	start = i;
	while (data->repfile[i] && data->repfile[i] != '\n')
		++i;
	*map_elem = ft_substr(data->repfile, start, i - start);
	if (data->repfile[i] == '\n')
		++i;
	return (i);
}

static void	make_array_map(int i, t_data *data)
{
	int	save_i;
	int	size;
	int	j;

	j = 0;
	save_i = i;
	size = check_map_size(i, data);
	i = save_i;
	data->map = (char **)malloc(sizeof(char *) * (size + 2));
	while (i > 0 && data->repfile[i - 1] != '\n')
		--i;
	while (j < size + 1)
	{
		i = check_n(i, data, &data->map[j]);
		++j;
	}
	data->map[j] = NULL;
}

void	map_read(int i, t_data *data)
{
	while (data->repfile[i] && (data->repfile[i] == ' '
			|| data->repfile[i] == '\t' || data->repfile[i] == '\n'))
		++i;
	if (data->repfile[i] != '1' && data->repfile[i] != '0')
		print_error(data, ERROR_INCORRECT);
	else
	{
		if (data->repfile[i] == '0')
			print_error(data, ERROR_OPEN_MAP);
		else
			make_array_map(i, data);
	}
	map_error(data);
}
