/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 13:58:33 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/17 14:00:41 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	get_angle(double direction, int key)
{
	double	angle;

	angle = direction;
	if (key == KEY_S)
		angle += M_PI;
	else if (key == KEY_A)
		angle -= 0.5 * M_PI;
	else if (key == KEY_D)
		angle += 0.5 * M_PI;
	return (angle);
}
