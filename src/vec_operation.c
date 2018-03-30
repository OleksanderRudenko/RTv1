#include "rtv1.h"

/* Subtract two vectors and return the resulting vector */
t_vector vector_sub(t_vector *v1, t_vector *v2)
{
	t_vector res;

	res.x = v1->x - v2->x;
	res.y = v1->y - v2->y;
	res.z = v1->z - v2->z;
	return res;
}

/* Calculate Vector x Scalar and return resulting Vector*/
t_vector vector_mult_scal(float c, t_vector *v)
{
	t_vector res;

	res.x = v->x * c;
	res.y = v->y * c;
	res.z = v->z * c;
	return (res);
}

t_vector vector_mult(t_vector *v1, t_vector *v2)
{
	t_vector res;

	res.x = v1->x * v2->x;
	res.y = v1->y * v2->y;
	res.z = v1->z * v2->z;
	return (res);
}

/* Multiply two vectors and return the resulting scalar (dot product) */
float vector_dot(t_vector *v1, t_vector *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

/* Add two vectors and return the resulting vector */
t_vector vector_add(t_vector *v1, t_vector *v2)
{
    t_vector res;

    res.x = v1->x + v2->x;
    res.y = v1->y + v2->y;
    res.z = v1->z + v2->z;
    return res;
}

float	vec_len(t_vector *v)
{
	return (vector_dot(v, v));
}

// t_vector ref_ray(t_vector *r, t_vector *n)
// {
// 	t_vector res;

// 	// return 2*N*dot(N, R) - R;
// 	res = vector_sub();
// }
