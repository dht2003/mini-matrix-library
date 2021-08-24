#include "matrix.h"

/* 
    defult constructor for matrix
*/
matrix::matrix() {
    m_rows = 0;
    m_cols = 0;
}

/*
    copy constructor for matrix
*/
matrix::matrix(const matrix& m1) {
    m_rows = m1.getRow();
    m_cols = m1.getCol();
    m = m1.getMatrix();
}

/*
    constructor for matrix which sets up 
    matrix with a certian size
    Input: int rows, int cols
    Output : none
*/
matrix::matrix(int rows,int cols) {
    m_rows = rows;
    m_cols = cols;
    m.resize(getRow(),std::vector<double>(getCol()));
}

matrix::matrix(shape matrixShape) {
    m_rows = matrixShape[0];
    m_cols = matrixShape[1];
    m.resize(getRow(),std::vector<double>(getCol()));
}

/*
    matrix constructor which sets up a matrix 
    from a vector of vectors 
    Input: vector<vector<double>> v 
    Output : none
*/
matrix::matrix(std::vector<std::vector<double>> v) {
    m = v;
    m_rows = v.size();
    m_cols = v[0].size();
}

// returns the number of columns 
int matrix::getCol() const {return m_cols;}

// returns the number of rows
int matrix::getRow() const {return m_rows;}

/*
    Resizes matrix to a new specified size 
    Input: int rows, int cols
    Output: None
*/
void matrix::resize(shape newMatrixShape) {
    m_rows = newMatrixShape[0];
    m_cols = newMatrixShape[1];
    this->m.resize(m_rows,std::vector<double>(m_cols));
}

/* 
    Checks if size of matrices match 
    if it does not match , the function throws 
    expectation accordingly 
    Input: matrix& m1, matrix& m2
    Output : None
*/
void checkSize(matrix& m1, matrix& m2) {
    if (m1.getRow() == 0 || m2.getCol() == 0 || m1.getCol() == 0 || m2.getRow() == 0) 
        throw std::logic_error("Operation on an empty matrix");
    if (m1.getRow() != m2.getRow() || m1.getCol() != m2.getCol())
        throw std::logic_error("The 2 matrices are not the same size");
}

// returns matrix
std::vector<std::vector<double>> matrix::getMatrix() const{
    return m;
}

// return refernce to matrix
std::vector<std::vector<double>>& matrix::getMatrix() {
    return m;
}

/*
    Sets up a matrix from a vector of vectors
    Input : vector<vector<double>> v
    Output : None
*/
void matrix::setMatrix(std::vector<std::vector<double>> v) {
    m = v;
    m_rows = v.size();
    m_cols = v[0].size();
}

/*
    Gets the scalar in a specified row and column 
    from the matrix
    Input: int row, int col
    Output: m[row][col] - scalar from matrix
*/
double matrix::getValue(int row,int col) const{
    if (row >= getRow() || col >= getCol()) throw std::out_of_range("Index is out of matrix");
    return m[row][col];
}

/*
    Change scalar of an element inside the matrix 
    in a specific row and column 
    Input: int row, int col,double newValue
    Output: None
*/
void matrix::setValue(int row,int col,double newVal) {
    if (row >= getRow() || col >= getCol()) throw std::out_of_range("Index is out of matrix");
    m[row][col] = newVal;
}

/*
    Return a vector in a certien index
    Input: int index
    Output: m[index] - Reference to the vector in the index'th row
*/
std::vector<double>& matrix::operator[](int index) {
    if (index >= getRow()) throw std::out_of_range("Index is out of matrix");
    return m[index];
}

/*
    Return a refernce to a vector in a certien index
    Input: int index
    Output: m[index] - The vector in the index'th row
*/
std::vector<double> matrix::operator[] (int index) const {
    if (index >= getRow()) throw std::out_of_range("Index is out of matrix");
    return m[index];
}

/*
    Element wise addition 
    Input: matrix& m1, matrix& m2
    Output: The result matrix of the element wise addition
*/
matrix operator+(matrix& m1,matrix& m2) {
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
matrix operator-(matrix& m1,matrix& m2) {
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
    prints the matrix 
*/
void matrix::display() const {
    for (int i = 0; i < getRow();i++) {
        for (int j = 0; j < getCol();j++) 
            std::cout << getValue(i,j) << ",";
        std::cout << std::endl;
    }
}

/*
    prints the size of the matrix 
*/
void matrix::showSize() const {
    std::cout << getRow() << "X" << getCol() << std::endl;
}

/*
    assigns a matrix to another matrix 
    Input: matrix& other
    Output: A reference to the newly assigned matrix
*/
matrix& matrix::operator=(matrix& other) {
    resize({getRow(),getCol()});
    for (int i = 0;i < getRow();i++) 
        for (int j = 0; j < getCol();i++) {
            setValue(i,j,other[i][j]);
        }
    return *this;
}
/*
    Element wise multiplication 
    Input: matrix& m1, matrix& m2
    Output: The result matrix of the element wise multiplication
*/
matrix operator*(matrix& m1,matrix& m2) {
    
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
matrix operator/(matrix& m1,matrix& m2) {
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
    Input: matrix& m1, double scalar
    Output: The result matrix of the element wise addition
*/
matrix operator+(matrix& m1,double scalar) {
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
    Input: matrix& m1, double scalar
    Output: The result matrix of the element wise subtraction
*/
matrix operator-(matrix& m1,double scalar) {
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
    Input: matrix& m1, double scalar
    Output: The result matrix of the element wise multiplication
*/
matrix operator*(matrix& m1,double scalar) {
    
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
    Input: matrix& m1, double scalar
    Output: The result matrix of the element wise division
*/
matrix operator/(matrix& m1,double scalar) {
    if (scalar == 0) throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    matrix m(m1.getRow(),m1.getCol());
    for (int i = 0; i < m1.getRow();i++) 
        for (int j = 0; j < m1.getCol();j++) 
            m[i][j] = m1[i][j] / scalar;
    return m; 
}


/*
    transposes a matrix
    Input: None
    Output: The transposed matrix
*/
matrix matrix::transpose() {
    matrix transposed(getCol(),getRow());
    for (int i = 0; i < getCol();i++) 
        for (int j = 0; j < getRow();j++) 
            transposed[i][j] = getValue(j,i);
    return transposed;
}

/*
    Assignment with element wise addition 
    Input: matrix& other
    Output: A reference to the result matrix of the element wise addition
*/
matrix& matrix::operator+=(matrix& other) {        
    checkSize(*this,other);
    for (int i = 0;i < getRow();i++) 
        for (int j = 0; j < getCol();j++) 
           setValue(i,j,this->m[i][j] + other[i][j]);
    return *this;
}


/*
    Assignment with element wise multiplication 
    Input: matrix& other
    Output: A reference to the result matrix of the element wise multiplication
*/
matrix& matrix::operator*=(matrix& other) {        
    checkSize(*this,other);
    for (int i = 0;i < getRow();i++) 
        for (int j = 0; j < getCol();j++) 
           setValue(i,j,this->m[i][j] * other[i][j]);
    return *this;
}

/*
    Assignment with element wise subtraction 
    Input: matrix& other
    Output: A reference to the result matrix of the element wise subtraction
*/
matrix& matrix::operator-=(matrix& other) {        
    checkSize(*this,other);
    for (int i = 0;i < getRow();i++) 
        for (int j = 0; j < getCol();j++) 
           setValue(i,j,this->m[i][j] - other[i][j]);
    return *this;
}

/*
    Assignment with element wise division 
    Input: matrix& other
    Output: A reference to the result matrix of the element wise division
*/
matrix& matrix::operator/=(matrix& other) {        
    checkSize(*this,other);
    for (int i = 0;i < getRow();i++) 
        for (int j = 0; j < getCol();j++) { 
           if (other[i][j] == 0) throw std::runtime_error("Math error: Attempted to divide by Zero\n");
           setValue(i,j,this->m[i][j] / other[i][j]);
        }
    return *this;
}

/*
    Assignment with element wise addition by a scalar
    Input: double scalar
    Output: A reference to the result matrix of the element wise addition
*/
matrix& matrix::operator+=(double scalar) {        
    for (int i = 0;i < getRow();i++) 
        for (int j = 0; j < getCol();j++) 
           setValue(i,j,this->m[i][j] + scalar);
    return *this;
}


/*
    Assignment with element wise multiplication by a scalar 
    Input: double scalar
    Output: A reference to the result matrix of the element wise multiplication
*/
matrix& matrix::operator*=(double scalar) {        
    for (int i = 0;i < getRow();i++) 
        for (int j = 0; j < getCol();j++) 
           setValue(i,j,this->m[i][j] * scalar);
    return *this;
}

/*
    Assignment with element wise subtraction  by a scalar
    Input: double scalar
    Output: A reference to the result matrix of the element wise subtraction
*/
matrix& matrix::operator-=(double scalar) {        
    for (int i = 0;i < getRow();i++) 
        for (int j = 0; j < getCol();j++) 
           setValue(i,j,this->m[i][j] - scalar);
    return *this;
}

/*
    Assignment with element wise division  by a scalar
    Input: double scalar
    Output: A reference to the result matrix of the element wise division
*/
matrix& matrix::operator/=(double scalar) {        
    if (scalar == 0) throw std::runtime_error("Math error: Attempted to divide by Zero\n");
    for (int i = 0;i < getRow();i++) 
        for (int j = 0; j < getCol();j++)  
           setValue(i,j,this->m[i][j] / scalar);
    return *this;
}



/*
    Fills matrix with specified scalar 
    Input: double scalar 
    Output: None
*/
void matrix::fill(double scalar) {
    for (int i = 0; i < getRow();i++)
        for (int j = 0; j < getCol(); j++) 
            m[i][j] = scalar;
}

std::ostream& operator<<(std::ostream& os,const matrix& m) {
    for (int i = 0; i < m.getRow();i++) {   
        for (int j = 0; j < m.getCol();j++) 
            os << m.getValue(i,j) << ",";
        os << std::endl;
    }
    return os;
}



















































