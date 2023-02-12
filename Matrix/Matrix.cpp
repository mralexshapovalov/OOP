// Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <iomanip>

class Matrix 
{
private:
    size_t size;
    int** matrix;

public:

    size_t get_size() const
    {
        return size;
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

    Matrix(const int size) 
    {
        this->size = size ;
        this->matrix = new int* [size]{};

        for (int i = 0; i < size; i++) 
        {
            matrix[i] = new int[size];
            for (int j = 0; j < size; j++) 
            {

                this->matrix[i][j] = matrix[i][j];
                /*this->matrix[i][j] = matrix[i][j] = 1 + rand() % 9;;*/
            }
           
        }
        std::cout << "1ArgConstuctor " << this << std::endl;

    }

    ~Matrix() 
    {
        delete this->matrix;
        std::cout << "Destructor\t" << this << std::endl;
    }

    void print()const
    {
        std::cout << "Size:\t" << size << std::endl;
        std::cout << "matrix:\t" << matrix << std::endl;

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                std::cout << matrix[i][j] << " ";
            }
            std::cout <<std::endl;
        }
        std::cout << this << std::endl;
    }


};
//Matrix operator+(const Matrix left, const Matrix right) 
//{
//
//    Matrix cat(left.get_size() + right.get_size() - 1);
//    for (int i = 0; i < left.get_size(); i++)
//        cat.get_matrix()[i] = left.get_matrix()[i];
//        /*cat[i] = left[i];*/
//
//    for (int i = 0; i < right.get_size(); i++)
//        cat.get_matrix()[i + left.get_size() - 1] = right.get_matrix()[i];
//       /* cat[i + left.get_size() - 1] = right[i];*/
//
//    return cat;
//
//



//std::ostream& operator << (std::ostream& os, const Matrix& obj)
//{
//    return os << obj.ma();
//}

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
    for (int i = 0; i < obj.get_size(); i++)
    {
        for (int j = 0; j < obj.get_size(); j++)
        {
            os << obj.get_matrix()[i][j];
        }
        std::cout << std::endl;
    }
    return os;


}

std::istream& operator>> (std::istream& input, Matrix& obj) 
{

    for (int i = 0; i < obj.get_size(); i++)
    {
        for (int j = 0; j < obj.get_size(); j++)
        {
            input >> obj.get_matrix()[i][j];
        }
        
    }
    return input;

}

int main()
{
    
    /*Matrix A(5);
   
    A.print();
    std::cout << std::endl;
    Matrix B(5);

    B.print();*/

    /*Matrix C = A + B;
    C.print();*/

    Matrix C(4);
    std::cin >> C;
    std::cout << C << std::endl;
}

