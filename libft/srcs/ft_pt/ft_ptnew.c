#include "point.h"

t_point	*ft_ptnew(int x, int y, int z)
{
	t_point	*pt;
	pt = (t_point *)malloc(sizeof(t_point));
	ft_ptset(pt, x, y, z);
	return (pt);
}
