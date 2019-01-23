/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 10:10:39 by daykim            #+#    #+#             */
/*   Updated: 2019/01/22 23:49:53 by zduan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

//take in the binary 
int		**get_input(int argc, char **argv)
{
	int	i;
	int	j;
	int	**num;

	//allocate the binary
	//+1 isn't necessary 
	num = (int **)malloc(sizeof(int *) * 9 + 1);
	
	//start of loop for (int i = 0; i<= 8; i++)
	//for the pointer to the array 
	//"..9.."
	i = 0;
	while (i <= 8)
	{
		//to handle the error when argument is less or more than 10
		//since the acceptable amoutn of argument is 9 + 1
		if (argc != 10)
			return (0);

		//dynamically allocate memory spaces correspondin to user input
		// + 1 is not necessay 
		num[i] = (int *)malloc(sizeof(int) * 9 + 1);
		
		//for the pointer to the pointer to the array
		j = 0;
		while (j <= 8)
		{
			//set range of acceptable numbers for the argv[i]
			//argv[i] is the array that holds 9 chars
			// i + 0 since the argv[0] will be ./a.out 
			if ('1' <= argv[i + 1][j] && argv[i + 1][j] <= '9')
				//converting the numbers from char to int
				num[i][j] = argv[i + 1][j] - '0';
				//convert "." to 0s
			else if (argv[i + 1][j] == '.')
				num[i][j] = 0;
			else
				return (0);
			j++;
		}
		i++;
	}
	//return the input
	// 0 = NULL in the address
	return (num);
}

void	print_sudoku(int **sud)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 8)
	{
		j = 0;
		while (j <= 8)
		{
			//conver the int to char
			ft_putchar(sud[i][j] + '0');
			if (j != 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}	
