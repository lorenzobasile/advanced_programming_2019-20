#include <iostream>
#include <string>

template<typename T>
bool get_type();

int main(){
    if(get_type<int>()) std::cout<<"Integer inserted \n";
    if(get_type<double>()) std::cout<<"Double inserted \n";
    return 0;
}

template<typename T>
bool get_type(){
    T input;
    std::cin.clear();
    std::cin.ignore();
    while(!(std::cin>>input)){
        std::cin.clear();
        std::cin.ignore();
    }
    return true;
}
