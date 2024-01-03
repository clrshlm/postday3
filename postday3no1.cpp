#include <iostream>
#include <vector>
#include<iomanip>
using namespace std;

class Matrix{
    private:
        vector<vector<double>>data;
        int rows;
        int cols;
    public:
        Matrix(int xrows, int xcols):
            rows(xrows) ,
            cols(xcols)
            {
                data.resize(xrows, vector<double>(xcols, 0.0));
                cout<<"Constructor berparameter baris dan kolom"<<endl;
            }
        Matrix(initializer_list<vector<double>>value):data(value){
            rows = value.size();
            cols = value.begin()->size();
            cout<<"Constructor berparameter koleksi data"<<endl;
        }

void display(){
    for (int i=0; i<rows; i++){
        for (int j=0; j<cols; j++){
            cout<<setw(5)<<data[i][j]<<" ";
        }
        cout<<'\n';
    }
}

Matrix operator+(const Matrix& kanan){
    if (cols == kanan.cols && rows==kanan.rows){
        Matrix hasil(rows, cols);
        for(int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                hasil.data[i][j]=data[i][j]+kanan.data[i][j];
            }
        }
        return hasil;
    }
    else{
        cout<<"The matrix dimension is not valid!"<<endl;
        Matrix hasil={{0}};
        return hasil;
    }
}

Matrix operator-(const Matrix& kanan){
    if (cols == kanan.cols && rows==kanan.rows){
        Matrix hasil(rows, cols);
        for(int i=0; i<rows; i++){
            for (int j=0; j<cols; j++){
                hasil.data[i][j]=data[i][j]-kanan.data[i][j];
            }
        }
        return hasil;
    }
    else{
        cout<<"The matrix dimension is not valid!"<<endl;
        Matrix hasil={{0}};
        return hasil;
        }
    }

Matrix operator* (const Matrix& kanan) {
    if (cols == kanan.rows){
        Matrix hasil(rows, kanan.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < kanan.cols; j++) {
             hasil.data[i][j] = 0;
             for (int k = 0; k < cols; k++) {
                hasil.data[i][j] = hasil.data[i][j] + ((data[i][k]) * (kanan.data[k][j]));
        }
      }
    }
    hasil.display();
    return hasil;
  }
  else{
    cout<<"The matrix dimension is not valid!"<<endl;
    Matrix hasil={{0}};
    return hasil; 
  }
}
};

int main()
{
    Matrix A = {{1,2,3},{2,3,1}};
    Matrix B = {{0,2,4},{1,2,5},{8,2,1.2}};
    Matrix C(2,3);
    std::cout<<"Matrix A\n";
    A.display();
    std::cout<<"Matrix B\n";
    B.display();
    std::cout<<"Matrix C\n";
    C.display();
    std::cout<< '\n';
    Matrix C1 = A+C;
    std::cout<<"Matrix C1\n";
    C1.display();
    std::cout<<'\n';
    Matrix C2 = A-C;
    std::cout<<"Matrix C2\n";
    C2.display();
    std::cout<<'\n';
    Matrix C3 = A*B;
    std::cout<<"Matrix C3\n";
    C3.display();
    std::cout<<'\n';
    Matrix C4 = B*A;
    std::cout<<"Matrix C4\n";
    C4.display();
    std::cout<<'\n';
    return 0;
}