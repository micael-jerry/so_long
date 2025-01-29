/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfidimal <mfidimal@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:28:28 by mfidimal          #+#    #+#             */
/*   Updated: 2025/01/29 06:44:23 by mfidimal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map_coordinate find_next_coordinate(t_action_key_code action, t_map_coordinate actual_coord)
{
	t_map_coordinate    new_coord;

    new_coord.x = actual_coord.x;
    new_coord.y = actual_coord.y;
    if (action == MOVE_UP)
		new_coord.y += 1;
	else if (action == MOVE_DOWN)
		new_coord.y -= 1;
	else if (action == MOVE_LEFT)
		new_coord.x -= 1;
	else if (action == MOVE_RIGHT)
		new_coord.x += 1;
	return (new_coord);
}

int	is_valid_move(t_map_coordinate new_p_coord, t_data *data)
{
	if (data->map_data->data[new_p_coord.y][new_p_coord.x] == '0')
		return (1);
    if (data->map_data->data[new_p_coord.y][new_p_coord.x] == 'C')
		return (1);
    if (data->map_data->data[new_p_coord.y][new_p_coord.x] == 'E')
		return (1);
    if (data->map_data->data[new_p_coord.y][new_p_coord.x] == 'T')
		return (1);
    return (0);
}

void	set_map_onemove(t_map_coordinate old, t_map_coordinate new, char old_val, char new_val, t_data *data)
{
	data->map_data->data[new.y][new.x] = new_val;
    data->map_data->data[old.y][old.x] = old_val;
}

void move_player(t_action_key_code action, t_map_coordinate p_coord, t_data *data)
{
	char tmp_p_old_val;
	t_map_coordinate next_p_coord;

	tmp_p_old_val = data->map_data->data[p_coord.y][p_coord.x];
	next_p_coord = find_next_coordinate(action, p_coord);

	if(is_valid_move(next_p_coord, data))
	{
		if (data->map_data->data[next_p_coord.y][next_p_coord.x] == '0')
			set_map_onemove(p_coord, next_p_coord, '0', 'P', data);
		else if (data->map_data->data[next_p_coord.y][next_p_coord.x] == 'C')
			set_map_onemove(p_coord, next_p_coord, '0', 'P', data);
		else if (data->map_data->data[next_p_coord.y][next_p_coord.x] == 'E')
			set_map_onemove(p_coord, next_p_coord, '0', 'T', data);
		if (tmp_p_old_val == 'T')
			set_map_onemove(p_coord, next_p_coord, 'E', 'P', data);
		data->player_move++;
		ft_printf("Move: %d\n", data->player_move);
	}
}

int	action(t_action_key_code action, t_data *data)
{
	t_map_coordinate player_coord;

	if (action == QUIT)
		return (exit_game(data) ,0);
	player_coord = find_coordinate_obj(data->map_data->data, data->map_data->heigth, data->map_data->width, 'P');
	if (player_coord.x == -1 && player_coord.y == -1)
		player_coord = find_coordinate_obj(data->map_data->data, data->map_data->heigth, data->map_data->width, 'T');
	move_player(action, player_coord, data);
	game_render(data);
	return (0);
}

int	key_handler(int keycode, t_data *data)
{
	if (keycode == QUIT || keycode == MOVE_UP || keycode == MOVE_DOWN || keycode == MOVE_LEFT || keycode == MOVE_RIGHT)
		action(keycode, data);
	return (0);
}
