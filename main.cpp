#include <iostream>
#include "apples.h"
using namespace std;
int first,second;
string op;
void operations(string o,int f,int s);//Allows the function underneath the int main to be read.

int main(){
cout<<"Please enter the first number"<< endl;
cin >> first;
cout<<"Please enter the operation:(+,-,*,/)"<< endl;
cin >> op;
cout<<"Please enter the second number"<< endl;
cin >> second;
operations(op,first,second);
apples bo;
return 0;
}

void operations(string o,int f,int s){//Checks for operator then runs code for each operation.
if(o == "+")
    {
    int ans = f + s;
    cout <<"The answer is: "<< ans<< endl;
    }

else if(o == "-")
    {
    int ans = f - s;
    cout<<"The answer is: "<< ans<< endl;
    }

else if(o == "*")
    {
    int ans = f * s;
    cout<<"The answer is: "<< ans << endl;
    }

else if(o == "/")
    {
    if(s !=0){
    int ans = f / s;
    cout<<"The answer is: "<< ans<< endl;
        }
    else{
        cout<<"Cannot divide by zero stupid, try again."<<endl;
        }
    }

else{
    cout<<"An operation error has occurred please try again."<<endl;
    }
}
