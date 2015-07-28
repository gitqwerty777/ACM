#include <iostream>

using namespace std;

int main(){
	int a, b;
	int ans[1000];
	int i;
	
	ans[1] = 2;
	int plus = 2, plusp = 2;
	for(i = 2; i < 1000 ; i++){
		ans[i] = ans[i-1] + plus;
		plus += plusp;
		plusp++;
	}
	
	int pluswan = plus, pluspwan = plusp;
	while(cin>>a){
		cout<<ans[a]<<endl;
	}

	return 0;
}