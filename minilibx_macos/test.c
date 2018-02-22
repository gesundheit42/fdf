#include "mlx.h"

int	main()
{
	void	*ptr;
	void	*wdw;

	ptr = mlx_init();
	wdw = mlx_new_window(ptr, 1000, 1000, "test");
	mlx_pixel_put(ptr, wdw, 250, 250, 0xff0000);
	mlx_loop(ptr);
}
