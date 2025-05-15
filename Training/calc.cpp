#include <iostream>
#include <string>
using namespace std;

class apples{


public :
    apples(string z){//Constructor don't need a return type and has same name as class so it will run automatically.
    cout<<"This will be printed out."<<endl;
    setname(z);
    }

    void setname(string x){
    name = x;
    }

    string getname(){
    return name;
    }

private :
    string name;//Since name is private public functions are needed to access it.
};

int main(){

apples bo("Reynald Walme");

cout<<bo.getname()<<endl;
}
