/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:50:47 by cdahlia           #+#    #+#             */
/*   Updated: 2022/05/16 14:50:51 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	print_error2(int error)
{
	if (error == ERROR_OPEN_MAP)
		printf("Error\nopen map\n");
	else if (error == ERROR_MILPTIPLE_PLAYERS)
		printf("Error\nmultiple players on the map\n");
	else if (error == ERROR_PLAYER)
		printf("Error\nplayer not found\n");
	else if (error == ERROR_EXTENSION)
		printf("Error\nwrong extension\n");
}

void	print_error(t_data *data, int error)
{
	free_data(data);
	if (error == ERROR_RGB)
		printf("Error\nrgb color must be from 0 to 255\n");
	else if (error == ERROR_NUMBER_RGB)
		printf("Error\nrgb color must consist of 3 numbers\n");
	else if (error == ERROR_OPEN_FILE)
		printf("Error\nfile not found or permission denied\n");
	else if (error == ERROR_INCORRECT)
		printf("Error\nparameters are incorrect\n");
	else if (error == ERROR_EMPTY_STRING)
		printf("Error\nempty string without arguments\n");
	else if (error == ERROR_REPEATING_PARAMETERS)
		printf("Error\nrepeating parameters\n");
	else if (error == ERROR_WRONG_ORDER)
		printf("Error\nwrong order (NO, SO, WE, EA, F, C, *map*)\n");
	else if (error == ERROR_TEXT_ERROR)
		printf("Error\ntextures do not exist or access is denied\n");
	else if (error == ERROR_COLOR_NUMBER)
		printf("Error\nF/C should only contain numbers and a sep ','\n");
	else
		print_error2(error);
	exit(1);
}
