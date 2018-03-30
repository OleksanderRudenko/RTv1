#include "rtv1.h"

t_vector		convert_coords(t_rtv *s, int x, int y)
{
	t_vector		dis;

	dis.x = ((float)x) * s->vp.w / WIDTH;
	dis.y = ((float)y) * s->vp.h / HEIGHT;
	// printf("disx:%f\n", dis.x);
	// printf("disy:%f\n", dis.y);
	// dis.z = s->vp.dist;
	dis.z = 1.0;
	return (dis);
}