/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:59:48 by fquist            #+#    #+#             */
/*   Updated: 2023/02/06 19:52:59 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

int	is_occupied(char c)
{
	if (c == '1' || c == 'P')
		return (1);
	return (0);
}

void	print_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map.map[i])
	{
		printf("%s", data->map.map[i]);
		i++;
	}
}

time_t	timer(t_data *data)
{
	char	*fps;
	char	*count;
	char	*tmp;

	if (data->main_img->enabled == true)
	{
		if (data->runtime == 0)
			data->runtime = clock();
		if (data->counter)
			mlx_delete_image(data->mlx, data->counter);
		if (data->fps)
			mlx_delete_image(data->mlx, data->fps);
		count = ft_itoa((data->time_count - (clock()
						- data->runtime) / CLOCKS_PER_SEC));
		data->counter = mlx_put_string(data->mlx, count, WIDTH * 0.5, 10);
		tmp = ft_itoa(data->fps_val);
		fps = ft_strjoin("FPS: ", tmp);
		if (SHOW_FPS == true)
			data->fps = mlx_put_string(data->mlx, fps, 0, 0);
		free(count);
		free(fps);
		free(tmp);
	}
	return ((clock() - data->runtime) / CLOCKS_PER_SEC);
}

int	get_resolution(void)
{
	if (WIDTH == 1920 && HEIGHT == 1080)
		return (1);
	else if (WIDTH == 1600 && HEIGHT == 900)
		return (2);
	else
		return (0);
}
