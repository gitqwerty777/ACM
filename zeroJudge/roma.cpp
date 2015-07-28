
#include <iostream>
#include <vector>
#include <cstdlib>
#include <sstream>
using namespace std;
void guxuan(string &bechu, string b, int lo, int lob, vector<int> &ans){//lo = bechu.size()
	int indexbe, indexb, i, j;
	string tempb, temp;
	int vb, v, gu;
	stringstream s;
	
	indexbe = 2; indexb = 2;
	if(lob == lo)
		tempb.assign(bechu, 0, indexbe);
	else
		tempb.assign(bechu, 0, ++indexbe);

	
	temp.assign(b, 0, indexb);
	vb = atof(tempb.c_str());
	v = atof(temp.c_str());
	gu = vb / v;
	
	//cout<<"guxuan"<<tempb<<" and "<<temp<<endl;
	
	if(indexb < lob){
		vb = vb * 10 + bechu[indexbe] - '0';
		v = v *10 + b[indexb] - '0';
	}
	
	while(gu != vb / v){//增
		gu = vb / v;
	//	cout<<"vb :"<<vb<<"v :"<<v<<endl;
		indexbe++; indexb++;
		if(indexbe >= lo && indexb >= lob)
			break;
		vb = vb * 10 + bechu[indexbe]- '0';
		v = v *10 + b[indexb]- '0';
	}
	
	tempb.assign(bechu, 0, lo);
	//cout<<tempb<<" - "<<b<<" * "<<gu;
	
	if(gu != 0){
		if(lob != lo){/*
			for(j = lob-1; j >= 0; j--){
				bechu[j+1] -= (b[j] - '0') * gu;
				while(bechu[j+1] < '0'){
					bechu[j+1] += 10;
					bechu[j] --;
				}
			}*/	
			
			for(i = 0; i < lob; i++){
				bechu[i+1] -= (b[i] - '0') * gu;
				while(bechu[i+1] < '0'){
					bechu[i+1] += 10;
					bechu[i] --;
				}
			}
		}
		else{
			for(i = 0; i < lob; i++){
				bechu[i] -= (b[i] - '0') * gu;
				while(bechu[i] < '0'){
					bechu[i] += 10;
					bechu[i-1] --;
				}
			}
		
			/*
			for(j = lob-1; j >= 0; j--){
				bechu[j] -= (b[j] - '0') * gu;
				while(bechu[j] < '0'){
					bechu[j] += 10;
					bechu[j-1] --;
				}
			}*/
			
		}
		
		for(i = lo-1; i >= 0; i--){
			while(bechu[i] < '0'){
				bechu[i] += 10;
				bechu[i-1] --;
			}
		}
		
		i = 0;
		while(!bechu.empty() && bechu[0] == '0'){
			bechu.erase(0, 1);
			i++;
		}
		tempb.assign(bechu, 0, lo-i);
		
		ans.push_back(gu);
		for(int j = 1; j < i && !bechu.empty(); j++)
			ans.push_back(0);
		
		//cout<<" = "<<bechu<<endl;
	}
	else{
		ans.push_back(gu);
	}
	
	//刪除0
}
void make_vector(string a, int loa, vector<int> &av){
	string temp; int count = loa, i = 0;
	do{
		count -= 9;
		if(count > 0)
			temp.assign(a, count, 9);
		else
			temp.assign(a, 0, count + 9);
			
		av.push_back(atof(temp.c_str()));
		i++;
	}while(count > 0);//check 8 進
}
void make_vector_4(string a, int loa, vector<int> &av){
	string temp; int count = loa, i = 0;
	do{
		count -= 4;
		if(count > 0)
			temp.assign(a, count, 4);
		else
			temp.assign(a, 0, count + 4);
			
		av.push_back(atof(temp.c_str()));
		i++;
	}while(count > 0);//check 8 進
}

int main(){
	string a, o, b;
	int i, j, k, flow, last, loa, lob, lo, lom, start, end, mid, gu;
	string ans;
	string chu, bechu, gus;
	//int con = 0;
	while(cin>>a>>o>>b){
		//con++;
		//if(con == 5)
		//	cout<<b<<endl;
		loa = a.size();
		lob = b.size();
		vector<int> ans;
		vector<int> av;
		vector<int> bv;
		ans.clear();
		av.clear(); bv.clear();

		if(o == "+"){
			make_vector(a, loa, av);
			make_vector(b, lob, bv);
			
			loa = av.size();
			lob = bv.size();
			
			lo = (loa>lob)?loa:lob;
			
			flow = 0;
			if(loa >= lob)
				for(i = 0; i < lo; i++){
					if(i < lob)
						ans.push_back(av[i] + bv[i] + flow);
					else
						ans.push_back(av[i] + flow);
					
					if(ans[i] >= 1000000000){
						ans[i] -= 1000000000;
						flow = 1;
					}
					else
						flow = 0;
				}
			else if(lob > loa)
				for(i = 0; i < lo; i++){
					if(i < loa)
						ans.push_back(av[i] + bv[i] + flow);
					else
						ans.push_back(bv[i] + flow);
					
					if(ans[i] >= 1000000000){
						ans[i] -= 1000000000;
						flow = 1;
					}
					else
						flow = 0;
				}
	
			if(flow)//進位了
				ans.push_back(1);
				
			int way, tempa;
			lo = ans.size();
			cout<<ans[lo-1];
			for(i = lo-2; i >= 0; i--){
				way = 9; tempa = ans[i];
				if(ans[i] == 0)
					cout<<"00000000";
				else{
					while(tempa != 0){
						tempa /= 10;
						way--;}
					while(way-- != 0)
						cout<<"0";
				}
				cout<<ans[i];
			}
			cout<<endl;
		}
		else if(o == "-"){//有負數嗎?
		
			bool change = false;
			if(loa < lob){//比大小
				string c = a;
				a = b;
				b = c;
				int loc = loa;
				loa = lob;
				lob = loc;
				change = true;
			}
			else if(loa == lob){
				for(i = 0; i < a.size(); i++)
					if(a[i] < b[i]){
						string c = a;
						a = b;
						b = c;
						int loc = loa;
						loa = lob;
						lob = loc;
						change = true;
						break;
					}
					else if(a[i] > b[i])
						break;
			}
			
			make_vector(a, loa, av);
			make_vector(b, lob, bv);
			
			loa = av.size();
			lob = bv.size();
			lo = (loa>lob)?loa:lob;
			
			//cout<<a << " - "<<b<<endl;
			flow = 0;
			for(i = 0; i < lo; i++){
				if(i < lob)
					ans.push_back(av[i] - bv[i] - flow);
				else
					ans.push_back(av[i] - flow);
				
				if(ans[i] < 0){
					ans[i] += 1000000000;
					flow = 1;
				}
				else
					flow = 0;
			}
		
			/*
			if(flow)//進位了
				ans.push_back(1);
			*/	
			int way, tempa;
			lo = ans.size();
			if(change)
				cout<<"-";
			cout<<ans[lo-1];
			for(i = lo-2; i >= 0; i--){
				way = 9; tempa = ans[i];
				if(ans[i] == 0)
					cout<<"00000000";
				else{
					while(tempa != 0){
						tempa /= 10;
						way--;}
					while(way-- != 0)
						cout<<"0";
				}
				cout<<ans[i];
			}
			cout<<endl;
		}
		else if(o == "*"){
			
			if(a == "0" || b == "0")
				cout<<"0"<<endl;
			else{
				ans.assign(loa + lob, 0);//設為00000
				av.push_back(0);
				bv.push_back(0);
				make_vector_4(a, loa, av);
				make_vector_4(b, lob, bv);
				
				loa = av.size();
				lob = bv.size();
				
				lo = (loa>lob)?loa:lob;
				
				flow = 0;
				for(i = 1; i < loa; i++)
					for(j = 1; j < lob; j++){
						ans[i + j] += (av[i] * bv[j]);
					
						if(ans[i + j] >= 10000){
							ans[i + j + 1] += ans[i + j] / 10000;
							ans[i + j] %= 10000;
						}
					}
				
				lo = ans.size();
				for(i = 0; i < lo; i++)
					if(ans[i] >= 10000){
						ans[i+1] += ans[i] / 10000;
						ans[i] %= 10000;
					}
				
				int way, tempa, real;
				lo = ans.size();
				
				real = lo-1;
				while(ans[real] == 0)
					real--;
				cout<<ans[real];
				for(i = real-1; i >= 2; i--){
					way = 4; tempa = ans[i];
					if(ans[i] == 0)
						cout<<"000";
					else{
						while(tempa != 0){
							tempa /= 10;
							way--;}
						while(way-- != 0)
							cout<<"0";
					}
					cout<<ans[i];
				}
				cout<<endl;
			}
		}
		else if(o == "/"){//無小除大
			ans.clear();
			int ok = 0;
			if(a == "0" || loa < lob){
				cout<<"0"<<endl;
				ok = 1;
			}
			else if(loa == lob){
				for(i = 0; i < loa ;i++)
					if(a[i] < b[i]){
						cout<<"0"<<endl;
						ok = 1;
						break;
					}
					else if(a[i] > b[i])
						break;
			}
			
			if(!ok){
				for(i = 0 ; i < loa - lob + 1; i++){//i = ans count
					if(a.size() < lob)
						break;
					bechu.assign(a, 0, lob);
					if(bechu >= b){
						//cout<<"no jinwei"<<endl;
						guxuan(a, b, lob, lob, ans);
					}
					else{
						if(a.size() == lob)
							break;
						guxuan(a,b, lob+1,  lob, ans);

					}
				}
				
				lo = ans.size();/*
				int real = 0;
				while(ans[real] == 0)
					real++;*/
				for(i = 0; i < lo ; i++)
					cout<<ans[i];
				
				cout<<endl;
			}
		}
	}
	
	return 0;
}
