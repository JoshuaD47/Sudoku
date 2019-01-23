
#include "files.h"

int main(int argc, char **argv)
{
	int **num;
	int **num2;

	//pass the input into num and num2
	//use two to compare later
	num = get_input(argc, argv);
	num2 = get_intput(argc, argv);
	
	//to handle if the str is empty
	if (num == 0)
		write (1, "Error\n", 6);

	//if num is not empty
	//start filling in the cells by using fillcell() from 1 to 9 and pass to num
	else if (fillcell(num, 0))
	{
		//filling in the cells by using fillcell_rev() from 9 to 1 and pass to num2
		fillcell_rev(num2, 0);

		//to compare if num and num2 are identical
		if(ft_sdkcmp(num, num2)
				//if identical, the solution is one and valid
				//print the solution
				print_sudoku(num);
		else
			//otherwise print error since there are two solutions
			write(1, "Error\n", 6);
	}
	else
	//if the fillcell return false
	//
	write (1 , "Error\n", 6);
	return(0);
}			
