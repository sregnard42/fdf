#include "point.h"

void	ft_ptcpy(t_point *dst, t_point *src)
{
	ft_ptset(dst, src->x, src->y, src->z);
}
