#ifndef __Matrix_h_
#define __Matrix_h_

class EigenvalueSolution;

class Matrix {
public:
    Matrix(int size);
    ~Matrix();

    double& operator()(int row, int col);

    EigenvalueSolution* diagonalize() const;
private:
    int size;
    double* data;
};

#endif
