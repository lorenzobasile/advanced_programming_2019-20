#include <iostream>
#include <string>

int main(){
    int number;
    bool exit=false;
    std::string unit;
    while(!exit){
        if(!(std::cin >> number)) {
            exit=true; //the first element inserted was not a number
            std::cout<<"Exiting";
        }
        else {
            std::cin >> unit;
            if(unit=="inch"){
                std::cout<<number*0.0254<<" m \n";        
            }
            else {
                exit=true; //the second element was not "inch"
                std::cout<<"Exiting";
            }
        }
}
}
