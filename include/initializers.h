#pragma once 
#include <matrix.h>

namespace matrixInitializers {
matrix zeros(shape inputShape);
matrix ones(shape inputShape);
matrix randomMatrix(shape inputShape,int seed = -1);

matrix full(shape matrixShape, float value = 0);

matrix identity(int matrixSize);
}