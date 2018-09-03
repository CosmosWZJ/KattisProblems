//bing it on
#include<iostream> 
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	int N;
	cin >> N;
	unordered_map<string, int> words;
	
	while(N--){
		string word;
		cin >> word;
		cout << words[word] << endl;
		for(int i = 1; i <= word.size(); ++i)
			++words[word.substr(0, i)];
    }
    return 0;   
		
	
}