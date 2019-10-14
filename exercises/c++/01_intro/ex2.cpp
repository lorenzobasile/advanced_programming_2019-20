#include <string>
#include <iostream>


int main(){

int count=0;
std::string current;
std::string next;
while(std::getline(std::cin, next)){
    if(count != 0 && current != next){
        std::cout<<"The string "<<current<<" was repeated "<<count<<" times \n";
        count=1;
    }
    else count++;
    current=next;
}

}
