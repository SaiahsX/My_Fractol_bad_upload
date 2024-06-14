/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 18:20:10 by oadewumi          #+#    #+#             */
/*   Updated: 2024/06/14 22:39:45 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <errno.h>
# include <stdlib.h>
# include "./MLX42/include/MLX42/MLX42.h"
# include <math.h>
# include "libft/libft.h"

# define WIDTH 700
# define HEIGHT 700

// typedef struct s_mlx
// {
// 	void		*window;
// 	void		*context;
// 	int32_t		width;
// 	int32_t		height;
// 	double		delta_time;
// }	t_mlx_t;

// typedef void (*mlx_scrollfunc)(double xdelta, double ydelta, void* param);

void	validate_input(int argc, char *argv[]);
int	    ft_strcmp(const char *src, const char *dest);
double  ft_atod(char *str);

//error handling
void	error_message(char *str);
void    set_and_perror(const char *msg);

# endif