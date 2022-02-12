#include<bits/stdc++.h>
using namespace std;
 
const int m = 1e9 + 7;

void display(int subset){

    for(int i = 0; i <= 10; i++){
        if(subset & (1 << i)){
            cout<<i+1<<" ";
        }
    }

}

void add(int &subset,int x){
    subset = subset ^ (1 << (x-1));
}

void deleteX(int &subset,int x){
    subset = subset ^ (1 << (x-1));
}

int main()
{
    int subset = 15;
    add(subset,6);
    deleteX(subset,2);
    display(subset);

    return 0;
    
}
