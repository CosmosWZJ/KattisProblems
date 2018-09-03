#include<iostream>

#include<algorithm>
using namespace std;

#define MAXN 100001


void test_case(int c){
	long sanswer[101];
	long lanswer[101];
	
	for(int i = 0; i < c; i++){
		
	
		long  pole, ants;
		cin >> pole;//length of pole
		cin >> ants;//number of ants
		long  pos[MAXN];
		long  stime = 0, ltime = 0;
		
		for(long j = 0; j < ants; j++){
			cin >> pos[j];
			
			//determine the shortest time 
			if(min(pos[j], pole - pos[j]) > stime){
				stime = min(pos[j], pole - pos[j]);
			}		
		}
		
		sort(pos, pos + ants);
		// assume when two ants meet, they dont turn arround but keep going their origin path
		if((pole-pos[0]) < pos[ants-1]){
			ltime = pos[ants-1];
		}
		else{
			ltime = pole - pos[0];
		}
		
		sanswer[i] = stime;
		lanswer[i] = ltime;		
	}
	for(int k = 0; k < c; k++){
		cout << sanswer[k] << " " << lanswer[k] << endl;
	}
return;	
}



int main(){
	int c;
	cin >> c; //number of test case
	test_case(c);
	return 0;
	
}
