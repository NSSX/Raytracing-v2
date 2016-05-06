/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:30:12 by avella            #+#    #+#             */
/*   Updated: 2016/03/19 15:30:44 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_h.h"

void	parcour_all(t_main *main)
{
	int i;
	int j;
	int mypixelcolor;

	mypixelcolor = 0;
	j = 0;
	while (j < HEIGHT)
	{
		i = 0;
		while (i < WIDTH)
		{
			mypixelcolor = definee_color(i, j, main);
			if (mypixelcolor != 0)
			{
				my_pixel_put_to_image2(main->img, i, j, mypixelcolor);
			}
			i++;
		}
		j++;
	}
}
