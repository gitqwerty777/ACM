/**********************************************************************************/
/*  Problem: d473 "秒杀求幂题(求幂系列题4)" from scientific             */
/*  Language: CPP (1608 Bytes)                                                    */
/*  Result: TLE(1s) judge by this@ZeroJudge                                       */
/*  Author: ZJOJSFUS at 2013-07-07 03:54:31                                       */
/**********************************************************************************/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <cmath>
using namespace std;

int main(){
	string sn;
	string sa;
	int a;
	int n;
	
	vector<int > lastbase;
	vector<int > lastav;//記錄用
	bool over = false;
	int overcount = 0;
	int index;
	while(cin>>sa>>sn){
		//預處理
		int i = 0;
		if(over){
			overcount++;
			continue;
		}
		if(sa == "0" && sn == "0"){
			cout<<"All Over. ";
			over = true;
			continue;
		}
			/*
		while(sa[0] == '0' && sa.size() > 1)
			sa.erase(sa.begin());
		while(sn[0] == '0' && sn.size() > 1)//0
			sn.erase(sn.begin());*/
		stringstream ss;//no clear
		ss.clear();
		ss<<sa<<" "<<sn;
		ss>>a>>n;

		if(a == 0){
			cout<<"0"<<endl;
			continue;
		}
		if(n == 0){
			cout<<"1"<<endl;
			continue;
		}
		if(a == 1 || a == -1){
			if(a == 1 || (sn[sn.size()-1] - '0') % 2 == 0)
				cout<<"1"<<endl;
			else
				cout<<"-1"<<endl;
			continue;
		}
		else{
			cout<<pow(a, n)<<endl;
		}
		
	}
	cout<<"Exceeded "<<overcount<<" lines!"<<endl;
	
	return 0;
}
