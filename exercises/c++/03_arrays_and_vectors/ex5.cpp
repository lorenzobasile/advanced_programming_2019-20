#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <map>
#include <unordered_map>

using namespace std::chrono;

void printvec(std::vector<std::string>);

template <typename T>
void printmap(T);

int main(){
    std::fstream myfile;
    std::string temp;
    std::vector<std::string> vect;
    std::map<std::string, int> m;
    std::unordered_map<std::string, int> um;
    int i=0;
    myfile.open("LittleWomen.txt");
    std::pair<std::map<std::string,int>::iterator,bool> ret;
    while(!myfile.eof()){
        myfile>>temp;
        if (m.count(temp)>0) {
            m[temp]++;
        }
        else m.insert ( std::pair<std::string,int>(temp, 1) );
        if (um.count(temp)>0) {
            um[temp]++;
        }
        else um.insert ( std::pair<std::string,int>(temp, 1) );
        vect.push_back(temp);      
        }
    myfile.close();
    auto v0 = high_resolution_clock::now(); 
    printvec(vect);
    auto v1 = high_resolution_clock::now();
    auto elapsedv = duration_cast<std::chrono::milliseconds>(v1-v0);
    std::cout<<"std::vector: elapsed time of " << elapsedv.count() << " milliseconds" << std::endl;
    auto m0 = high_resolution_clock::now(); 
    printmap<std::map<std::string, int>>(m);
    auto m1 = high_resolution_clock::now();
    auto elapsedm = duration_cast<std::chrono::milliseconds>(m1-m0);
    std::cout<<"std::map: elapsed time of " << elapsedm.count() << " milliseconds" << std::endl;
    auto um0 = high_resolution_clock::now(); 
    printmap<std::unordered_map<std::string, int>>(um);
    auto um1 = high_resolution_clock::now();
    auto elapsedum = duration_cast<std::chrono::milliseconds>(um1-um0);
    std::cout<<"std::unordered_map: elapsed time of " << elapsedum.count() << " milliseconds" << std::endl;
    return 0;
}

void printvec(std::vector<std::string> v){
    int cont=1;
    std::sort(v.begin(), v.end());
    //std::cout<<v[0]<<" ";   everything works for all 3 types, so i just print the results in terms of time to compare them. about 116ms for the vector vs 6ms of both types of map
    for(int i=1; i<v.size(); i++)
        if(v.at(i)!=v.at(i-1)) {
            //std::cout<<cont<<std::endl<<v[i]<<" ";
            cont=1;
            }
        else cont++;
    //std::cout<<cont<<std::endl;
}

template <typename T>
void printmap(T m){
    for(auto i : m){
        //std::cout<<i.first<<" "<<i.second<<std::endl;
    }
}

