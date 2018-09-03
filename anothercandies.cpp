#include<iostream>

using namespace std;

int main(){
	int numberOfKids, cas, i, j, k;
	long long sum;
	string blank;
		
	
	cin >> cas;
	getline(cin, blank);
	
	
	for(i=0; i<cas; i++){
		sum = 0;
		cin >> numberOfKids ;
	
		long long candies = 0;
		
		for(j=0; j < numberOfKids; j++){
			cin >> candies;
			sum += candies;
		if( sum> numberOfKids ){
			sum %= numberOfKids;
		}
			
		}
		getline(cin, blank);
		if (sum % numberOfKids == 0){
			cout << "YES\n";
		}
		else{
			cout <<"NO\n";
		}
	}
	
	
		
	return 0;
	
	

}
