### Description of the Code:

1. Header and Namespace:
   - `#include <iostream>`: Includes the iostream library to allow input and output operations.
   - `using namespace std;`: Uses the standard namespace to avoid prefixing standard library names with `std::`.

2. Function Declarations:
   - `void fillMatAlt(int matrix[][100], int N);`: Declares a function to fill the matrix alternately with 0s and 1s.
   - `void fillMatDiag(int matrix[][100], int N);`: Declares a function to fill the diagonals of the matrix with 1s.
   - `void printMat(int matrix[][100], int N);`: Declares a function to print the matrix.

3. Main Function:
   - Prompts the user to enter the size `N` of an NxN matrix.
   - Defines a 100x100 matrix `mat`.
   - Calls `fillMatAlt` to fill the matrix with alternating 0s and 1s.
   - Prints the matrix.
   - Calls `fillMatDiag` to fill the diagonals of the matrix with 1s.
   - Prints the matrix again.
   - Returns 0 to indicate successful execution.

4. fillMatAlt Function:
   - Fills the matrix such that elements are alternately 0 and 1 based on the sum of their row and column indices.

5. fillMatDiag Function:
   - Fills the primary and secondary diagonals of the matrix with 1s.

6. printMat Function:
   - Prints the matrix row by row, with each element separated by a space.
   - Prints an empty line after printing the matrix.

This code effectively creates and manipulates a square matrix of size `N`, filling it first with an alternating pattern and then with 1s on its diagonals, printing the matrix after each modification.