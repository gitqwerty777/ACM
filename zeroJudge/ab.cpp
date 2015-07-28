#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	int ans[4]; int n;
	int ansp[10];
	int quest;
	stringstream ss; string ans; int ansi;
	//注意到，在loop 裡面有清除 flag 動作，stream.clear()。若要清文字內容，是用 stream.str("")，二者不同。要用 stringstream 產生 A001.txt~A100.txt 字串較麻煩一點，要先引入 iomanip
	while(getline(cin, ans)){
		cin>>n;
		int i, j;
		vector<int> ansp(10,0);
		ss.clear();
		ss.str("");
		ss<<ans;
		for(i = 0; i < 4; i++){
			ss>>ansi;
			ansp[ansi]++;
		}
		int a, b;
		for(i = 0; i < n ;i++){
			getline(cin, ans);
			ss.clear();
			ss.str("");
			ss<<ans;
			a = 0; b = 0;
			vector<int> temp(ansp);
			for(i =0; i <4; i++){
				ss>>ansi;
				temp[ansi]--;
				if(ansi == ans[i])
					a++;
				else if(temp[ansi] >= 0)
					b++;
			}
			
			cout<<a<<"A"<<b<<"B"<<endl;
			
		}
	}
	
	return 0;
}