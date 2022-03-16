/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_design_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:18:33 by yshimazu          #+#    #+#             */
/*   Updated: 2022/03/16 11:08:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "constants_bonus.h"
#include "cub3d_bonus.h"

static size_t	count_commas(t_dict *design_dict, char *key)
{
	size_t	num_commas;
	char	*color_str;

	num_commas = 0;
	color_str = dict_get_value(key, design_dict);
	while (*color_str)
	{
		if (ft_strchr(",", *color_str))
			num_commas++;
		color_str++;
	}
	return (num_commas);
}

static bool	exist_all_settings(t_dict *design_dict)
{
	return (dict_search_item("NO", design_dict)
		&& dict_search_item("SO", design_dict)
		&& dict_search_item("WE", design_dict)
		&& dict_search_item("EA", design_dict)
		&& dict_search_item("F", design_dict)
		&& dict_search_item("C", design_dict));
}

void	validate_design(t_dict *design_dict)
{
	if (!exist_all_settings(design_dict))
		error_exit(EM_MISS_DES);
	if (dict_count(design_dict) > NUM_DESIGN_ELEMS)
		error_exit(EM_WRONG_DES);
	if (count_commas(design_dict, "F") > 2
		|| count_commas(design_dict, "C") > 2)
		error_exit(EM_DESIGN);
}
