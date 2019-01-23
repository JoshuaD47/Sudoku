/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daykim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/19 11:41:50 by daykim            #+#    #+#             */
/*   Updated: 2019/01/22 23:49:56 by zduan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "files.h"

//algorithm to check the validity of the numbers to fill in 
int	avlabl(int **num, int pos, int dgt)
{
	int rowsec;
	int colsec;
	int i;
	int row;
	int col;

	//setting the range of the interval
	row = pos % 9;
	col = pos / 9;

	//setting the range of the settor
	//need to be initailized
	rowsec = (row / 3) * 3;
	colsec = (col / 3) * 3;

	//start of the loop to validfy the numbers 
	i = 0;
	while (i <= 8)
	{
		//start checking the row
		//start checking the colum
		if (num[row][i] == dgt || num[i][col] == dgt)
			return (0);
		
		//starting checking the settor
		// i / 3 to set the intervals [0,1,2] when i is from 0 to 8
		//  i % 3 to set the intervals [0,1,2] when i is from 0 to 8
		if (num[rowsec + (i / 3)][colsec + (i % 3)] == dgt)
			return (0);
		i++;
	}
	return (1);
}
