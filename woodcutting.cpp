#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;


void test_case(){
	
	long N = 0;
	long numOfWood = 0;
	double result = 0;
	cin >> N ; //number of customers
	long sum[N] = {0}, temp = 0;
	
	for(int j = 0; j < N; j++){
		cin >> numOfWood;
		for(int k = 0; k < numOfWood; k++){
			//read in the woods of customer j
			cin >> temp;
			sum[j] += temp;
		}
	}
	//sort the array of total time in an increasing order
	sort(sum, sum + N);
		
	for(int i = 0; i<N; i++){
		result += (N - i)*sum[i] ;
	}
	result /= N;
	
	cout << setprecision(10) << fixed;
	cout << result << endl;
	return ;
	
		
}


int main(){
	int c;
	cin >> c; //number of test case
	for(int i = 0; i < c ; i++){
		test_case();
	}
	
	return 0;
	
}
