/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdahlia <cdahlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 14:51:29 by cdahlia           #+#    #+#             */
/*   Updated: 2022/05/16 14:51:34 by cdahlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	reaplace_file(t_data *data, int fd_file)
{
	char	*save;
	char	*save_replace;

	save = NULL;
	save_replace = NULL;
	while (get_next_line(fd_file, &save))
	{
		save_replace = data->repfile;
		data->repfile = ft_strjoin(save_replace, save);
		free(save_replace);
		free(save);
		save_replace = data->repfile;
		data->repfile = ft_strjoin(save_replace, "\n");
		free(save_replace);
	}
	save_replace = data->repfile;
	data->repfile = ft_strjoin(save_replace, save);
	free(save_replace);
	free(save);
}
