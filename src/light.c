#include "rtv1.h"

void init_light(t_rtv *s)
{
	s->light = (t_light *)malloc(sizeof(t_light) * 5);
	s->light[0].type = AMBIENT;
	s->light[0].intens = 0.2;

	s->light[1].type = POINT;
	s->light[1].intens = 0.3;
	s->light[1].pos.x = 1.3;
	s->light[1].pos.y = 9.0;
	s->light[1].pos.z = 7.3;

	s->light[2].type = POINT;
	s->light[2].intens = 0.0;
	s->light[2].pos.x = -1.5;
	s->light[2].pos.y = 8.5;
	s->light[2].pos.z = 4.2;

	s->light[3].type = DIR;
	s->light[3].intens = 0.0;
	s->light[3].pos.x = 1.5;
	s->light[3].pos.y = 9.0;
	s->light[3].pos.z = 7.2;

	s->light[4].type = DIR;
	s->light[4].intens = 0.0;
	s->light[4].pos.x = -4.5;
	s->light[4].pos.y = -1.0;
	s->light[4].pos.z = 0.2;
}

float lightning(t_rtv *s, t_vector point, t_vector normal, float spec, t_vector view)
{
	int i = 0;
	float intensity = 0.0;
	t_vector vec_l;
	t_vector vec_r;
	float n_dot_l;
	float r_dot_v;
	float t_max;

	while (i < 4)
	{
		if (s->light[i].type == AMBIENT)
		{
			intensity += s->light[i].intens;
		}
		else
		{
			if (s->light[i].type == POINT)
			{
				vec_l = vector_sub(s->light[i].pos, point);
				// vec_l = s->light[i].pos;
				//  vec_l = vector_mult_scal(-1.0, vec_l);
				t_max = 1000000.0;
			}
			else //light directional
			{
				vec_l = s->light[i].pos;
				// vec_l = vector_mult_scal(-1.0, vec_l);
				t_max = 1000000.0;
			}
			// point = vector_mult_scal(-1, point);
			closest_object_light(point, vec_l, 0.0001, t_max, s);
			if (s->sf.closest_obj2 != t_max || s->sf.near2 != NULL)
			{
				++i;
				continue;
				// intensity = 0.0;
				// if (s->light[i].type == AMBIENT)
				// 	intensity = s->light[i].intens;
			}

			n_dot_l = vector_dot(normal, vec_l);
			if (n_dot_l > 0)
			{
				intensity += s->light[i].intens * n_dot_l / (vec_len(normal) * vec_len(vec_l));
			}
			if (spec >= 0)
			{
				// t_vector lol = (vector_mult_scal(2.0 * vector_dot(normal, vec_l), normal));
				vec_r = vector_sub((vector_mult_scal(2.0 * vector_dot(normal, vec_l), normal)), vec_l);
				r_dot_v = vector_dot(vec_r, view);
				if (r_dot_v > 0)
				{
					intensity += s->light[i].intens * pow(r_dot_v / (vec_len(vec_r) * vec_len(view)), spec);
				}
			}
		}
		i++;
	}
	intensity > 1.0 ? intensity = 1.0 : 0;
	return (intensity);
}