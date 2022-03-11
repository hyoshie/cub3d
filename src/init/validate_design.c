/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_design.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:18:33 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/11 12:10:48 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants.h"
#include "cub3d.h"

void	validate_design(t_dict *design_dict, t_game *game)
{
	if (!dict_search_item("NO", design_dict)
		|| !dict_search_item("SO", design_dict)
		|| !dict_search_item("WE", design_dict)
		|| !dict_search_item("EA", design_dict)
		|| !dict_search_item("F", design_dict)
		|| !dict_search_item("C", design_dict))
		free_all_exit(EM_MISS_DES, game);
}
