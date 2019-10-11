#include <iostream>
#include <cmath>

bool* erathostenes(bool*, unsigned int);


int main(){
    unsigned int num;
    std::cout<<"insert number: ";
    std::cin>>num;
    bool* sieve=new bool[num]; //surely less than num
    for (int i=2; i<=num; i++){
        sieve[i]=true;
    }
    sieve=erathostenes(sieve, num);
    std::cout<<std::endl;
    for (int i=2; i<=num; i++){
        if(sieve[i]) std::cout<<i<<std::endl;
    }
    return 0;
}
bool* erathostenes(bool* vect, unsigned int max){
    for (int i=2; i<=std::sqrt(max); i++){
        if(vect[i]){
            for (int j=2*i; j<=max; j +=i) vect[j]=false; 
        }
    }
    return vect;
}
