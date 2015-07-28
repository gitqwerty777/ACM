#include <iostream>
#include <vector>
#include <deque>
/*vector<string> breeding(breed, dnum, snum, ){
	

}*/
using namespace std;

class sick_node{
	public:
		string s;
		int sickd;//第幾天會遇到//無 = -1
		sick_node(string str, int d){
			s = str; sickd = d;
		}
};
typedef sick_node node;

int main(){
	string a,b;
	long d, n;
	int lo;int i, j;int ia, ib, sickd;
	
	cin>>a>>d>>n;
	lo = a.size();
	
	vector<node> sick;
	bool over = false;
	for(i = 0; i < n ;i++){
		cin>>b;
		if(a.find(b) != a.npos){
			cout<<"0 1"<<endl;
			over = true;
			break;
		}
		sickd = -1;
		for(i = 0; i < lo; i++)
			if(a[i] == b[0]){
				for(j = 0; j < b.size() && i+j < a.size(); j++)
					if(a[i+j] != b[j]){
						j = -1;break;}
				if(j != -1){
					sickd = b.size()-j+1;//??????
					break;
				}
			}
		
		if(sickd == -1)
			node tempnode(b, b.size());
		else
			node tempnode(b, sickd);
		sick.push_back(tempnode);
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