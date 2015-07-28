#include <iostream>
#include <vector>
#include <string>
#include <map>
	
void hash::make_friends(string &fri){


}
void hash::make_friends_rp(string &fri){


}
void find_same(){

}
void hash::print(){
	int i, lo = lists.size(), lor = listr.size();
	for(i = 0; i < lo; i++)
		cout<<" "<<lists[i];
	for(i = 0; i < lor; i++)
		cout<<" "<<listr[i];
}

void hash_table::insert(string word){
	

}
void hash_table::insert(hash_node* node){
	hashmap.insert(pair<int,hash>(node->key, *node));//??ok
}