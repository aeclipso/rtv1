/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aeclipso <aeclipso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 18:29:07 by ilmira            #+#    #+#             */
/*   Updated: 2020/11/18 18:49:35 by aeclipso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_RTV1_H
# define RTV1_RTV1_H
# include <unistd.h>
# include <fcntl.h>
# include <pthread.h>
# include "libft.h"
# include "veclib.h"
# include <SDL2/SDL.h>
# include <math.h>
# define WIDTH 750
# define HEIGHT 750
# define DIST 750

typedef struct	s_matr
{
	double			l;
	t_vec			vec;
}				t_matr;

typedef struct	s_vector
{
	t_vec			point;
	t_vec			direct;
	t_vec			angles;
	t_matr			roter;
	int				insert;
}				t_vector;

typedef struct	s_vecs
{
	t_vec	l;
	t_vec	k;
	double	t_max;
}				t_vecs;

typedef struct	s_obj
{
	double	radius;
	t_vec	center;
	t_vec	rot;
	double	color[3];
	t_vec	n;
	double	specular;
	char	*name;
	double	t;
	int		nbr;
	int		insert;
}				t_obj;

typedef struct	s_raydata
{
	double			t_max;
	t_vec			direction;
	t_vec			st_cent;
	t_vec			point;
}				t_raydata;

typedef struct	s_border
{
	double			b_x;
	double			b_x1;
	double			b_y;
	double			b_y1;
}				t_border;

typedef struct	s_light
{
	char			*type;
	double			intensity;
	t_vec			position;
	t_vec			direction;
	int				insert;
	struct s_light	*next;
}				t_light;

typedef struct	s_rt
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	int				x;
	int				y;
	int				d;
	t_vector		cam;
	t_obj			*obj;
	t_obj			*clone;
	t_light			*light;
	int				count;
	int				clos;
	int				s;
	int 			i;
	double			shadow_t;
	double			closest_t;
	int				amount_obj;
	double			intensity;
}				t_rt;

void			ft_render(t_rt *r);
void			ft_light(char **box, t_rt *r);
void			parse1(char **box, t_rt *r);
void			ft_cam(char **box, t_rt *r);
void			ft_parser(char *arg, t_rt *r);
void			ft_sphere(char **box, t_rt *r);
t_vec			ft_lighting1(t_rt *r, t_raydata vew);
void			ft_count_obj(t_rt *r, char *arg);
void			ft_plane(t_rt *r, char **box);
double			ft_ray_plane(t_raydata vew, t_obj obj);
t_vec			ft_norm_sphere(t_vec p, t_rt *r);
double			ray_sphere(t_raydata vew, t_obj obj);
t_vec			ft_norm_plane(t_rt *r);
double			ft_get_t(double k1, double k2, double k3);
double			ft_ray_con(t_raydata ray, t_obj *obj);
t_vec			ft_norm_con(t_vec vew, t_vec p, t_rt *r);
void			ft_con(t_rt *r, char **box);
void			ft_cylinder(t_rt *r, char **box);
t_vec			ft_norm_cylinder(t_vec vew, t_vec p, t_rt *r);
double			ft_ray_cylinder(t_raydata ray, t_obj *obj);
void			ft_put_error(char *s);
int				ft_valid(char **box);
void			ft_clear_box(char **box, int k);
double			closest_func(t_rt *r, t_raydata vew, double t_max, int i);
t_matr			matr_rot(t_vector camera);
t_vec			rot(t_vec vector, t_matr matr);
t_raydata		creat_ray(double max_len, t_vec point, t_vec direction);
void			matr_normal(t_matr *m);
#endif
