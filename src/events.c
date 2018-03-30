/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:04:35 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/15 13:05:36 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		poll_event(t_rtv *s)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
		if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN &&
			e.key.keysym.sym == SDLK_ESCAPE))
			return (0);

	return (1);
}