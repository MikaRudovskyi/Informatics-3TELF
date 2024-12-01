// Developer m1rskiy - 22.01.2024
#include <iostream>
#include <ctime>
#include <cstdlib>
#define N 5

using namespace std;

void printMatrix(int mat[N][N]) 
{
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
	{
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int countZeros(int mat[N][N]) 
{
    int zeroCount = 0;
    
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
	{
            if (mat[i][j] == 0) 
	    {
                zeroCount++;
            }
        }
    }
    
    return zeroCount;
}

int sumFirstRow(int mat[N][N]) 
{
    int sum = 0;
    
    for (int j = 0; j < N; j++) 
    {
        sum += mat[0][j];
    }
    
    return sum;
}

bool checkCenterSymmetry(int mat[N][N]) 
{
    int center = N / 2;
    
    for (int i = 0; i < N; i++) 
    {
        if (mat[i][center] != mat[center][i]) 
	{
            return false;
        }
    }
    
    return true;
}

bool checkDiagonalSymmetry(int mat[N][N]) 
{
    for (int i = 0; i < N; i++) {
        if (mat[i][i] != mat[i][N - 1 - i]) 
	{
            return false;
        }
    }
    
    return true;
}

int main() 
{    
    int mat[N][N];
    
    srand(time(NULL));
        
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
	{
            mat[i][j] = rand() % 10;
        }
    }
    
    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < N; j++) 
	{
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << endl;
    
    cout << "-----------------------------" << endl;
    cout << "Matrix printed with function:" << endl;
    cout << "-----------------------------" << endl;
    
    cout << endl;
    
    printMatrix(mat);
    
    cout << endl;
    
    int zeroCount = countZeros(mat);
    
    cout << "--------------------------------" << endl;
    cout << "The matrix contains " << zeroCount << " zeros" << endl;
    cout << "--------------------------------" << endl;
    
    int firstRowSum = sumFirstRow(mat);
    
    cout << "-----------------------------------------------" << endl;
    cout << "The sum of the elements in the first row is " << firstRowSum << endl;
    cout << "-----------------------------------------------" << endl;
	
	bool centerSymmetry = checkCenterSymmetry(mat);
	
	cout << "------------------------" << endl;
	cout << "Center symmetry check: " << centerSymmetry << endl;
	cout << "------------------------" << endl;
	
	bool diagonalSymmetry = checkDiagonalSymmetry(mat);
	
	cout << "--------------------------" << endl;
	cout << "Diagonal symmetry check: " << diagonalSymmetry << endl;
	cout << "--------------------------" << endl;
	
	return 0;
}
