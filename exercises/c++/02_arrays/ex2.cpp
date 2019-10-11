#include <iostream>


unsigned int* alloc(unsigned int*, unsigned int, unsigned int);
bool isprime(unsigned int);

int main(){
unsigned int* primes;
int count=0;
for(unsigned int i=2; i<101; i++){ //used unsigned just because i is used as a unsigned int parameter
    if(isprime(i)){
        count++;
        primes=alloc(primes, count, i);
    }
}
for(int i=0; i<count; i++){
    std::cout<<primes[i]<<" ";
}
}
//used the dynamic array to gain some experience in its usage, probably the static solution is preferable
unsigned int* alloc(unsigned int* vect, unsigned int size, unsigned int number){
    unsigned int* vect2=new unsigned int[size];
    if(size>1){
        for (unsigned int i=0; i<size; i++){
            vect2[i]=vect[i];
        }
    }
    vect2[size-1]=number;
    if(size>1){
        delete[] vect;
    }
    return vect2;
}

bool isprime(unsigned int number){
    for(unsigned int i=2; i<number; i++){
        if(number%i==0) return false;
    }
    return true;
}

