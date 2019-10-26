#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::ostream;

enum class m_name {jan=1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec};

class date{
    private:
        int giorno;
        m_name mese;
        int anno;
        void oneday();
        const bool leap()const;
    public:
        date(int d=1, m_name m=m_name::jan, int y=1970): giorno{d}, mese{m}, anno{y}
        {}
        const int day()const{return giorno;}
        const m_name month()const{return mese;}  
        const int year()const{return anno;}
        void add_days(const unsigned int); 
};
bool operator ==(const date& lhs, const date& rhs){
    if(lhs.day()==rhs.day() && lhs.month()==rhs.month() && lhs.year()==rhs.year()) 
        return true;
    else return false;
}
bool operator !=(const date& lhs, const date& rhs){
    return (!(lhs==rhs));
}
ostream& operator <<(ostream& out, const date& obj){
    return out<<"it is:"<<obj.day()<<"/"<<(int(obj.month()))<<"/"<<obj.year()<<endl;
}
const bool date::leap ()const{
    if(anno%4 == 0 && anno%400 != 0) return true;
    else return false;
}

void date::oneday(){
   switch(mese){
        case m_name::jan : case m_name::mar : case m_name::may : case m_name::jul : 
        case m_name::aug : case m_name::oct :{
            if(giorno==31){
                giorno=1;
                int m=(int(mese));
                m++;
                mese=static_cast<m_name>(m);
            }
            else giorno=giorno+1;
            break;
        }
        case m_name::dec: {
            if(giorno==31){
                giorno=1;
                mese=m_name::jan;
                anno++;
            }
            else giorno++;
            break;
        }
        case m_name::feb: {
            if(leap()){
               if(giorno==29){
                giorno=1;
                mese=m_name::mar;
                }
                else giorno++; 
            }
            else{
                if(giorno==28){
                giorno=1;
                mese=m_name::mar;
                } 
                else giorno++;
            }
            break;
        }
        case m_name::apr : case m_name::jun : case m_name::sep : case m_name::nov :{
            if(giorno==30){
                giorno=1;
                int m=(int(mese));
                m++;
                mese=static_cast<m_name>(m);
                } 
            else giorno++;
            break;
        }
    }
}

void date::add_days(const unsigned int n){
    for(int i=0; i<n; i++){
        oneday();
    }
}

int main(){

    date d(28, m_name::feb, 1996);
    date e(28, m_name::feb, 2000);  
    d.add_days(4);
    e.add_days(4);
    cout<<d;
    cout<<e;
    
}
