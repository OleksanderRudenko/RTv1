/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arudenko <arudenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/15 13:47:53 by arudenko          #+#    #+#             */
/*   Updated: 2018/03/15 13:49:22 by arudenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	draw_sphere(t_rtv *s)
{
	int x = 0;
    int y = 0;
    s->b = s->win_surface->pixels;
    while (x < WIDTH)
    {
        while (y < HEIGHT)
        {
            s->b[x * WIDTH + y] = 0xff;
            y++;
        }
        x++;
    }
}



// void    main_loop(t_rtv *s)
// {
//     int x;
//     int y;

//     x = 0;
//     y = 0;

// }