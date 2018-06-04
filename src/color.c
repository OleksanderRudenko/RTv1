#include "rtv1.h"

int clamp(int a)
{
	if (a <= 0)
		return (0);
	else if (a > 255)
		return (255);
	return (a);
}

int		color_parse(t_color col, float c)
{
	int r;
	int g;
	int b;
	int	color;

	r = clamp((col.r & 0xFF) * c);
	g = clamp((col.g & 0xFF) * c);
	b = clamp((col.b & 0xFF) * c);
	color = (r << 16 | g << 8 | b);
	return (color);
}

// void    sphere_mapping_texture(t_additional *s, void *t)
// {
//     t_rtv                *rtv;
//     t_mapping_texture    *tx;
//     t_sphere            *sp;
//     t_vect                temp;

//     rtv = (t_rtv *)t;
//     sp = (t_sphere*)rtv->objects[s->figure].object;
//     tx = (t_mapping_texture *)rtv->objects[s->figure].texture.tx_struct;
//     temp = vector_substract(&s->point, &sp->pos);
//     temp = normalize_vector(&temp);
//     VAR_INT(i, 0);
//     i = (int)((0.5 + (atan2(temp.z, temp.x) / (2.0 * M_PI))) * 
// 	tx->w) + tx->w * (int)((0.5 - (asin(temp.y) / M_PI)) * tx->h);
//     s->mat.cl = parse_color(tx->arr[i]);
// }