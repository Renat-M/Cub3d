/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:50:10 by cdahlia           #+#    #+#             */
/*   Updated: 2022/05/16 14:50:15 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_first_last_string(int j, t_data *data)
{
	int	i;

	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] != '1' && check_s_t(data->map[j][i], 1))
			print_error(data, ERROR_OPEN_MAP);
		i++;
	}
}

static void	map_error2(t_data *data, int j, int i)
{
	while (data->map[j][i])
	{
		if (data->map[j][i] && data->map[j][i] != '0'
			&& data->map[j][i] != '1' && check_s_t(data->map[j][i], 1)
			&& !check_plr(data->map[j][i]))
			print_error(data, ERROR_INCORRECT);
		if (data->map[j][i] == '0')
		{
			if ((data->map[j - 1] && ft_strlen(data->map[j - 1]) < i)
				|| (data->map[j - 1][i] && check_s_t(data->map[j - 1][i], 0)))
				print_error(data, ERROR_OPEN_MAP);
			if ((data->map[j + 1] && ft_strlen(data->map[j + 1]) < i)
				|| (data->map[j + 1][i] && check_s_t(data->map[j + 1][i], 0)))
				print_error(data, ERROR_OPEN_MAP);
		}
		if (data->map[j][i] && check_plr(data->map[j][i]) && !data->plr_ch)
			data->plr_ch = data->map[j][i];
		else if (data->map[j][i] && check_plr(data->map[j][i]) && data->plr_ch)
			print_error(data, ERROR_MILPTIPLE_PLAYERS);
		i++;
		if ((check_s_t(data->map[j][i], 0) || data->map[j][i] == '\n'
			|| data->map[j][i] == '\0') && (data->map[j][i - 1] != '1'
			&& check_s_t(data->map[j][i - 1], 1)))
			print_error(data, ERROR_OPEN_MAP);
	}
}

void	map_error(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	check_first_last_string(0, data);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] && check_s_t(data->map[j][i], 0))
			i++;
		if (i == 0 && data->map[j][i] == '\0')
			print_error(data, ERROR_EMPTY_STRING);
		if (data->map[j][i] && data->map[j][i] != '1')
			print_error(data, ERROR_OPEN_MAP);
		map_error2(data, j, i);
		j++;
		if (!data->map[j + 1])
		{
			check_first_last_string(j, data);
			break ;
		}
	}
	if (!data->plr_ch)
		print_error(data, ERROR_PLAYER);
}
