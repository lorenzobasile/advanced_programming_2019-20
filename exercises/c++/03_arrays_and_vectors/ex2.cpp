#include <sstream>
#include <iostream>
#include <vector>
void transpose(std::vector<double>&, int, int);
void print(const std::vector<double>, int, int);

int main(int argc, char* argv[]){
    int rows;
    int cols;
    int n;
    std::istringstream is{argv[1]};
    is >> rows;
    std::cout<<rows;
    std::istringstream is2{argv[2]};
    is2>> cols;
    n=rows*cols;
    /*
    std::vector<double> mat;
    for(int i=0; i<n; i++) mat.push_back(i);
    print(mat, rows, cols);
    transpose(mat, rows, cols);
    std::cout<<std::endl;
    print(mat, cols, rows);
    */
    
}


void transpose(std::vector<double>& matrix, int r, int c){
    std::vector<double> temp;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            temp[i+j*r]=matrix[j+i*c];
        }
    }
    matrix=temp;
}
void print(const std::vector<double> matrix, int r, int c){

    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            std::cout<<matrix[j+i*c]<<" ";
        }
    std::cout<<std::endl;
    }
}
    
    
