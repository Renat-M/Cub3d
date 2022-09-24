/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:39:55 by cdahlia           #+#    #+#             */
/*   Updated: 2022/05/16 14:39:55 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	press_keys(t_data *data)
{
	if (data->keys.left_turn)
		turn_left(data);
	if (data->keys.right_turn)
		turn_right(data);
	if (data->keys.forward)
		move_forward(data);
	if (data->keys.backward)
		backward_move(data);
	if (data->keys.left)
		strafe(data, 1);
	if (data->keys.right)
		strafe(data, -1);
}

int	keyrelease(int keycode, t_data *data)
{
	if (keycode == W)
		data->keys.forward = 0;
	if (keycode == S)
		data->keys.backward = 0;
	if (keycode == A)
		data->keys.left = 0;
	if (keycode == D)
		data->keys.right = 0;
	if (keycode == LEFT)
		data->keys.left_turn = 0;
	if (keycode == RIGHT)
		data->keys.right_turn = 0;
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == ESC)
		ft_exit(data);
	if (keycode == W)
		data->keys.forward = 1;
	if (keycode == S)
		data->keys.backward = 1;
	if (keycode == A)
		data->keys.left = 1;
	if (keycode == D)
		data->keys.right = 1;
	if (keycode == LEFT)
		data->keys.left_turn = 1;
	if (keycode == RIGHT)
		data->keys.right_turn = 1;
	return (0);
}
