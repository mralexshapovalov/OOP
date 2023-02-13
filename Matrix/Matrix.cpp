// Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>
class Matrix;

Matrix operator+(const Matrix&left, const Matrix& right);
Matrix operator-(const Matrix& left, const Matrix& right);
Matrix operator*(const Matrix& left, const Matrix& right);
Matrix operator/(const Matrix& left, const Matrix& right);

class Matrix
{

private:
    int ROWS, COLS;
    int** matrix;

public:

    int get_sizeRow() const
    {
        return ROWS;
    }

    int get_sizeCol() const
    {
        return COLS;
    }

    int** get_matrix()
    {
        return matrix;
    }

    int** get_matrix()const
    {
        return matrix;
    }


   /* Matrix( int rows=6,  int cols=6) :ROWS(rows), COLS(cols), matrix(new int* [rows] {})
    {
        std::cout << "DefConstructor\t" << this << std::endl;
    }*/


    Matrix(const int rows, const int cols):ROWS(rows), COLS(cols), matrix(new int* [rows] {})
    {
        for (int i = 0; i < rows; i++)
        {
            matrix[i] = new int [rows];

            for (int j = 0; j < cols; j++)

                /*       this->matrix[i][j]=matrix[i][j];*/

                matrix[i][j] = 1+ rand() % 50;  //Происходит переполнение буфера...ХЗ 
           

        }
        std::cout << "1ArgConstuctor " << this << std::endl;
    }


    ~Matrix()
    {
        for (int i = 0; i < ROWS; i++) 
        
            delete[] matrix[i];         //деструктор удаляет из памяти динамический массив, созданный конструктором

        delete[] matrix;

        std::cout << "Destructor\t" << this << std::endl;
    }

    Matrix& operator+=(const Matrix& other)
    {
        return *this = *this + other;
    }

    Matrix& operator-=(const Matrix& other)
    {
        return *this = *this + other;
    }

    Matrix& operator*=(const Matrix& other)
    {
        return *this = *this + other;
    }

    Matrix& operator/=(const Matrix& other)
    {
        return *this = *this + other;
    }

    Matrix& Sort() 
    {
        int emptyValue;

        for (int k = 0; k < ROWS; ++k) {

            for (int l = 0; l < COLS; ++l)
            {
                for (int i = 0; i < ROWS; ++i)
                {
                    for (int j = 0; j < COLS; ++j)
                    {
                        if (matrix[i][j] > matrix[k][l])
                        {
                            emptyValue = matrix[i][j];
                            matrix[i][j] = matrix[k][l];
                            matrix[k][l] = emptyValue;
                        }
                    }
                }
            }
        }
        return *this;
    }
    /*Matrix& Search()
    {

            for (int i = 0; i < row; i++)
            {
            for (int j = 0; j < col; j++)
            {
                for (int l = i; l < row; l++)
                {
                    for (int k = j + 1; k < col; k++)

                        if (matrix[i][j] == matrix[l][k])
                        {
                            std::cout << "mass[" << i << "][ " << j << "] == mass[ " << l << "][" << k << "]" << matrix[i][j] << std::endl;
                        }

                }
            }
        }
        
        
    }*/

    void print()const
    {
        std::cout << "Size:\t" << ROWS<<"\t" << COLS << std::endl;
        std::cout << "matrix:\t" << matrix << std::endl;

        for (int i = 0; i < ROWS; i++)
        {
            for (int j = 0; j < COLS; j++)
            {
                std::cout << matrix[i][j]<<"\t";
            }
            std::cout <<std::endl;
        }
        std::cout << this << std::endl;
    }

    int& operator()(int i, int j)//перегрузка круглых скобок для матрицы.
    {                             // Если m - матрица, то m(i,j) будет
        return matrix[i][j];  //означать i,j-тый элемент матрицы
    }

    int operator()(int i, int j) const//перегрузка круглых скобок для матрицы.
    {                             // Если m - матрица, то m(i,j) будет
        return matrix[i][j];  //означать i,j-тый элемент матрицы
    }

};

Matrix operator+( const Matrix& left,  const Matrix& right)
{
    Matrix temp(left.get_sizeRow(), left.get_sizeCol());

    for (int i = 0; i < left.get_sizeRow(); i++)
        for (int j = 0; j < left.get_sizeCol(); j++)
            temp.get_matrix()[i][j] = left.get_matrix()[i][j] + right.get_matrix()[i][j];
    temp.print();

    return temp;
}

Matrix operator-(const Matrix& left, const Matrix& right)
{
    Matrix temp(left.get_sizeRow(), left.get_sizeCol());
    for (int i = 0; i < left.get_sizeRow(); i++)
        for (int j = 0; j < left.get_sizeCol(); j++)
            temp.get_matrix()[i][j] = left.get_matrix()[i][j] - right.get_matrix()[i][j];
    temp.print();

    return temp;
}

Matrix operator*(const Matrix& left, const Matrix& right)
{
    Matrix temp(left.get_sizeRow(), left.get_sizeCol());
    for (int i = 0; i < left.get_sizeRow(); i++)
        for (int j = 0; j < left.get_sizeCol(); j++)
            temp.get_matrix()[i][j] = left.get_matrix()[i][j] - right.get_matrix()[i][j];
    temp.print();

    return temp;
}

Matrix operator/(const Matrix& left, const Matrix& right)
{
    Matrix temp(left.get_sizeRow(), left.get_sizeCol());
    for (int i = 0; i < left.get_sizeRow(); i++)
        for (int j = 0; j < left.get_sizeCol(); j++)
            temp.get_matrix()[i][j] = left.get_matrix()[i][j] / right.get_matrix()[i][j];
    temp.print();

    return temp;
}

std::ostream& operator << (std::ostream& os, const Matrix& obj)
{
    for (int i = 0; i < obj.get_sizeRow(); i++)
    {
        for (int j = 0; j < obj.get_sizeCol(); j++)
        {
            os << obj.get_matrix()[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return os;

}

std::istream& operator>> (std::istream& input, Matrix& obj) 
{
    for (int i = 0; i < obj.get_sizeRow(); i++)
    {
        for (int j = 0; j < obj.get_sizeCol(); j++)
        {
            input >> obj.get_matrix()[i][j];
        }
    }
    return input;
}

int main()
{
    
   /* Matrix G();
    std::cout << G << std::endl;*/

    Matrix A(10,10);
    A.Sort();
    A.print();
   // A.Sort()*/;
   // A.print();

 /*
    Matrix B(2,2);
    std::cout << B << std::endl;

    Matrix C = A + B;
    C.print();*/


    //A += B;
    //A.print();
    //std::cout << "He" << std::endl;

   


 /*   Matrix D= A - B;
    D.print();*/

  /* Matrix E = A * B;
    E.print();*/

  /*  Matrix F = A / B;
    F.print();*/


}

