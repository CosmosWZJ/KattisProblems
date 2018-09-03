#include<iostream>

#include<algorithm>

using namespace std;

int main(){
	
	int temp1, temp2;
	int N, M, Q, check;
	
	int sum = 0;
	
	cin >> N >> M >> Q ;
	int arr[N + 100] = {0};
	
	
	sum = 0;
		
	for(int k = 0; k< M ; k++){
		
		scanf("%d", &temp1);
		scanf("%d", &temp2); 
		arr[temp1 - 1] += 1;
		arr[temp2] -=1;
	}
	
	
	for( int j = 0; j<N; j++){
		arr[j] += sum;
		sum = arr[j];
	}
	for(int i = 0 ; i < Q; i++){
		scanf("%d", &check);
		printf("%d\n", arr[check-1]);
		
	}
	
		
		
	
	return 0;
}
	
	
