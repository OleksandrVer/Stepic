//The swap_min function takes a two - dimensional array of integers as input, 
//searches in this array for the row containing the smallest value among all the array elements, 
//and swaps this row with the first row of the array.
//Think about how to swap the rows of an array without swapping the elements of the rows individually.

void swap_min(int* m[], unsigned rows, unsigned cols)
{
	int min = m[0][0], min_row = 0;
	for (unsigned i = 0; i < rows; ++i)
	{
		for (unsigned j = 0; j != cols; ++j)
		{
			if (min > m[i][j])
			{
				min = m[i][j];
				min_row = i;
			}
		}
	}
	int* swap = m[0];
	m[0] = m[min_row];
	m[min_row] = swap;
}
