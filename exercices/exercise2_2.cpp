#include <iostream>
#include <iomanip> 

int **initialize_matrix(int num_rows, int num_cols)
{
    int **matrix = new int *[num_rows];
    for (int i = 0; i < num_rows; ++i)
    {
        matrix[i] = new int[num_cols];
    }

    return matrix;
}

void print_matrix(int **matrix, int num_rows, int num_cols)
{
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            std::cout << std::right << std::setw(5)  << matrix[i][j];
        }
        std::cout << "\n";
    }
}

void fill_matrix(int **matrix, int num_rows, int num_cols)
{
    for (int i = 0; i < num_rows; i++)
    {
        for (int j = 0; j < num_cols; j++)
        {
            matrix[i][j] = i*num_cols + j;
        }
    }
}

int main()
{
    int num_rows = 3;
    int num_cols = 10;

    std::cout << "Initializing matrix...\n";
    int **matrix = initialize_matrix(num_rows, num_cols);
    std::cout << "Filling matrix...\n";
    fill_matrix(matrix, num_rows, num_cols);
    std::cout << "Displaying matrix:\n\n";
    print_matrix(matrix, num_rows, num_cols);

    return 0;
}