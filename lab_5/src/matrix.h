#include <iostream>
class TwoDimensionMatrix{
    static const int size=2;
    int matrix[size][size];
public:
    TwoDimensionMatrix(){
        std::cout<<"***MATRIX CREATED***"<<std::endl;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++) matrix[i][j]=0;
        }
    }
    TwoDimensionMatrix(TwoDimensionMatrix &newmatrix){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++) matrix[i][j]=newmatrix.matrix[i][j];
        }
    }
    TwoDimensionMatrix(const int _matrix[size][size]){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++) matrix[i][j]=_matrix[i][j];
        }
    }
    int get(int i,int j){return matrix[i][j];}
    void set(int i,int j,int x){matrix[i][j]=x;}
    static constexpr int getSize(){return size;}
    TwoDimensionMatrix & operator = (const TwoDimensionMatrix & _matrix);
    TwoDimensionMatrix& operator*=(int number){
        for(int i=0;i<2;i++){
            for(int j=0;j<2;i++) this->matrix[i][j]*=number;
        }
        return *this;
    }
};
TwoDimensionMatrix & operator <<(const TwoDimensionMatrix & matrix, const int & x);
TwoDimensionMatrix operator +(const TwoDimensionMatrix & matrix1, const TwoDimensionMatrix & matrix2){
    TwoDimensionMatrix matrix;
    //for(int i=0;i<2;i++){
      //  for(int j=0;j<2;j++) matrix.set(i,j,(matrix1.get(i,j)+matrix2.get(i,j)));
    //}
   return matrix;
}
