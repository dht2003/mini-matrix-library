#include "matrix.h"
#include "initializers.h"
#include "matrixOperations.h"


int main() {
    matrix matrix1({{1,2,3},{3,4,5}});
    matrix matrix2({{6,7,8},{9,10,11}});
    std::cout << "matrix 1:" << std::endl;
    std::cout << matrix1 << std::endl;
    std::cout << "matrix 2: " << std::endl;
    std::cout << matrix2 << std::endl;
    std::cout << "matrix addition: " << std::endl;
    std::cout << matrix1 + matrix2 << std::endl;

    std::cout << "matrix subtraction:" << std::endl;
    std::cout << matrix2 - matrix1 << std::endl;

    std::cout << "element wise multiplication:" << std::endl;
    std::cout << matrix1 * matrix2 << std::endl;

    std::cout << "element wise division: " << std::endl;
    std::cout << matrix2 / matrix1 << std::endl;

    matrix dot1({{1,2,3},{4,5,6}});
    matrix dot2({{7,8,9},{10,11,12},{13,14,15}});
    std::cout << "matrix dot product: " << std::endl;
    std::cout << operations::dot(dot1,dot2);
}