#include <iostream>
#include <array>
#define cols 5
#define rows 3
#define n cols*rows


void transpose(std::array<double,n>&, const unsigned int);
void print(const std::array<double,n>, const unsigned int);

int main(){
    std::array<double, n> mat={3,16,3,5,1,59,24,12,43,54,62,9,24,21,75};
    print(mat, rows);
    transpose(mat, rows);
    std::cout<<std::endl;
    print(mat, cols);
}


void transpose(std::array<double,n>& matrix, const unsigned int r){
    unsigned int c=n/r;
    std::array<double, n> temp;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            temp[i+j*r]=matrix[j+i*c];
        }
    }
    matrix=temp;
}
void print(const std::array<double,n> matrix, const unsigned int r){

    unsigned int c=n/r;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            std::cout<<matrix[j+i*c]<<" ";
        }
    std::cout<<std::endl;
    }
}
    
    
