//This function takes an integer matrix M(in other words, just a two - dimensional integer array)
//of size rows * cols as input, and returns the transposed matrix TM
//(also a two - dimensional integer array) of size cols * rows. 
//If in M at the intersection of the i-th row and j-th column there was a number x, 
//then at the intersection of the j-th row and i-th column in the matrix TM
//will also be the number x, or in other words M[j][i] = TM[i][j]


int** transpose_(const int* const* m, unsigned rows, unsigned cols)
{
    int** new_m = new int* [cols];
    new_m[0] = new int[cols * rows];
    for (unsigned i = 1; i < cols; ++i)
    {
        new_m[i] = new_m[i - 1] + rows;
    }
    for (unsigned i = 0; i < cols; ++i)
    {
        for (unsigned j = 0; j < rows; ++j)
        {
            new_m[i][j] = m[j][i];
        }
    }
    return new_m;
}