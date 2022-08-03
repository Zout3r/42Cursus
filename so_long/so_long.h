/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 11:26:09 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/03 16:22:37 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdio.h>
# include "./get_next_line/get_next_line.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_enemy {
	int		x_e;
	int		y_e;
	int		sign;
	int		x;
	int		path_to_move;
	int		sleep;
	int		sleep_for_move;
	char	*imgs[5];
}	t_enemy_vars;

typedef struct s_vars {
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				movement;
	char			**map;
	int				collect;
	t_enemy_vars	e_vars;
}	t_vars;

typedef struct s_vars_map {
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map_vars;

void	check_file(char *file_line);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);
char	**get_map(char *fmap);
size_t	ft_strlen(const char *arg);
void	check_map(t_vars *vars);
int		get_height(char **map);
void	check_elements(t_vars **vars);
void	ft_error(t_vars ***v, char *err);
char	*ft_itoa(int n);
void	put_text(t_vars ***v);
void	put_image(t_vars ***v, int x, int y, char *img);
void	put_image_to_map(char p, int x1, int y1, t_vars **v);
void	exit_door(t_vars ***v);
void	to_left(t_vars **v);
void	to_right(t_vars **v);
void	to_up(t_vars **v);
void	to_down(t_vars **v);
void	open_exit(t_vars **vars);
char	*ft_substr(const char *s, unsigned int start, size_t len);
int		get_position_for_enemy(t_vars **vars);
int		animation(t_vars *vars);

#endif