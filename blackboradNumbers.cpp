// Blackboard NUmbers
#include<iostream>
#include<string>
#include<cmath>
#include<array>
using namespace std;

int IsPrime(long long num){
	if(num == 0 || num == 1) return 0;
	if(num == 2) return 1;
	
	int i = 2;
	long long s = sqrt(num);
	while(i<=s){
		 if (num % i == 0) {
            // This means that n has a factor in between 2 and sqrt(n)
            // So it is not a prime number
            return 0;
        }
        i++;
	}
	return 1;	
}

array<int, 4> Check(string n){
	array<int, 4> base;
	for(int j = 0; j < 4; j++){
		base[j] = 1;
	}
	for(int i = 0; i < n.size(); i++){
		if(n[i] != '0' && n[i] != '1'){
			base[0] = 0;
	
		}
		if(n[i] == '8' || n[i] == '9'){
			base[1] = 0;
		}
		if(n[i] >= 'A' && n[i] <= 'F'){
			base[1] = base[2] = 0;
		}
		if(n[i] > 'F' || (n[i] < 'A' && n[i]>'9') || n[i]<'0')
			base[0] = base[1] = base[2] = base[3] = 0;
	}
	return base;
	
}

long long BtoD(string n){
	long long rem, num ,temp, dec = 0, b = 1;
	num = stoll(n);
	temp = num;
	while(temp > 0){
		rem = temp % 10;
		dec = dec + rem * b;
		b *= 2;
		temp /= 10;
	}
	return dec;
	
}

long long OtoD(string n){
	long long num = stoll(n), dec = 0, rem;
	int i = 0;
	while(num != 0){
		rem = num % 10;
		num /= 10;
		dec += rem * pow(8, i);
		++i;
	}
	return dec;
}

long long HtoD(string n){
	int len = n.size();
	long long dec = 0, base = 1;
	
	for(int i = len - 1; i >= 0; i--){
		if(n[i] >= '0' && n[i] <='9'){
			dec += (n[i] - 48) * base;
			base *= 16;
		}
		else if(n[i] >= 'A' && n[i] <='F'){
			dec += (n[i] - 55) * base;
			base *= 16;
		}
	}
	return dec;
}

void printMinimal(int a, int b){
	if(a == 0) printf("%d/%d\n", 0, 1);
	else{	
		for(int i = b*a; i>1; i--){
			if((b % i == 0) && (a % i == 0)){
				b /= i;
				a /= i;
			}
		}		
		printf("%d/%d\n", a, b);
	}
}

int main(){
	int numOfCase;
	string n;
	cin >> numOfCase;
	array<int, 4> Base;
	while(numOfCase--){
		
		cin >> n;
		Base = Check(n);

		if(Base[0] == 1){
			//means denominator = 4
			int numerator = 0;
			numerator += IsPrime(BtoD(n)) + IsPrime(OtoD(n)) + IsPrime(HtoD(n)) + IsPrime(stoll(n));		
			printMinimal(numerator, 4);
			
		}
		else{
		 	if(Base[1] == 1){
				int numerator = 0;
				numerator += IsPrime(OtoD(n)) + IsPrime(HtoD(n)) + IsPrime(stoll(n));			
				printMinimal(numerator, 3);
			}
			else{
				if(Base[2] == 1){
					int numerator = 0;
					numerator += IsPrime(HtoD(n)) + IsPrime(stoll(n));				
					printMinimal(numerator, 2);
				}
				else if(Base[3] == 1){
					int numerator = 0;
					numerator += IsPrime(HtoD(n));
					printMinimal(numerator, 1);
				}
				else{
					printMinimal(0,1);
				}	
				    
				}
			}
		}
	return 0;	
	}

