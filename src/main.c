/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:57:23 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/15 17:13:59 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw(t_rtv *s)
{
	int x;
	int y;
	int color;
	t_vector origin;
	t_vector direction;

	origin.x = 0;
	origin.y = 0;
	origin.z = 0;
	x = 0;
	s->b = s->win_surface->pixels;
	while (x < WIDTH )
	{
		y = 0;
		while (y < HEIGHT)
		{
			 direction = convert_coords(s, x - WIDTH/2 , HEIGHT/2 -y);
			//direction = convert_coords(s, x, y);
			// printf("disx:%f\n", direction.x);
			// printf("disy:%f\n", direction.y);
			color = ray_tracer_sphere(&origin, &direction, 0.01f, 1000000, s);
			//printf("%d\n", color);
			s->b[x + y * WIDTH] = color;
			y++;
		}
		x++;
	}
}

int		main(int argc, char **argv)
{
	t_rtv rtv;
	t_sphere	s;
	init_rtv(&rtv);
	init_sphere(&rtv);
	init_light(&rtv);
	while (1)
	{
		if (!poll_event(&rtv))
			return (0);
		ft_bzero(rtv.win_surface->pixels, WIDTH * HEIGHT * 4);
		draw(&rtv);
		SDL_UpdateWindowSurface(rtv.win);
	}
	return (0);
}
