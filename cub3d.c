/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpimenta <mpimenta@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:32:24 by mpimenta          #+#    #+#             */
/*   Updated: 2023/06/05 11:13:19 by mpimenta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub3d.h"

int main(int argc, char **argv)
{
    t_game cub;
    
    if (!validation_file(argc, argv))
        return (0);
    init(&cub);
    map_analyze(argv[1], &cub);
    return (0);
}