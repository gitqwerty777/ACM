#include <iostream>
#include <cctype>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(){
	int a, b;
	int i, j, lo, count;
	string in;
	bool p;
	
	
	int head[26] = {0};
	int tail[26] = {0};
	bool curve[26] = {false};
	bool use[26] = {false};
	
	while(cin>>a){
		if(a == 0)	
			break;
			
		memset(head, 0, sizeof(int)*26);
		memset(tail, 0, sizeof(int)*26);
		memset(curve, false, sizeof(bool)*26);
		memset(use, false, sizeof(bool)*26);

		for(i = 0; i < a; i++){
			cin>>in;
			lo = in.size();
			
			count = in[0] - 'a';
			
			use[count] = true;
			use[in[lo-1] - 'a'] = true;
			
			if(in[0] == in[lo-1])
				curve[count] = true;
			else{
				head[count]++;
				tail[in[lo-1] - 'a']++;
			}
		}
		
		int count = 0;
		for(i = 0; i < 26; i++)
			if(use[i])
				count++;
			
		if(count == 1)
			p = true;
		else{
			p = true;
			for(i = 0; i < 26 && p; i++){
				if(curve[i])
					if(!head[i] || !tail[i])//
						p = false;
				if(head[i] - tail[i])
					p = false;
			}
		}
		
		
		if(p)
			cout<<"OK"<<endl;
		else
			cout<<"NG"<<endl;

	}

	return 0;
}
