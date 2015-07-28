#include <iostream>
#include <vector>
#include <deque>
/*vector<string> breeding(breed, dnum, snum, ){
	

}*/


using namespace std;
int main(){
	string a,b;
	long d, n;
	
	cin>>a>>d>>n;
	
	int i, j;
	vector<int> sick;
	bool over = false;
	for(i = 0; i < n ;i++){
		cin>>b;
		if(a.find(b) != a.npos){
			cout<<"0 1"<<endl;
			over = true;
			break;
		}
		sick.push_back(b);
	}
	if(!over){
		vector<string> breed;
		int dnum = 0, snum = 0;
		string temp;
		
		breed.push(a);
		
		
		
		/*breeding(breed, dnum, snum);*/
		/*
		for(i = 0; i < d; i++){//找每個病的演化次數並計算
			for(j = 0; j < stack.size(); j++)
				temp = stack.pop();
		}*/
		
			
	}

	return 0;
}