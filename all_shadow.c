/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_shadow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:20:23 by avella            #+#    #+#             */
/*   Updated: 2016/03/19 15:22:02 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_h.h"

int		my_shadow_cylinder(t_main *main, double v)
{
	double a;
	double b;
	double c;
	double det;

	give_shadow_cyl(main, v);
	a = (pow(main->lum->vx, 2) + pow(main->lum->vy, 2));
	b = (2 * main->lum->vx * main->cyl->xp + 2
			* main->lum->vy * main->cyl->yp);
	c = (pow(main->cyl->xp, 2) + pow(main->cyl->yp, 2)
			- main->cyl->rayon * main->cyl->rayon);
	det = (b * b) - (4 * a * c);
	main->myv1 = (-b - sqrt(det)) / (2 * a);
	main->myv2 = (-b + sqrt(det)) / (2 * a);
	if (main->myv1 > main->myv2 && main->myv2 > 0)
		main->myv1 = main->myv2;
	if (main->myv1 > 0 && main->myv1 < 1)
		return (2);
	return (1);
}

int		my_shadow_conee(t_main *main, double v)
{
	double a;
	double b;
	double c;
	double det;

	give_shadow_cone(main, v);
	a = pow(main->lum->vx, 2) + pow(main->lum->vy, 2)
		- (pow(main->lum->vz, 2) * 0.05);
	b = (2 * main->lum->vx * main->cone->xp) + (2 * main->lum->vy
			* main->cone->yp)
		- ((2 * main->lum->vz * main->cone->zp) * 0.05);
	c = (pow(main->cone->xp, 2) + pow(main->cone->yp, 2)
			- (pow(main->cone->zp, 2) * 0.05));
	det = (b * b) - (4 * a * c);
	main->myv1 = (-b - sqrt(det)) / (2 * a);
	main->myv2 = (-b + sqrt(det)) / (2 * a);
	if (main->myv1 > main->myv2 && main->myv2 > 0)
		main->myv1 = main->myv2;
	if (main->myv1 > 0 && main->myv1 < 1)
		return (2);
	return (1);
}

int		my_shadow_sphere(t_main *main, double v)
{
	double a;
	double b;
	double c;
	double det;

	give_shadow_sphere(main, v);
	a = (pow(main->lum->vx, 2) + pow(main->lum->vy, 2) + pow(main->lum->vz, 2));
	b = 2 * (main->lum->vx * main->sphere->xp + main->lum->vy * main->sphere->yp
			+ main->lum->vz * main->sphere->zp);
	c = (pow(main->sphere->xp, 2) + pow(main->sphere->yp, 2)
			+ pow(main->sphere->zp, 2) - pow(main->sphere->rayon, 2));
	det = (b * b) - (4 * a * c);
	if (det < 0)
		return (1);
	main->myv1 = (-b - sqrt(det)) / (2 * a);
	main->myv2 = (-b + sqrt(det)) / (2 * a);
	if (main->myv1 > main->myv2 && main->myv2 > 0)
		main->myv1 = main->myv2;
	if (main->myv1 > 0 && main->myv1 < 1)
		return (2);
	return (1);
}
