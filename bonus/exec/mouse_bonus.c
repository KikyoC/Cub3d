/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: togauthi <togauthi@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:45:56 by togauthi          #+#    #+#             */
/*   Updated: 2025/04/18 16:49:33 by togauthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../cub3d.h"

int	ft_mouse_leave(t_game *game)
{
	game->handle_mouse = 0;
	return (0);
}

int	ft_mouse_enter(t_game *game)
{
	game->handle_mouse = 1;
	return (0);
}
