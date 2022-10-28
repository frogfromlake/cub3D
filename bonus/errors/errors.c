/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:44:39 by fquist            #+#    #+#             */
/*   Updated: 2022/07/03 22:56:07 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D_bonus.h"

void	malloc_error(t_data *game, char *error_obj)
{
	printf("\e[0;31mMemory allocation for '%s' failed.\e[0m\n", error_obj);
	exit_game(game);
}

void	error(t_data *game, char *error_message)
{
	if (!error_message)
		exit_game(game);
	else
	{
		printf("%s", error_message);
		exit_game(game);
	}
}

void	input_error(t_data *game, int argc)
{
	if (argc != 2)
	{
		error(game, "\e[0;31mError: invalid arguments."
			" Usage  >>  $./cub3D MAP_PATH/MAP_NAME.cub'\e[0m\n");
	}
}
