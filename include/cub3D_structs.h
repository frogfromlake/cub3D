/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fquist <fquist@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 19:08:00 by fquist            #+#    #+#             */
/*   Updated: 2022/07/06 19:09:50 by fquist           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

/* standard	 Aspect rat.   width   height
	HD+			16:9		1600	900
	FHD			16:9		1920	1080
*/

//	Window Size
// HD+
# define WIDTH 1600
# define HEIGHT 900
// FHD
// # define WIDTH 1920
// # define HEIGHT 1080

/* ************************************************************************** */
/* 	DATA STRUCTURES															  */
/* ************************************************************************** */

typedef struct s_vec
{
	float	x;
	float	y;
}	t_vec;

typedef struct s_intpair
{
	int	x;
	int	y;
}	t_intpair;

typedef struct s_texes
{
	mlx_texture_t	*tex_n;
	mlx_texture_t	*tex_s;
	mlx_texture_t	*tex_e;
	mlx_texture_t	*tex_w;
	mlx_texture_t	*tex_p;
}	t_texes;

typedef struct s_map
{
	char	**map;
	char	*paths[4];
	int		f_colour;
	int		c_colour;
	int		map_fd;
	int		x;
	int		y;
	bool	no;
	bool	ea;
	bool	so;
	bool	we;
	bool	f;
	bool	c;
	bool	created;
}	t_map;

typedef struct s_player
{
	t_vec		dir;
	t_vec		init_pos;
	float		p_x;
	float		p_y;
	float		old_x;
	float		old_y;
	float		old_dir;
	float		p_dir;
	float		p_dir_x;
	float		p_dir_y;
	float		plane_x;
	float		plane_y;
	float		move_speed;
	float		sprint_speed;
	float		p_old_dir_x;
}				t_player;

typedef struct s_camera
{
	t_vec	plane;
	t_vec	ray;
	float	camerapos;
}				t_camera;

typedef struct s_data
{
	void		*mlx;
	mlx_image_t	*main_img;
	t_texes		imgs;
	t_map		map;
	t_player	player;
	t_vec		vec;
	t_intpair	map_values;
	t_camera	camera;
	float		perp_wall_dist_s[WIDTH];
	float		h;
	int			m_x;
	int			m_y;
	int			screen_width;
	int			screen_height;
	float		fov_factor_x;
	float		fov_factor_y;
	int			*wall_heights;
	char		*wall_types;
	float		*wall_shade;
	int			side;
	bool		float_keys;
}				t_data;

#endif