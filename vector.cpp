#include<iostream>
#include<vector>
using namespace std;


void display(vector<int>vec){
    cout<<endl;
    cout<<"vector: ";
    for(int ele:vec){
	    cout<<ele<<" ";
	}
	cout<<endl;
	return;
}


void measure(vector<int>v){
    cout<<"size: "<<v.size()<<endl;
	cout<<"capacity: "<<v.capacity()<<endl;
	return;
}

int main(int argc, char *argv[])
{
	vector<int>v = {10,11,12,77};
	display(v);
	measure(v);
	
	v.push_back(9);
	display(v);
	measure(v);
	
	v.push_back(8);
	display(v);
	measure(v);
	
	for(int i=0; i<=8; i++){
	    v.push_back(i);//It insert element at end
	}
	display(v);
	measure(v);
	
	v.pop_back(); //It remove last element
	display(v);
	
	v.resize(10); //resize function
	cout<<"size: "<<v.size()<<endl;
	cout<<"capacity: "<<v.capacity()<<endl;
	
	v.push_back(5);
	display(v);
	cout<<"size: "<<v.size()<<endl;
	cout<<"capacity: "<<v.capacity()<<endl;
	
	v.insert(v.begin()+3, 23);//It insert an element to the particular position
	display(v);
	v.insert(v.end()-2, 32);
	display(v);
	
	v.erase(v.begin()+2);//It can erase a particular positional element
	display(v);
	
	v.clear();
	display(v);
	
	return 0;
}