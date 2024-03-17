#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c;
    cin>>a>>b>>c;
    if((a+b>c) &&(b+c>a) && (c+b>a)) 
        cout<<"This is valid Triangle\n";
    else
        cout<<"This is not a valid Triangle\n";
    return 0;
}