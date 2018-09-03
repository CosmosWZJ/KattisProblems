#include<iostream>
#include<cmath>
using namespace std;

//this is a kattis problem: 3D printed statues
int compute(int n);

int main(){
	int n;
	cin >> n;
	cout << compute(n);	
	return 0;
	
}

int compute(int n){
	int days, i = 0, num;
	double j;
	num = n;
	while(num > 1){
		num /= 2;
		i++;
	}
	// i = spend how many days to make printers
	j = n / pow(2, i);
	if(j > 1.0){
		return i + 1 + (int) j;
		
	}
	else{
		return i + (int) j;
	}
	
	
	
}
