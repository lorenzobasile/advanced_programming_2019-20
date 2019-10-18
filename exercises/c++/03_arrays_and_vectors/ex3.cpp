#include <iostream>
#include <algorithm>
#include <fstream>

double median(std::vector<double>&);
double mean(const std::vector<double>);

int main(){
    std::fstream myfile;
    std::vector<double> temps;
    double temp, med, mea;
    myfile.open("temperatures.txt");
    while(!myfile.eof()){
        myfile>>temp;
        temps.push_back(temp);
    }
    myfile.close();
    med=median(temps);
    mea=mean(temps);
    std::cout<<"The median is: "<<med<<" and the mean is: "<<mea<<std::endl;

}
double median(std::vector<double>& v){
    std::sort(v.begin(), v.end());
    if(v.size()%2==0)
        return (v[v.size()/2]+v[(v.size()/2)+1])/2;
    else return v[(v.size()/2)+1];
}
double mean(const std::vector<double> v){
    double sum=0;
    for(int i=0; i<v.size(); i++){
        sum += v[i];
    }
    return sum/v.size();

}
