#pragma once 

#include <matrix.h>

namespace operations
{
    matrix dot(matrix& m1,matrix& m2);   
    matrix add(matrix& m1,matrix& m2);
    matrix subtract(matrix& m1, matrix& m2);
    matrix multiplay(matrix& m1,matrix& m2);
    matrix divide(matrix& m1,matrix& m2);    
    matrix add(matrix& m1,float scalar);
    matrix subtract(matrix& m1,float scalar);
    matrix multiplay(matrix& m1,float scalar);
    matrix divide(matrix& m1,float scalar);
}