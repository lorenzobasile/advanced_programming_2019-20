#include <iostream>
#include <cmath>
#include <vector>

std::vector<bool> erathostenes(std::vector<bool>, unsigned int);


int main(){
    unsigned int num;
    std::cout<<"insert number: ";
    std::cin>>num;    
    std::vector<bool> sieve(num+1);
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
std::vector<bool> erathostenes(std::vector<bool> vect, unsigned int max){
    for (int i=2; i<=std::sqrt(max); i++){
        if(vect[i]){
            for (int j=2*i; j<=max; j +=i) vect[j]=false;
        }
    }
    return vect;
}
