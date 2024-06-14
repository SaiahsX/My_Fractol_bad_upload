/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security_utilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 16:44:32 by oadewumi          #+#    #+#             */
/*   Updated: 2024/06/14 22:43:56 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//This error message utilises the ft_putendl from my Libft, it 
//prints out a string followed by a new line. Also, this function
//is made to print out "Error: "as a prefix to all received strings.
//the file descriptor used is 2, (written to standard error output).
void	error_message(char *str)
{
	write(2, "Error: ", 7);
	ft_putendl_fd(str, 2);
    exit(EXIT_FAILURE);
}

//utilising the perror function with EINVAL error code
void    set_and_perror(const char *msg)
{
    errno = EINVAL;  // Set errno to an appropriate error code
    perror(msg);
    exit (EXIT_FAILURE);
}
