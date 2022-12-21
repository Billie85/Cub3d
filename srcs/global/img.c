#include "../cub3d.h"
void 	img(int flag, size_t len, unsigned *io)
{
	static unsigned img_data[BL * BL * 4];

	if (flag == SET)
		ft_memcpy(img_data, io, BL * BL * 4);
	else if (flag < 4)
		ft_memcpy(io, img_data + BL * BL * flag + BL * len, BL);
	return ;
}