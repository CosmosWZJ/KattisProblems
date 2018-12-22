#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;

void area(int n){
	vector< pair<int, int> > coordinates;
	int x, y;
	for(int i = 0; i<n; i++){
		cin >> x >> y;
		coordinates.push_back(make_pair(x, y));
	}
	double ar = 0.0;
	ar = (double) coordinates[n-1].first * coordinates[0].second - coordinates[n-1].second * coordinates[0].first;
	
	for(int j = 0; j<n-1; j++){
		ar += (double)coordinates[j].first * coordinates[j+1].second - coordinates[j+1].first * coordinates[j].second;
	//	cout << ar << endl;
	}
	ar = 0.5 * ar;
	if(ar <= 0){
		ar = -ar;
		printf("CW %.1f\n", ar);
		//cout << coordinates[0].first;
	}
	else
		printf("CCW %.1f\n", ar);
	
	coordinates.clear();
	
	
}

int main(){
	int n;
	while(cin>>n){
		if(n == 0) break;
		area(n);
	}
	return 0;
}
