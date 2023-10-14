#include <bits/stdc++.h>
using namespace std;

int add(int a,int b){
	return a+b;
}
int subtract(int a,int b){
	return a-b;
}
long multiply(int a,int b){
	return a*b;
}
double divide(double a,double b){
	return a/b;
}

int main(){
	int n,m,ch;
	cout<<"Enter 1st Number: ";
	cin>>n;
	cout<<"Enter 2nd Number: ";
	cin>>m;
	cout<<"\nOperations available:-\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n\nEnter your choice: ";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<"\nresult: "<<n<<" + "<<m<<" = "<<add(n,m)<<endl;
			break;
		case 2:
			cout<<"\nresult: "<<n<<" - "<<m<<" = "<<subtract(n,m)<<endl;
			break;
		case 3:
			cout<<"\nresult: "<<n<<" * "<<m<<" = "<<multiply(n,m)<<endl;
			break;
		case 4:
			if(m==0)
			cout<<"\nresult: "<<"Undefined";
			else
			cout<<"\nresult: "<<n<<" / "<<m<<" = "<<divide((double)n,(double)m)<<endl;
			break;
		default:cout<<"Invalid choice";
	}
	return 0;
}
