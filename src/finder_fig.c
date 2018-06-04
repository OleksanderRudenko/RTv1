/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finder_fig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:47:53 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/15 13:49:22 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_root find_sphere(t_vector origin, t_vector direction, t_figure *sphere)
{
	t_root d;
	float discrim;
	t_vector oc;
	/*T0DO*/
	/* create t_vector type for x1, x2, x3 */
	float x1;
	float x2;
	float x3;

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

// t_root find_plane(t_vector origin, t_vector direction, t_figure *obj)
// {
// 	t_root k;
// 	t_vector subs;

// 	subs = vector_sub(origin, obj->pos);
// 	k.a = vector_dot(direction, obj->direction);
// 	k.b = vector_dot(subs, obj->direction);
// 	if (k.a != 0)
// 		return ((t_root){-k.b / k.a, -1.0});
// 	return ((t_root){-1.0, -1.0});
// }

t_root find_plane(t_vector origin, t_vector direction, t_figure *obj)
{
	t_root k;

	k = (t_root){-1, -1};
	if (obj->direction.x != 0 || obj->direction.y != 0 || obj->direction.z != 0)
		k.a = vector_dot(obj->direction, vector_sub(obj->pos, origin)) /
				vector_dot(obj->direction, direction);
		k.b = -1.0;
	return (k);
}

//  a   = D|D - (D|V)^2
//    b/2 = D|X - (D|V)*(X|V)
//    c   = X|X - (X|V)^2 - r*r
// Surface normal is:

//    m = D|V*t + X|V
//    N = nrm( P-C-V*m )

t_root			find_cylinder(t_vector origin, t_vector dir, t_figure *obj)
{
    	/*T0DO*/
	/* create t_vector type for a, b, c */
	float a;
	float b;
	float c;
	float discrim;
    t_root d;

    // obj->pos = vnormalize(obj->pos);
	a = vector_dot(dir, dir) - pow(vector_dot(dir, obj->direction), 2.0);

	b = (vector_dot(dir, vector_sub(origin, obj->pos)) - vector_dot(dir, obj->direction) *
			vector_dot(vector_sub(origin, obj->pos), obj->direction)) * 2.0;

	c = vector_dot(vector_sub(origin, obj->pos), vector_sub(origin, obj->pos)) -
		pow(vector_dot(vector_sub(origin, obj->pos), obj->direction), 2) - (obj->radius * obj->radius);
	discrim = b * b - (4.0 * a * c);
	if (discrim < 0)
	{
		return ((t_root){-1, -1});
	}
	d.a = (-b + sqrt(discrim) / (2.0 * a));
	d.b = (-b - sqrt(discrim) / (2.0 * a));
	return (d);
}
