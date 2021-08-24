#include <initializers.h>

/*               
    returns new matrix full of zeros                
    Input: int rows, int cols               
    Output: matrix                
*/               
matrix matrixInitializers::zeros(shape InputShape) {               
    matrix m(InputShape);               
    m.fill(0);               
    return m;               
}               
               
/*               
     returns new matrix full of ones                
     Input: int rows, int cols               
     Output: matrix                
 */               
 matrix matrixInitializers::ones(shape matrixShape) {               
     matrix m(matrixShape);               
     m.fill(1);               
     return m;               
 }               
               
               
               
/*               
     returns new matrix full of random values from 0 to 1                
     Input: int rows, int cols               
     Output: matrix                
*/               
 matrix matrixInitializers::randomMatrix(shape matrixShape,int seed ) {               
    matrix m(matrixShape);               
    if (seed >= 0) srand(seed);               
    for (int i = 0; i < m.getRow(); i++)                 
        for (int j = 0; j < m.getCol(); j++)                
            m[i][j] = (float) rand() / RAND_MAX;               
    return m;               
 }               
               
/*               
     returns new matrix full of a chosen value                 
     Input: int rows, int cols , float value              
     Output: matrix                
*/                              
matrix matrixInitializers::full(shape matrixShape,float value) {               
    matrix m(matrixShape);               
    for (int i = 0; i < m.getRow();i++)                
        for (int j = 0; j < m.getCol();j++)               
            m[i][j] = value;               
    return m;               
}

/*               
    returns identity matrix of certien size 
    Input: int matrixSize
    Output: matrix                
*/                              
matrix matrixInitializers::identity(int matrixSize) {               
    matrix m(matrixSize,matrixSize);               
    for (int i = 0; i < m.getRow(); i++) {               
        m[i][i] = 1;               
    }               
    return m;               
}