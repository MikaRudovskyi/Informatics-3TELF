// Developer m1rskiy - 09.04.2024
#include <iostream>

using namespace std;

void fillMatAlt(int matrix[][100], int N);

void fillMatDiag(int matrix[][100], int N);

void printMat(int matrix[][100], int N);

int main() 
{
    int N;
    
    cout << "Enter the size of the NxN matrix: ";
    
    cin >> N;

    int mat[100][100];

    fillMatAlt(mat, N);
    
    cout << "Matrix filled alternately: " << endl;
    
    printMat(mat, N);

    fillMatDiag(mat, N);
    
    cout << "Matrix filled with 1 on diagonals: " << endl;
    
    printMat(mat, N);

    return 0;
}

void fillMatAlt(int mat[][100], int N) 
{
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            mat[i][j] = (i + j) % 2;
        }
    }
}

void fillMatDiag(int mat[][100], int N) 
{
    for (int i = 0; i < N; ++i) 
    {
        mat[i][i] = 1;
        mat[i][N - 1 - i] = 1;
    }
}

void printMat(int mat[][100], int N) 
{
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < N; ++j) 
        {
            cout << mat[i][j] << " ";
        }
        
        cout << endl;
    }
    
    cout << endl;
}
