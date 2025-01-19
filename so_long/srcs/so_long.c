/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:06:55 by codespace         #+#    #+#             */
/*   Updated: 2025/01/19 11:35:01 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

#define WIDTH 500
#define HEIGHT 500

int	main(int argc, char *argv[])
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_new_window(mlx_ptr, WIDTH, HEIGHT, "MLX_SO_LONG");
	mlx_loop(mlx_ptr);
}
