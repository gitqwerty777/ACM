#include <iostream>

using namespace std;

void print(string out, int left, int right, int count){
	if(left == count){
		cout<<out;
		while(left > right){
			cout<<")"; right++;
		}
		cout<<endl;
	}
	else{
//		print(out+'(', left+1, right, count);
		if(left > right)
			print(out+")(", left+1, right+1, count);
		if(left + 1 < count)
			print(out+"()", left+1, right+1, count);
	}
}

int main(){
	int count;
	string out;
	while(cin>>count){
		out.clear();
		print(out, 0, 0, count);
	
	}

	return 0;
}