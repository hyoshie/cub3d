/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_design.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:18:33 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/14 14:55:11 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

bool	exist_all_settings(t_dict *design_dict)
{
	return (dict_search_item("NO", design_dict)
		&& dict_search_item("SO", design_dict)
		&& dict_search_item("WE", design_dict)
		&& dict_search_item("EA", design_dict)
		&& dict_search_item("F", design_dict)
		&& dict_search_item("C", design_dict));
}

void	validate_design(t_dict *design_dict, t_game *game)
{
	if (!exist_all_settings(design_dict))
		free_all_exit(EM_MISS_DES, game);
	if (dict_count(design_dict) > NUM_DESIGN_ELEMS)
		free_all_exit(EM_WRONG_DES, game);
}
