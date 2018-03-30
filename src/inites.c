/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inites.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:01:16 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/15 17:39:26 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_rtv(t_rtv *s)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		sdl_err();
	s->win = SDL_CreateWindow("RTv1", SDL_WINDOWPOS_UNDEFINED,
	SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
	s->win_surface = SDL_GetWindowSurface(s->win);
	s->buff = s->win_surface->pixels;
	s->vp.h = 1.0;
	s->vp.w = 1.0;
	s->vp.dist = 1.0;
}

void	init_sphere(t_rtv *s)
{
	s->spher = (t_sphere *)malloc(sizeof(t_sphere) * 3);
	s->spher[0].radius = 1.2;
	s->spher[0].material = 1;
	s->spher[0].pos.x = 0.0;
	s->spher[0].pos.y = -1.0;
	s->spher[0].pos.z = 5.0;
	s->spher[0].color.red = 250;
	s->spher[0].color.green = 0;
	s->spher[0].color.blue = 0;

	s->spher[1].radius = 1.0;
	s->spher[1].material = 1;
	s->spher[1].pos.x = 2.0;
	s->spher[1].pos.y = 0.5;
	s->spher[1].pos.z = 6.0;
	s->spher[1].color.red = 0;
	s->spher[1].color.green = 250;
	s->spher[1].color.blue = 0;

	s->spher[2].radius = 1.0;
	s->spher[2].material = 1;
	s->spher[2].pos.x = -2.0;
	s->spher[2].pos.y = 0.0;
	s->spher[2].pos.z = 6.0;
	s->spher[2].color.red = 0;
	s->spher[2].color.green = 0;
	s->spher[2].color.blue = 250;
	//printf("%f\n", s->spher[0].color.red);
}

