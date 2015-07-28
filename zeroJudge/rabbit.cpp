#include <iostream>
#include <cstring>
#include <cstdio>
#include <sstream>
using namespace std;

int main(){
	int x,y,z,w, n, m;
	string in;
	stringstream ss;
	int eat[5] = {0};
	int type, poiv;
	bool poison;
	
	while(cin>>eat[1]>>eat[2]>>eat[3]>>eat[4]>>n>>m){
		poiv = 0;
		poison = false;
		ss.clear();
		eat[3] = -eat[3];
		eat[4] = -eat[4];
		
		getline(cin, in);
		ss<<in;
		
		while(ss>>type){
			if(poison)
				m -= poiv;
			if(m <= 0){
				puts("bye~Rabbit");
				break;
			}
			m += eat[type];
				
			if(type == 4){
				poison = true;
				poiv += n;
			}
		}
		if(m > 0)
			cout<<m<<"g"<<endl;
	}
	
	return 0;
}