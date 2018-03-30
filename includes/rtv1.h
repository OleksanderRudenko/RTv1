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
#define min(a,b) (((a) < (b)) ? (a) : (b))

// typedef enum	struct	e_type
// {
// 	ambient,
// 	point,
// 	directional
// }						s_type;

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
	float			red;
	float			green;
	float			blue;
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
	float			intens;
}					t_light;

/* Material Definition */
typedef struct		s_material
{
	t_color			diffuse;
	float			reflection;
}					t_material;

/* The ray */
typedef struct		s_ray
{
	t_vector		start;
	t_vector		dir;
}					t_ray;

/* The sphere */
typedef struct 		s_sphere
{
	float 			radius;
	int				material;
	t_vector		pos;
	t_color			color;
}					t_sphere;

typedef struct s_trace
{
	float	closest_spher;
	t_sphere	sfera;	
}t_trace;

typedef struct		s_rtv
{
	SDL_Window		*win;
	SDL_Event		event;
	SDL_Surface		*im_surf;
	SDL_Surface		*win_surface;
	unsigned int	*buff;
	unsigned int	*b;
	t_sphere		*spher;
	t_light			*light;
	t_ramka			vp;
	t_trace			sf;
}					t_rtv;

void		sdl_err(void);
int			poll_event(t_rtv *s);
void		init_rtv(t_rtv *s);
void		draw_sphere(t_rtv *s);
t_vector 	vector_sub(t_vector *v1, t_vector *v2);
t_vector 	vector_mult_scal(float c, t_vector *v);
float 		vector_dot(t_vector *v1, t_vector *v2);
float		vec_len(t_vector *v);
t_vector	vector_mult(t_vector *v1, t_vector *v2);
t_vector 	vector_add(t_vector *v1, t_vector *v2);
int		color_parse(int red, int green, int blue, float c);
void		init_sphere(t_rtv *s);
t_vector	convert_coords(t_rtv *s, int x, int y);
void		draw(t_rtv *s);
int 		ray_tracer_sphere(t_vector *o, t_vector *direction, float min, float max, t_rtv *s);
float    	lightning(t_rtv *s, t_vector *point, t_vector *normal);
void    init_light(t_rtv *s);
#endif
