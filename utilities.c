/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oadewumi <oadewumi@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:10:01 by oadewumi          #+#    #+#             */
/*   Updated: 2024/06/14 22:43:17 by oadewumi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double  ft_set_double(char *str)
{
    double  output;
    double  denom;

    output = 0.0;
    denom = 1.0;
    
    while (*str != '.' && ft_isdigit((unsigned char)*str) && *str != '\0')
    {
        output *= 10.0;
        output += (*str++ - '0');
    }
    if (*str == '.')
    {
        str ++;
        while (ft_isdigit((unsigned char)*str) && *str != '\0')
        {
            denom *= 10.0;
            output = output + (*str++ - '0') / denom;
        }
    }
    return (output);
}

double ft_atod(char *str)
{
    double  output;
    int		indx;
	int		polarity;

	output = 0;
	indx = 0;
	polarity = 1;
	if (str[indx] == '-')
	{
		polarity *= -1;
		indx++;
	}
	output = ft_set_double(str + indx);
	return (output * polarity);  
}

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

//The function below is to check if the inputs are valid
//the perror function bellow is to be tested later.
//perror("Insufficient/Invalid arguments!")
void	validate_input(int argc, char *argv[])
{
	if (argc < 2 || argv[1][0] == '\0')
		error_message("Insufficient/Invalid arguments!");
	if (ft_strncmp(argv[1], "mandelbrot", 10) == 0 && (argc == 3))
	{
		ft_atoi(argv[3]);
	}
	else if (ft_strncmp(argv[1], "julia", 5) == 0 && (argc == 5))
	{
		ft_atoi(argv[3]);
		ft_atoi(argv[4]);
	}
}
