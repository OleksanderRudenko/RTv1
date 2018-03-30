#include "rtv1.h"

t_root	find_sphere(t_vector *origin, t_vector *direction, t_sphere *sphere)
{
	t_root		d;
	float		discrim;
	t_vector	oc;
	float		x1;
	float		x2;
	float		x3;

	oc = vector_sub(origin, &sphere->pos);
	x1 = vector_dot(direction, direction);
	x2 = 2 * vector_dot(&oc, direction);
	x3 = vector_dot(&oc, &oc) - sphere->radius * sphere->radius;
	discrim = x2 * x2 - (4.0 * x1 * x3);
	if (discrim < 0)
	{
		return((t_root){-1, -1});
	}
	d.a = (-x2 + sqrt(discrim) / (2.0 * x1));
	d.b = (-x2 - sqrt(discrim) / (2.0 * x1));
	return (d);
}

int 	ray_tracer_sphere(t_vector *o, t_vector *direction, float min, float max, t_rtv *s)
{
	s->sf.closest_spher = 0;
	int	i = 0;
	t_root	ts;
    t_vector    point;
    t_vector    normal;

	while (i < 3)
	{
		// ts.a = -1;
		// ts.b = -1;
		ts = find_sphere(o, direction, &s->spher[i]);
		if (ts.a > s->sf.closest_spher && min < ts.a && ts.a < max)
		{
			s->sf.closest_spher = ts.a;
			break;
		}
		if (ts.b > s->sf.closest_spher && min < ts.b && ts.b < max)
		{
			s->sf.closest_spher = ts.b;
			break;
		}
		i++;
	}
    t_vector a;
    a = vector_mult_scal(s->sf.closest_spher, direction);
    point = vector_add(o, &a);
    normal = vector_sub(&point, &s->spher[i].pos);
    normal = vector_mult_scal(1.0 / vec_len(&normal), &normal);
	if (s->sf.closest_spher == 0)
		return (0);
    float   fg =  lightning(s, &point, &normal);
    //printf("%f\n", fg);
	return((color_parse((int)s->spher[i].color.red , (int)s->spher[i].color.green, (int)s->spher[i].color.blue, fg)));
    //return((color_parse((int)s->spher[i].color.red, (int)s->spher[i].color.green, (int)s->spher[i].color.blue)));
}