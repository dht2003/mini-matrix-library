#include <matrixOperations.h>

/*
    Dot product
    Input: matrix& m1, matrix& m2
    Output: Return the result matrix from the dot product 
*/
matrix operations::dot(matrix& m1,matrix& m2) {
    if (m1.getCol() != m2.getRow()) throw std::logic_error("Invalid matrices shape for this operation\n");
    matrix result(m1.getRow(),m2.getCol()); 
    for (int i = 0; i < m1.getRow();i++) 
        for (int j = 0; j < m2.getCol();j++) 
            for (int k = 0; k < m1.getCol(); k++)  
                result[i][j] += m1[i][k] * m2[k][j];
    return result;
}


/*
    Element wise addition 
    Input: matrix& m1, matrix& m2
    Output: The result matrix of the element wise addition
*/
matrix operations::add(matrix& m1,matrix& m2) {
    checkSize(m1,m2);
    matrix m(m1.getRow(),m1.getCol());
    for (int i = 0; i < m1.getRow();i++) {
        for (int j = 0; j < m1.getCol();j++) {
            m[i][j] = m1[i][j] + m2[i][j];
        }
    }
    return m;
}

/*
    Element wise subtraction
    Input: matrix& m1, matrix& m2
    Output: The result matrix of the element wise subtraction
*/
matrix operations::subtract(matrix& m1,matrix& m2) {
    checkSize(m1,m2);
    matrix m(m1.getRow(),m1.getCol());
    for (int i = 0; i < m1.getRow();i++) {
        for (int j = 0; j < m1.getCol();j++) {
            m[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return m;
}


/*
    Element wise multiplication 
    Input: matrix& m1, matrix& m2
    Output: The result matrix of the element wise multiplication
*/
matrix operations::multiplay(matrix& m1,matrix& m2) {
    
    matrix m(m1.getRow(),m1.getCol());
    for (int i = 0; i < m1.getRow();i++) {
        for (int j = 0; j < m1.getCol();j++) {
            m[i][j] = m1[i][j] * m2[i][j];
        }
    }
    return m; 
}

/*
    Element wise division 
    Input: matrix& m1, matrix& m2
    Output: The result matrix of the element wise division
*/
matrix operations::divide(matrix& m1,matrix& m2) {
    checkSize(m1,m2);
    matrix m(m1.getRow(),m1.getCol());
    for (int i = 0; i < m1.getRow();i++) {
        for (int j = 0; j < m1.getCol();j++) {
            if (m2[i][j] == 0) throw std::runtime_error("Math error: Attempted to divide by Zero\n");
            m[i][j] = m1[i][j] / m2[i][j];
        }
    }
    return m; 
}


/*
    Element wise addition  with a scalar 
    Input: matrix& m1, float scalar
    Output: The result matrix of the element wise addition
*/
matrix operations::add(matrix& m1,float scalar) {
    matrix m(m1.getRow(),m1.getCol());
    for (int i = 0; i < m1.getRow();i++) {
        for (int j = 0; j < m1.getCol();j++) {
            m[i][j] = m1[i][j] + scalar;
        }
    }
    return m;
}

/*
    Element wise subtraction with scalar 
    Input: matrix& m1, float scalar
    Output: The result matrix of the element wise subtraction
*/
matrix operations::subtract(matrix& m1,float scalar) {
    matrix m(m1.getRow(),m1.getCol());
    for (int i = 0; i < m1.getRow();i++) {
        for (int j = 0; j < m1.getCol();j++) {
            m[i][j] = m1[i][j] - scalar;
        }
    }
    return m;
}

/*
    Element wise multiplication  with scalar
    Input: matrix& m1, float scalar
    Output: The result matrix of the element wise multiplication
*/
matrix operations::multiplay(matrix& m1,float scalar) {
    
    matrix m(m1.getRow(),m1.getCol());
    for (int i = 0; i < m1.getRow();i++) {
        for (int j = 0; j < m1.getCol();j++) {
            m[i][j] = m1[i][j] * scalar;
        }
    }
    return m; 
}


/*
    Element wise division by scalar 
    Input: matrix& m1, float scalar
    Output: The result matrix of the element wise division
*/
matrix operations::divide(matrix& m1,float scalar) {
    if (scalar == 0) throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    matrix m(m1.getRow(),m1.getCol());
    for (int i = 0; i < m1.getRow();i++) 
        for (int j = 0; j < m1.getCol();j++) 
            m[i][j] = m1[i][j] / scalar;
    return m; 
}