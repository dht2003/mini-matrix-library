#pragma once 

#include <iostream>
#include <vector>
#include <array>

typedef std::array<int,2> shape;

class matrix {
    private:
        int m_rows,m_cols;
        std::vector<std::vector<double>> m;
        void resize(shape newMatrixShape);
        
    public:
        matrix();
        matrix(const matrix& m1);
        matrix(int rows,int cols) ;
        matrix(shape matrixShape);
        matrix(std::vector<std::vector<double>> v);
        int getCol() const;
        int getRow() const;
        double getValue(int row,int col) const;
        void setValue(int row,int col,double newValue);
        std::vector<std::vector<double>> getMatrix() const;
        std::vector<std::vector<double>>& getMatrix();
        void setMatrix(std::vector<std::vector<double>> v);
        void display() const;
        matrix transpose();
        void showSize() const;
        void fill(double scalar);

    std::vector<double>& operator[](int index);
    std::vector<double> operator[](int index) const;
    friend matrix operator+(matrix& m1,matrix& m2);
    friend matrix operator-(matrix& m1, matrix& m2);
    friend matrix operator*(matrix& m1,matrix& m2);
    friend matrix operator/(matrix& m1,matrix& m2);    
    friend matrix operator+(matrix& m1,double scalar);
    friend matrix operator-(matrix& m1,double scalar);
    friend matrix operator*(matrix& m1,double scalar);
    friend matrix operator/(matrix& m1,double scalar);

    matrix& operator=(matrix& other);
    matrix& operator+=(matrix& other);   
    matrix& operator-=(matrix& other);
    matrix& operator*=(matrix& other);
    matrix& operator/=(matrix& other);
    matrix& operator+=(double scalar);   
    matrix& operator-=(double scalar);
    matrix& operator*=(double scalar);
    matrix& operator/=(double scalar);
    friend void checkSize(matrix& m1 ,matrix& m2);
    friend std::ostream& operator<<(std::ostream& os,const matrix& m); 
};









