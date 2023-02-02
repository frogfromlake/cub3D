/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 16:49:49 by fquist            #+#    #+#             */
/*   Updated: 2023/02/02 01:10:44 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/* ************************************************************************** */
/* STANDARD INCLUDES														  */
/* ************************************************************************** */
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# include "../libs/libft/include/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../include/cub3D_structs.h"
# include "../include/cub3D_defines.h"

/* ************************************************************************** */
/* 	PARSER																	  */
/* ************************************************************************** */
void			allocating_map(t_data *data, char **argv);
void			parsing_data(t_data *data, int argc, char **argv);
void			loading_map(t_data *data);
int				parsing_identifiers(t_data *data);
char			*parsing_path(t_data *data, char *str, int i);
int				parsing_colour(t_data *data, char *str, int i);
int				create_trgb(int r, int g, int b);
void			parsing_map(t_data *data);
int				is_empty_tile(char tile);
void			set_init_player_dir(t_data *game, int x, int y);
bool			no_whitespaces(char *str);
int				init_player_values(t_data *data, int x, int y);
int				is_sprite(char c);
void			check_valid_zero(t_data *data, int x, int y);
void			check_valid_player_pos(t_data *data, int x, int y);
int				is_bonus(char c);

/* ************************************************************************** */
/* 	ERRORS																	  */
/* ************************************************************************** */
void			malloc_error(t_data *game, char *error_obj);
void			error(t_data *game, char *error_message);
void			input_error(t_data *data, int argc);

/* ************************************************************************** */
/* 	UTILS																	  */
/* ************************************************************************** */
char			*strjoin(char *s1, const char *s2);
int				line_is_whitespace(char *str);
int				ft_atoi_cub(const char *str, int *res);
int				skip_whitespaces(char *str);
void			print_map(t_data *data);
int				is_player(char tile);
int				get_resolution(void);

/* ************************************************************************** */
/* 	MINIMAP																	  */
/* ************************************************************************** */
int32_t			create_window(t_data *data);

/* ************************************************************************** */
/* 	RAYCASTING																  */
/* ************************************************************************** */
int				calculating_walls(t_data *game);
t_vec			calc_ray(t_data *game, int i);
float			find_hit(t_data *game, int i);
int				dda(t_data *game, t_vec *side_dist,
					t_vec delta_dist, t_intpair step);

/* ************************************************************************** */
/* 	INITILIZATION															  */
/* ************************************************************************** */
t_vec			calc_dir(int d);
void			init_variables(t_data *game);
void			load_images(t_data *game);
void			load_textures(t_data *game);

/* ************************************************************************** */
/* 	MOVEMENT																  */
/* ************************************************************************** */
void			hook(void *data);
void			rotdir(t_data *game, int p);
void			call_key_events(t_data *game, int param, bool rotation,
					char dir);
void			moveplayer_per(t_data *game, int p, float move_speed);
void			moveplayer_par(t_data *game, int p, float move_speed);
int				is_occupied(char c);
t_vec			calc_dir(int d);

/* ************************************************************************** */
/* 	RENDERER																  */
/* ************************************************************************** */
int				rendering_world(t_data *game);
uint32_t		get_pixel(t_data *game, int x, int y);
void			exit_game(t_data *game);
#endif
