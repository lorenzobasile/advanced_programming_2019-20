#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

void print(std::vector<std::string>);
void divide(std::string&, std::vector<std::string>&);

int main(){
    std::vector<std::string> vect;
    int i=0;
    std::string temp;
    std::getline(std::cin,temp);
    divide(temp, vect);
    print(vect);
    std::cout<<std::endl;
    return 0;
}

void print(std::vector<std::string> v){
    std::sort(v.begin(), v.end());
    std::cout<<v[0]<<" ";
    for(int i=1; i<v.size(); i++)
        if(v.at(i)!=v.at(i-1)) std::cout<<v[i]<<" ";
}
void divide(std::string& s, std::vector<std::string>& v){
    int i=s.find_last_of(" ");
    if(i!=std::string::npos){
        v.push_back(s.substr(i+1));
        s.erase(i);
        divide(s, v);
    }
    else v.push_back(s);

}
