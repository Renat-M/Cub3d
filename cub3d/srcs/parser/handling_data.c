/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:48:20 by cdahlia           #+#    #+#             */
/*   Updated: 2022/05/16 14:48:25 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	data_clipping(int i, t_data *data, char **str)
{
	int	start;

	start = 0;
	if (*str)
		print_error(data, ERROR_REPEATING_PARAMETERS);
	while (data->repfile[i] && (data->repfile[i] == ' '
			|| data->repfile[i] == '\t'))
		i++;
	start = i;
	while (data->repfile[i] && data->repfile[i] != ' '
		&& data->repfile[i] != '\t' && data->repfile[i] != '\n')
		i++;
	if (start == i)
		print_error(data, ERROR_EMPTY_STRING);
	*str = ft_substr(data->repfile, start, i - start);
	if (data->repfile[i] != '\n')
	{
		while (data->repfile[i] && data->repfile[i] != '\n'
			&& (data->repfile[i] == ' ' || data->repfile[i] == '\t'))
			i++;
		if (data->repfile[i] != '\n')
			print_error(data, ERROR_INCORRECT);
	}
	return (i);
}

static void	data_validation(t_data *data)
{
	if (access(data->no, R_OK) || access(data->so, R_OK)
		|| access(data->we, R_OK) || access(data->ea, R_OK))
		print_error(data, ERROR_TEXT_ERROR);
	if (!check_extension(data->no, 1) || !check_extension(data->no, 1)
		|| !check_extension(data->we, 1) || !check_extension(data->ea, 1))
		print_error(data, ERROR_EXTENSION);
}

static int	param_selection(int i, t_data *data)
{
	if (i == 0 && i_is_zero_cmp(i, "NO", data))
		i = data_clipping(i + 2, data, &data->no);
	else if (i > 0 && i_isnt_zero_cmp(i, "NO", data))
		i = data_clipping(i + 2, data, &data->no);
	else if (i == 0 && i_is_zero_cmp(i, "SO", data))
		i = data_clipping(i + 2, data, &data->so);
	else if (i > 0 && i_isnt_zero_cmp(i, "SO", data))
		i = data_clipping(i + 2, data, &data->so);
	else if (i == 0 && i_is_zero_cmp(i, "WE", data))
		i = data_clipping(i + 2, data, &data->we);
	else if (i > 0 && i_isnt_zero_cmp(i, "WE", data))
		i = data_clipping(i + 2, data, &data->we);
	else if (i == 0 && i_is_zero_cmp(i, "EA", data))
		i = data_clipping(i + 2, data, &data->ea);
	else if (i > 0 && i_isnt_zero_cmp(i, "EA", data))
		i = data_clipping(i + 2, data, &data->ea);
	else if (i == 0 && i_is_zero_color(i, 'F', data))
		i = color_handling(i + 1, data, 'F');
	else if (i > 0 && i_isnt_zero_color(i, 'F', data))
		i = color_handling(i + 1, data, 'F');
	else if (i == 0 && i_is_zero_color(i, 'C', data))
		i = color_handling(i + 1, data, 'C');
	else if (i > 0 && i_isnt_zero_color(i, 'C', data))
		i = color_handling(i + 1, data, 'C');
	return (i);
}

void	handling_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->repfile[i])
	{
		i = param_selection(i, data);
		if (data->repfile[i] != ' ' && data->repfile[i] != '\t'
			&& data->repfile[i] != '\n')
			print_error(data, ERROR_INCORRECT);
		if (data->no && data->so && data->so && data->ea
			&& data->floor != -1 && data->ceiling != -1)
			break ;
		i++;
	}
	data_validation(data);
	map_read(i, data);
}
