#include <iostream>
#include "stack"
#include "vector"
using namespace std;


int main(){
    int a[10] = {0};
    int b[10][10] = {{1},{2},{3}};
    for(auto c : a)
        cout<<c<<" ";
    cout<<endl;
    for(auto c : b){
        for(int i = 0; i < 10; i++){
            cout<<c[i]<<" ";
        }
        cout<<endl;
    }



}