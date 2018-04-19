#include "rtv1.h"

void closest_object(t_vector *o, t_vector *direction, double min, double max, t_rtv *s)
{
    t_root	ts;
    int i;

    s->sf.closest_obj = max;
    i = -1;
    while (++i < 6)
	{
		if (s->figure[i].name == SPHERA)
			ts = find_sphere(o, direction, &s->figure[i]);
		if (s->figure[i].name == PLANE)
			ts = find_plane(o, direction, &s->figure[i]);
		if (ts.a < s->sf.closest_obj && min < ts.a && ts.a < max)
		{
			s->sf.closest_obj = ts.a;
			s->sf.near = s->figure[i];
            //break;
		}
		if (ts.b < s->sf.closest_obj && min < ts.b && ts.b < max)
		{
			s->sf.closest_obj = ts.b;
			s->sf.near = s->figure[i];
            //break;
		}
	}
}