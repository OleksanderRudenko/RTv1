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
	return ((t_vector){0.0, 0.0 ,0.0});
}

t_vector spher_normal(t_figure *fig, t_vector point)
{
	t_vector normal;

	normal = vector_sub(point, fig->pos);
	normal = vector_mult_scal(1.0 / vec_len(normal), normal);
	return (normal);
}

t_vector plane_normal(t_figure *fig)
{
	return (vnormalize(fig->pos));
}