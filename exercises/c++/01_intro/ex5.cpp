#include <iostream>
#include <string>

const int thr = 20;

void formatter(std::string);
int main(){
    std::string sentence;
    std::string temp;

    while(std::getline(std::cin,sentence)) formatter(sentence);
}

void formatter(std::string sen){
    std::string temp;
    int i;
    if(sen.find(" ")==0) sen.erase(0, 1);
    if(sen.length()>thr){
        i=sen.find_last_of(" ", thr);
        temp=sen.substr(i);
        sen.erase(i);
        std::cout<<sen<<"\n";
        formatter(temp);
    }
    else std::cout<<sen<<"\n";
}
