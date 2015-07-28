#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){
	string sn;
	string sa;
	long long a;
	long long n;
	
	
	vector<long long > lastbase;
	vector<long long >lastav;//記錄用
	
	
	
	long long lobase;
	bool bauliou = false;
	while(cin>>a>>n){
		//預處理
		int i = 0;
		while(sa[0] == '0' && sa.size() > 1)
			sa.erase(sa.begin());
		while(sn[0] == '0' && sn.size() > 1)//0
			sn.erase(sn.begin());
		a = atol(sa.c_str());
		n = atol(sn.c_str());
		//初始化
		long base = 1;
		lastbase.clear();
		lastav.clear();
		lastbase.push_back(1);
		lastav.push_back(a);
		//
		if(bauliou){
			cout<<"0"<<endl;
			bauliou = false;
		}
		if(n == 0){
			if(a != 0)
				cout<<"1"<<endl;
			else{
				bauliou = true;
			}
		}
		else if(a == 0){
			cout<<"0"<<endl;
		}
		else{
			if(base * 2 <= n){
				base *= 2;
				a *= a;
				lastbase.push_back(base);
				lastav.push_back(a);
			}
			else{
				lobase = lastav.size();
				for(long long i = lobase - 1; i >= 0; i--)
					if(lastbase[i] + base <= n){
						a *= lastav[i];
						base += lastbase[i];
						lastbase.push_back(base);
						lastav.push_back(a);
						break;
					}
			}
		}
		cout<<a<<endl;
	}
	cout<<"All Over."<<endl;
	
	return 0;
}