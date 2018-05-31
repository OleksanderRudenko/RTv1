#include "rtv1.h"

t_root find_sphere(t_vector origin, t_vector direction, t_figure *sphere)
{
	t_root d;
	double discrim;
	t_vector oc;
	/*T0DO*/
	/* create t_vector type for x1, x2, x3 */
	double x1;
	double x2;
	double x3;

	oc = vector_sub(origin, sphere->pos);
	x1 = vector_dot(direction, direction);
	x2 = 2 * vector_dot(oc, direction);
	x3 = vector_dot(oc, oc) - sphere->radius * sphere->radius;
	discrim = x2 * x2 - (4.0 * x1 * x3);
	if (discrim < 0)
	{
		return ((t_root){-1, -1});
	}
	d.a = (-x2 + sqrt(discrim) / (2.0 * x1));
	d.b = (-x2 - sqrt(discrim) / (2.0 * x1));
	return (d);
}

t_root find_plane(t_vector origin, t_vector direction, t_figure *obj)
{
	t_root t;
	t_root k;
	t_vector subs;

	subs = vector_sub(origin, obj->pos);
	k.a = vector_dot(direction, obj->direction);
	k.b = vector_dot(subs, obj->direction);
	if (k.a != 0)
		return ((t_root){-k.b / k.a, 0.0});
	return ((t_root){0.0, 0.0});
}

int ray_tracer_figures(t_vector o, t_vector direction, double min, double max, t_rtv *s)
{
	s->sf.closest_obj = max;
	closest_object(o, direction, min, max, s);
	if (s->sf.closest_obj == max || s->sf.near == NULL)
		return (0);
	t_vector point;
	t_vector normal;
	t_vector a;

	point = vector_add(o, vector_mult_scal(s->sf.closest_obj, direction));

	normal = get_normal(s->sf.near, point);

	
	t_vector view = vector_mult_scal(-1.0, direction);

	double fg = lightning(s, point, normal, s->sf.near->spec, view);
	if (s->sf.near->material == 0)
		s->sf.near->color = texture_color(normal, s->sf.closest_obj);
	return ((color_parse(s->sf.near->color, fg)));
}

t_color		texture_color(t_vector normal, double hit)
{
	t_color		col;
	int			color;
	SDL_Surface *surf;
	unsigned int	*arr;
	float		u;
	float		v;
	t_vector	d;

	u = 0.5 + atan2(normal.z, normal.x) / M_PI * 0.5;
	v = 0.5 - asin(normal.y/2)/M_PI;
	v = v - floor(v);
		// printf("u: %f v: %f\n", u * WIDTH ,v * WIDTH);
	surf = SDL_LoadBMP("text.bmp");
	if (surf == NULL)
		ft_putendl("LolWat");
	arr = surf->pixels;

	color = arr[(int)(u * 10) + (int)(v * WIDTH)];

	// int i = 0;
	// while (i < 100)
	// {
	// 	printf("%d\n", arr[i]);
	// 	++i;
	// }
	col.red = clamp(color >> 16);
	col.green = clamp(color >> 8);
	col.blue = clamp(color);
	// exit(0);
	return (col);
}