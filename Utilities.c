/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 18:00:53 by oadewumi          #+#    #+#             */
/*   Updated: 2024/06/08 21:23:47 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

//This is a modified string comare function from my libft without the size
//limitation for comparison. The return value return the difference between
//the two string. if the strings are identical, it returns 0 else it returns 
// the difference to let us know they are a not identical.
int	ft_strcmp(const char *src, const char *dest)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0' && dest[i] != '\0')
	{
		if (src[i] != dest[i])
			return ((unsigned char) src[i] - (unsigned char) dest[i]);
		i++;
	}
	return ((unsigned char) src[i] - (unsigned char) dest[i]);
}

// int	mini_atoi(const char *str)
// {
// 	size_t	output;
// 	int		indx;
// 	int		polarity;

// 	output = 0;
// 	indx = 0;
// 	polarity = 1;
// 	while (str[indx] == 32 || (str[indx] >= 9 && str[indx] <= 13))
// 		indx++;
// 	if (str[indx] == '-' || str[indx] == '+')
// 	{
// 		if (str[indx] == '-')
// 			polarity *= -1;
// 		indx++;
// 	}
// 	output = ft_ret_output(str + indx, polarity);
// 	return (output * polarity);
// }


//This error message utilises the ft_putendl from my Libft, it 
//prints out a string followed by a new line. Also, this function
//is made to print out "Error: "as a prefix to all received strings.
//the file descriptor used is 2, (written to standard error output).
void	error_message(char *str)
{
	write(2, "Error: ", 7);
	ft_putendl_fd(str, 2);
}

//The function below is to check if the inputs are valid
//the perror function bellow is to be tested later.
//perror("Insufficient/Invalid arguments!")
void	validate_input(int argc, char *argv[])
{
	if (argc < 2 || argv[1][0] == '\0')
		error_message("Insufficient/Invalid arguments!");
	if (ft_strcmp(argv[1], "mandelbrot") == 0 && (argc == 3))
	{
		ft_atoi(argv[3]);
	}
	else if (ft_strcmp(argv[1], "julia") == 0 && (argc == 5))
	{
		ft_atoi(argv[3]);
		ft_atoi(argv[4]);
	}
}