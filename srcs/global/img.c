#include "../cub3d.h"
void 	img(int flag, size_t len, unsigned *io)
{
	static unsigned img_data[BL * BL * 4];


//TESTn(flag)
//TESTn(len)
//TESTp(io)

if (len >= BL)
{
	//TESTn(len) STOP
}
	if (flag == SET)
		ft_memcpy(img_data, io, BL * BL * 4 * sizeof(unsigned));
	else if (flag < 4 && flag >= 0)
		ft_memcpy(io, img_data + (BL * BL * flag) + (BL * len), BL * sizeof(unsigned));
else
{
	//TEST STOP
}
	return ;
}