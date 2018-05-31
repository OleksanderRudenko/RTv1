/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 12:37:00 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/15 15:38:09 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "SDL2/SDL.h"
# include <math.h>
# include "../libft/libft.h"

# define WIDTH 1000
# define HEIGHT 1000
# define AMBIENT 1
# define POINT 2
# define DIR 3
# define min(a,b) (((a) < (b)) ? (a) : (b))
# define SPHERA 1
# define PLANE 2
# define NUM_FIGURES 4

typedef struct		s_vector
{
	float 			x;
	float 			y;
	float 			z;
}					t_vector;

typedef struct		s_root
{
	float			a;//root1
	float			b;//root2
}					t_root;

/* Color */
typedef struct		s_color
{
	int			red;
	int			green;
	int			blue;
}					t_color;

typedef struct		s_ramka
{
	float			dist; // d
	float			w; // view width
	float			h; // view height
	float			x;
	float			y;
}					t_ramka;

/* Lightsource definition */
typedef struct		s_light
{
	t_vector		pos;
	int				type;
	double			intens;
}					t_light;

/* The ray */
typedef struct		s_ray
{
	t_vector		origin;
	t_vector		dir;
}					t_ray;

/* The sphere */
typedef struct 		s_figure
{
	double 			radius;
	int				material;
	int				name;
	double			spec;
	t_vector		pos;
	t_vector		direction;
	t_color			color;
}					t_figure;

typedef struct		s_trace
{
	double			closest_obj;
	t_figure		*near;
	double			closest_obj2;
	t_figure		*near2;
}					t_trace;

typedef struct		s_rtv
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Surface		*im_surf;
	SDL_Surface		*win_surface;
	unsigned int	*buff;
	unsigned int	*b;
	t_figure		*figure;
	// t_figure		near;
	t_light			*light;
	t_ramka			vp;
	t_trace			sf;
}					t_rtv;

void		sdl_err(void);
int			poll_event(t_rtv *s);
void		init_rtv(t_rtv *s);
void		draw_sphere(t_rtv *s);
t_vector 	vector_sub(t_vector v1, t_vector v2);
t_vector 	vector_mult_scal(double c, t_vector v);
double 		vector_dot(t_vector v1, t_vector v2);
double		vec_len(t_vector v);
t_vector	vector_mult(t_vector v1, t_vector v2);
t_vector 	vector_add(t_vector v1, t_vector v2);
int		color_parse(t_color col, double c);
void		init_sphere(t_rtv *s);
t_vector	convert_coords(t_rtv *s, int x, int y);
void		draw(t_rtv *s);
int 		ray_tracer_figures(t_vector o, t_vector direction, double min, double max, t_rtv *s);
double    lightning(t_rtv *s, t_vector point, t_vector normal, double spec, t_vector view);
void    init_light(t_rtv *s);
t_root	find_plane(t_vector origin, t_vector direction, t_figure *obj);
t_root	find_sphere(t_vector origin, t_vector direction, t_figure *sphere);

void closest_object(t_vector o, t_vector direction, double min, double max, t_rtv *s);
void closest_object_light(t_vector o, t_vector direction, double min, double max, t_rtv *s);
t_vector get_normal(t_figure *fig, t_vector point);
t_vector spher_normal(t_figure *fig, t_vector point);
t_vector plane_normal(t_figure *fig);
t_vector vnormalize(t_vector a);
t_color		texture_color(t_vector normal,double hit);
int clamp(int a);
#endif
