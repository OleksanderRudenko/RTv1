#include "rtv1.h"

void closest_object(t_vector o, t_vector direction, double min, double max, t_rtv *s)
{
	t_root	ts;
	int i;

	s->sf.closest_obj = max;
	s->sf.near = NULL;
 	i = -1;
	while (++i < NUM_FIGURES)
	{
		if (s->figure[i].name == SPHERA)
			ts = find_sphere(o, direction, &s->figure[i]);
		if (s->figure[i].name == PLANE)
			ts = find_plane(o, direction, &s->figure[i]);
		if (ts.a < s->sf.closest_obj && min < ts.a && ts.a < max)
		{
			s->sf.closest_obj = ts.a;
			s->sf.near = &s->figure[i];
		}
		if (ts.b < s->sf.closest_obj && min < ts.b && ts.b < max)
		{
			s->sf.closest_obj = ts.b;
			s->sf.near = &s->figure[i];
		}
	}
}

void closest_object_light(t_vector o, t_vector direction, double min, double max, t_rtv *s)
{
	t_root	ts;
	int i;

	s->sf.closest_obj2 = max;
	s->sf.near2 = NULL;
 	i = -1;
	while (++i < NUM_FIGURES)
	{
		if (s->figure[i].name == SPHERA)
			ts = find_sphere(o, direction, &s->figure[i]);
		if (s->figure[i].name == PLANE)
			ts = find_plane(o, direction, &s->figure[i]);
		if (ts.a < s->sf.closest_obj2 && min < ts.a && ts.a < max)
		{
			s->sf.closest_obj2 = ts.a;
			s->sf.near2 = &s->figure[i];
		}
		if (ts.b < s->sf.closest_obj2 && min < ts.b && ts.b < max)
		{
			s->sf.closest_obj2 = ts.b;
			s->sf.near2 = &s->figure[i];
		}
	}
}