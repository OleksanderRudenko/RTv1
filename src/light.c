#include "rtv1.h"

void    init_light(t_rtv *s)
{
    s->light = (t_light *)malloc(sizeof(t_light) * 4);
    s->light[0].type = AMBIENT;
    s->light[0].intens = 0.0;

    s->light[1].type = POINT;
    s->light[1].intens = 1;
    s->light[1].pos.x = 0.0;
    s->light[1].pos.y = 0.1;
    s->light[1].pos.z = 0.0;

    s->light[2].type = DIR;
    s->light[2].intens = 0.5;
    s->light[2].pos.x = -1.5;
    s->light[2].pos.y = 1.5;
    s->light[2].pos.z = -0.2;

    s->light[3].type = DIR;
    s->light[3].intens = 0.5;
    s->light[3].pos.x = 1.5;
    s->light[3].pos.y = -1.5;
    s->light[3].pos.z = 0.2;
}

float    lightning(t_rtv *s, t_vector *point, t_vector *normal)
{
    int     i = 0;
    float   intensity = 0.0;
    t_light     li;
    t_vector    vec_l;
    float       n_dot_l;
    float       len_norm;

    // ft_putnbr(s->light[i].type);
    len_norm = vec_len(normal);
    while (i < 4)
    {
        if (s->light[i].type == AMBIENT)
        {
            intensity += s->light[i].intens;
            //printf("amb: %f\n", intensity);
        }
        else
        {
            if (s->light[i].type == POINT)
                vec_l = vector_sub(&s->light[i].pos, point);
            else //light directional
                vec_l = s->light[i].pos;
        n_dot_l = vector_dot(normal, &vec_l);
        if (n_dot_l > 0)
        {
            intensity += s->light[i].intens * n_dot_l / (len_norm * vec_len(&vec_l));
             //printf("vec: %f\n", n_dot_l);
            //printf("%f\n", intensity);
         }
        }
        i++;
    }
    //printf("%f\n", intensity);
    return (intensity);
}