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
    int row,col;
    int** matrix;

public:

    int get_sizeRow() const
    {
        return row;
    }
    int get_sizeCol() const
    {
        return col;
    }

    int **get_matrix() 
    {
        return matrix;
    }
    int** get_matrix()const
    {
        return matrix;
    }
    void set_matrix(int** matrix)
    {
        this->matrix = matrix;
    }

   
   /* const int** get_matrix()const
    {
        return matrix;
    }*/

  /*  Matrix(int size = 5)
    {
        this->size = size;
        this->matrix = new int*[size]{};

        std::cout << "DefConstructor\t" << this << std::endl;
    };*/

    //Matrix() 
    //{
    //    this->size = size;
    //    this->matrix = new int* [size] {};

    //    for (int i = 0; i < size; i++)
    //    {
    //        matrix[i] = new int[size];

    //        for (int j = 0; j < size; j++)
    //        {

    //            this->matrix[i][j] = matrix[i][j];
    //            /*this->matrix[i][j] = matrix[i][j] = 1 + rand() % 9;;*/
    //        }
    //    }
    //    std::cout << "1ArgConstuctor " << this << std::endl;

    //}




    Matrix(const int row, const int col)
    {
        this->row = row;
        this->col = col;
        this->matrix = new int* [row]{};

        for (int i = 0; i < row; i++) 
        {
            this->matrix[i] = new int[row];

            for (int j = 0; j < col; j++)
            

       /*       this->matrix[i][j]=matrix[i][j];*/

                matrix[i][j] = matrix[i][j] = 1 + rand() % 9;
            
        }
        std::cout << "1ArgConstuctor " << this << std::endl;
    }


    ~Matrix() 
    {
        for (int i = 0; i < row; i++)
            delete[] matrix[i]; //деструктор удаляет из памяти динамический массив, созданный конструктором
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
    


    void print()const
    {
        std::cout << "Size:\t" << row <<col<< std::endl;
        std::cout << "matrix:\t" << matrix << std::endl;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                std::cout << matrix[i][j]<<"\t";
            }
            std::cout <<std::endl;
        }
        std::cout << this << std::endl;
    }



    //int operator[](int i,int j)const
    //{

    //    return matrix[i][j];
    //}

    //int& operator[](int i, int j)const
    //{

    //    return matrix[i][j];
    //}

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
            temp(i, j) = left(i, j) + right(i, j);
    temp.print();
    return temp;
}

Matrix operator-(const Matrix& left, const Matrix& right)
{


    Matrix temp(left.get_sizeRow(), left.get_sizeCol());
    for (int i = 0; i < left.get_sizeRow(); i++)
        for (int j = 0; j < left.get_sizeCol(); j++)
            temp(i, j) = left(i, j) - right(i, j);
    temp.print();
    return temp;
}
//
Matrix operator*(const Matrix& left, const Matrix& right)
{


    Matrix temp(left.get_sizeRow(), left.get_sizeCol());
    for (int i = 0; i < left.get_sizeRow(); i++)
        for (int j = 0; j < left.get_sizeCol(); j++)
            temp(i, j) = left(i, j) * right(i, j);
    temp.print();
    return temp;
}

Matrix operator/(const Matrix& left, const Matrix& right)
{


    Matrix temp(left.get_sizeRow(), left.get_sizeCol());
    for (int i = 0; i < left.get_sizeRow(); i++)
        for (int j = 0; j < left.get_sizeCol(); j++)
            temp(i, j) = left(i, j) / right(i, j);

    temp.print();
    return temp;
}



//Matrix operator+(const Matrix& A, const Matrix& B)
///* Pre: A and B are non-empty matrices with the same size. Return: A+B.*/
//{
//    assert(A.size() == B.size());
//    assert(A[0].size() == B[0].size());
//
//    int nrows = A.size();
//    int ncols = A[0].size();
//    Matrix matrix(nrows, std::vector<int>(ncols));
//    for (int i = 0; i < nrows; ++i) {
//        for (int j = 0; j < ncols; ++j) {
//            matrix[i][j] = A[i][j] + B[i][j];
//        }
//    }
//    return matrix;
//}



std::ostream& operator << (std::ostream& os, const Matrix& obj)
{
    for (int i = 0; i < obj.get_sizeRow(); i++)
    {
        for (int j = 0; j < obj.get_sizeCol(); j++)
        {
            os << obj.get_matrix()[i][j];
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
    
    Matrix A(2,2);
  

 
    Matrix B(2,2);


   /* Matrix C = A + B;
    C.print();*/


    //A += B;
    //A.print();
    //std::cout << "He" << std::endl;

   


 /*   Matrix D= A - B;
    D.print();*/

  /* Matrix E = A * B;
    E.print();*/

    Matrix F = A / B;
    F.print();


}

