#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    srand(time(0));
    n=rand()%100;

    int g;
    cout<<"Guess the number between 0-100"<<endl;
    do{
        cout<<"\nenter your guess number : ";
        cin>>g;
        if(n==g)
        cout<<"Correct Guess!!"<<endl;
        else if(n<g)
        cout<<"----Guess Lower----"<<endl;
        else
        cout<<"----Guess Higher----"<<endl;
    }while(n!=g);
    return 0;

}
