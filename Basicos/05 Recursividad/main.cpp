#include <iostream>
using namespace std;


unsigned long int sumI(unsigned long int n){
	unsigned long int r = 0;

	while(n > 0){
		r+=n;
		n--;
	}

	return r;

}

unsigned long int sumR(unsigned long int n){
	if(n<2){
		return n;
	}

	return n + sumR(n-1);

}


unsigned long int factI(unsigned long int n){
	unsigned  long int r=1;

	while(n>1){
		r*=n;
		n--;

	}
	return r;

}


unsigned long int factR(unsigned long int n){
	if(n<2){
		return 1;
	}
	else{
		return n*factR(n-1) ;
	}

}

unsigned int long fibI(unsigned long int n){
	unsigned long int i = 1, j = 1, r = 1;
	while(n > 1){
		r = j + i;
		i = j;
		j = r;
		n--;
	}
	return r;
}

unsigned long int fibR(unsigned long int n){
	if(n<2){
		return 1;
	}
	else{
		return fibR(n-1) + fibR(n-2);
	}
}


int main(){
	int value;

	cout <<"Ingresa un valor: "<<endl;
	cin>> value;
	cout<< endl;

	cout<<"Sumatoria iterativa de "<<value<<": "<<sumI(value)<<endl;
	cout<<"Sumatoria recursiva de "<<value<<": "<<sumR(value)<<endl;

	cout<<"Factorial iterativa de "<<value<<": "<<factI(value)<<endl;
	cout<<"Factorial recursiva de "<<value<<": "<<factR(value)<<endl;

	cout<<"Fibonacci iterativa de "<<value<<": "<<fibI(value)<<endl;
	cout<<"Fibonacci recursiva de "<<value<<": "<<fibR(value)<<endl;



	return 0;
}
