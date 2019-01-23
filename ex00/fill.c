/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 16:15:17 by daykim            #+#    #+#             */
/*   Updated: 2019/01/22 23:50:03 by zduan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

int		ft_strcmp(int *s1, int *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
			break ;
		i++;
	}
	return (s1[i] - s2[i]);
}

int		ft_sdkcmp(int **num, int **num2)
{ 
	int i;

	i = 0;
	while (i <= 8)
	{
		if (ft_strcmp(num[i], num2[i]))
			return (0);
		i++;
	}
	return (1);
}

//to fill the cells
int		fillcell(int **num, int pos)
{
	int value;
	int row;
	int col;
 :
	//setting the intervals of range for rows and columns
	row = pos % 9;
	col = pos / 9;

	//when all filled, return true
	if (pos == 81)
		return (1);

	//if the position has been filled, recurred back to the function and move to the next position
	if (num[row][col] != 0)
		return (fillcell(num, pos + 1));

	//start of the loop to fill in the numbers 
	value = 1;
	while (value <= 9)
	{
		if (avlabl(num, pos, value))
		{
			//when valid (pass the 3 Cs)
			//assign the value to the num[][]
			num[row][col] = value;

			//if the position is wrong at the 45th
			//dont restart from position 0 
			//but to move to the next position (position + 1)
			if (fillcell(num, pos + 1))
				return (1);
			else
				num[row][col] = 0;
		}
		value++;
	}
	return (0);
}

//same idea but fill the cells from 9 to 1 to recheck the validity of the numbers to be filled
int		fillcell_rev(int **num, int pos)
{
	int value;
	int row;
	int col;

	row = pos % 9;
	col = pos / 9;
	if (pos == 81)
		return (1);
	if (num[row][col] != 0)
		return (fillcell_rev(num, pos + 1));
	value = 9;
	while (value >= 1)
	{
		if (avlabl(num, pos, value))
		{
			num[row][col] = value;
			if (fillcell_rev(num, pos + 1))
				return (1);
			else
				num[row][col] = 0;
		}
		value--;
	}
	return (0);
}
; 
