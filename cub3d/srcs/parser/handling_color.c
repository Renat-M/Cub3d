/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:47:49 by cdahlia           #+#    #+#             */
/*   Updated: 2022/05/16 14:47:58 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static void	hext_char_to_int(t_data *data, char **array_atoi, char color)
{
	long long	r;
	long long	g;
	long long	b;

	if (!array_atoi[0] || !array_atoi[1] || !array_atoi[2])
		print_error(data, ERROR_INCORRECT);
	r = ft_atoi(array_atoi[0]);
	g = ft_atoi(array_atoi[1]);
	b = ft_atoi(array_atoi[2]);
	if (r > 255 || g > 255 || b > 255)
		print_error(data, ERROR_RGB);
	if (color == 'F')
		data->floor = to_hex(r, g, b);
	else if (color == 'C')
		data->ceiling = to_hex(r, g, b);
}

static int	color_handling3(int i, int start, t_data *data, char **array_atoi)
{
	int	j;

	j = 0;
	while (array_atoi[j])
		j++;
	while (data->repfile[i] && data->repfile[i] != ','
		&& data->repfile[i] != '\n')
	{
		if (check_fl_cel_error(data->repfile[i]))
			print_error(data, ERROR_INCORRECT);
		i++;
	}
	if (check_fl_cel_error(data->repfile[i]))
		print_error(data, ERROR_INCORRECT);
	if (i != start)
	{
		if (j == 3)
			print_error(data, ERROR_NUMBER_RGB);
		array_atoi[j] = ft_substr(data->repfile, start, i - start);
		j++;
		if (j == 3)
			array_atoi[j] = NULL;
	}
	return (i);
}

static int	color_handling2(int i, t_data *data, char **array_atoi, char color)
{
	int	start;

	start = 0;
	while (data->repfile[i] && data->repfile[i] != '\n')
	{
		while (data->repfile[i] && (data->repfile[i] == ' '
				|| data->repfile[i] == '\t') && data->repfile[i] != '\n')
		{
			i++;
			if (data->repfile[i] == ',')
				print_error(data, ERROR_RGB);
		}
		start = i;
		i = color_handling3(i, start, data, array_atoi);
		if (data->repfile[i] == '\n')
		{
			hext_char_to_int(data, array_atoi, color);
			break ;
		}
		i++;
	}
	return (i);
}

int	color_handling(int i, t_data *data, char color)
{
	char	**array_atoi;
	int		j;

	j = 0;
	array_atoi = (char **)malloc(sizeof(char *) * 4);
	while (j < 4)
		array_atoi[j++] = NULL;
	if (!array_atoi)
		exit(1);
	i = color_handling2(i, data, array_atoi, color);
	if (array_atoi)
		free_array(array_atoi);
	return (i);
}
