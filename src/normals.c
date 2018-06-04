/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 12:00:48 by arudenko          #+#    #+#             */
/*   Updated: 2018/05/31 12:00:50 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector get_normal(t_figure *fig, t_vector point)
{
	if (fig->name == SPHERA)
		return (spher_normal(fig, point));
	else if (fig->name == PLANE)
		return (plane_normal(fig));
	else if (fig->name == CYLINDER)
		return (cylinder_normal(point, fig));
	return ((t_vector){0.0, 0.0 ,0.0});
}

t_vector spher_normal(t_figure *fig, t_vector point)
{
	t_vector normal;

	normal = vector_sub(point, fig->pos);
	normal = vector_mult_scal(1.0 / vec_len(normal), normal);
	// normal = vector_mult_scal(-1.0, normal);
	// normal = vnormalize(normal);
	return (normal);
}

t_vector plane_normal(t_figure *fig)
{
	// vec_len(fig->direction)
	return (vnormalize(fig->pos));
}

t_vector		cylinder_normal(t_vector point, t_figure *fig)
{
	double		m;
	t_vector	normal;

	// fig->pos = vnormalize(vector_mult_scal(-1.0, fig->pos));
	m = vector_dot(vector_sub(point, fig->pos), fig->direction);
	normal = vector_add(fig->pos, vector_mult_scal(m, fig->direction));
	normal = vnormalize(vector_sub(point, normal));
	return (normal);
}