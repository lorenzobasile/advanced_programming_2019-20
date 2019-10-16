#include <iostream>
template <typename T>
T* allocate(unsigned int);
template <typename T2>
void print(T2*, unsigned int);
int main(){

unsigned int size;
std::cin>>size;
int* a=allocate<int>(size);
print<int>(a, size);
delete[] a;
std::cout<<"\n";
double* b=allocate<double>(size);
print<double>(b, size);

delete[] b;

return 0;

}
template <typename T>
T* allocate(unsigned int size){
    T* vect= new T [size];
    for(int i=0; i<size; i++){
        std::cin>>vect[i];
    }
    return vect;
}
template <typename T2>
void print(T2* vect, unsigned int size){
    for(int i=size-1; i>-1; i--){
        std::cout<<vect[i]<<" ";
    } 
}
