/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mportaka <mportaka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 14:07:36 by mportaka          #+#    #+#             */
/*   Updated: 2024/02/24 14:15:49 by mportaka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include "../library/minilibx_opengl/mlx.h"

# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define EXIT 17
# define PIXEL 32

typedef struct s_map
{
	char		**map;
	int			x;
	int			y;
}				t_map;

typedef struct s_sprite
{
	void		*tile;
	void		*exit;
	void		*coin;
	void		*player;
	void		*wall;
}				t_sprite;

typedef struct s_main
{
	void		*mlx;
	void		*win;
	void		*img;
	int			read_count;
	int			p_count;
	int			c_count;
	int			e_count;
	int			m_count;
	int			player_x;
	int			player_y;
	t_map		*map;
	t_sprite	*sprite;
}				t_main;

int				main_initiliazer(char *map_path, t_main **main);
char			**map_initiliazer(char *path, t_main *main);

void			check_parameters(int ac, char **av);
void			map_checker(t_main *main);

int				virtual_map(t_main *main, int y, int x);
int				draw_map(t_main *main);
void			map_control(t_main *main, int i, int j);
int				draw_map2(t_main *main, int i, int j);
void			path_error(char *errormsg);
void			map_cem_checker(t_main **main, int i, int j);

void			virtual_map_free(int **v_map, t_main *main);
int				ft_x_button(t_main *main);
void			ft_free(t_main *main);
void			ft_error(char *errormsg, t_main *main);

int				key_hook(int keycode, t_main *main);
int				render(t_main *main);
#endif