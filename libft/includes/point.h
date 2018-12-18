#ifndef POINT_H
# define POINT_H

# include <stdlib.h>

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}		t_point;

t_point		*ft_ptnew(int x, int y, int z);
void		ft_ptcpy(t_point *dst, t_point *src);
void		ft_ptset(t_point *pt, int x, int y, int z);
void		ft_ptfree(void **pt, size_t size);

#endif
