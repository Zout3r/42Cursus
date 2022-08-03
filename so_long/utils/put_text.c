/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_text.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperez-p <jperez-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 15:48:10 by jperez-p          #+#    #+#             */
/*   Updated: 2022/08/03 14:58:45 by jperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_text(t_vars ***v)
{
	char	*text;
	char	*number;

	number = ft_itoa(++(**v)->movement);
	text = ft_strjoin("Move ", number);
	(**v)->img = mlx_load_png("./img/muro.png");
	(**v)->img = mlx_texture_to_image((**v)->mlx, (**v)->img);
	mlx_image_to_window((**v)->mlx, (**v)->img, 0, 0);
	mlx_image_to_window((**v)->mlx, (**v)->img, 50, 0);
	mlx_image_to_window((**v)->mlx, (**v)->img, 50 * 2, 0);
	mlx_put_string((**v)->mlx, text, 5, 10);
	ft_printf("%s\n", number);
	free(text);
	free(number);
}