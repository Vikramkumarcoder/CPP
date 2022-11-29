#include<iostream>
#include<vector>
using namespace std;


void display(int arr[], int s){
    cout<<endl;
    for(int i=0; i<s-1; i++){
	    cout<<arr[i]<<",";
	}
	cout<<arr[s-1]<<endl;
}
void vdisplay(vector<int>&v){
    cout<<"[";
    for(int ele: v){
	    cout<<ele<<",";
	}
	cout<<"]";
	cout<<endl;
}

int main(int argc, char *argv[])
{
	//Unique element
	int arr[] = {9,1,2,2,3,3,4,4,1,9};
	int size = sizeof(arr)/4;
	int count = 0;
	for(int ele:arr){
	    count ^= ele;
	}	
	//cout<<count;
	
	//second largest
	int maximum = INT_MIN;
	for(int i=0; i<10; i++){
	    if(maximum<arr[i]){
	       maximum = arr[i];
	    }
	}
	//display(arr, size);
	
	
	//cout<<maximum;
	int secMax = INT_MIN;
	for(int i=0; i<10; i++){
	    if(maximum != arr[i] && secMax<arr[i]){
	       secMax = arr[i];
	    }
	}
	//cout<<secMax;
	//display(arr, size);
	//cout<<endl;
	
	
	//#1  Rotate element kth times
	int k = 9;
	k = k%size;
	/*for(int i=0; i<k; i++){
	    int last = arr[size-1];
	    for(int j=size-2; j>=0; j--){
	        arr[j+1] = arr[j];
	    }
	    arr[0] = last;
	}
	display(arr, size);
	cout<<endl;*/
	
	//#2 Rotate array
	//cout<<"size: "<<size<<endl;
	int ans[size];
	//cout<<"Original arr: ";
	//display(arr, size);
	//cout<<"size: "<<sizeof(arr);
	int indx = 0;
	for(int i=size-k; i<size; i++){
	    ans[indx++] = arr[i];
	}
	
	for(int i=0; i<(size-k); i++){
	    ans[indx++] = arr[i];
	}
	//cout<<"New arr: ";
	//display(ans, size);
	
	//#3 Rotate arr
	vector<int>v = {1,2,3,4,5};
	int r = 5;
	int n = v.size();
	r = r%n;
	vdisplay(v);
	reverse(v.begin(), v.end());
	//vdisplay(v);
	reverse(v.begin(), v.begin()+r);
	//vdisplay(v);
	reverse(v.begin()+r, v.end());	
	vdisplay(v);
	
	//Find the particular element in array
	int num;
	cout<<"Enter No.of elements: ";
	cin>>num;
	vector<int>vec(num);
	for(int &ele: vec){
	    cin>>ele;
	}
	vdisplay(vec);
	const int N = 1e5+10;//equal to 10^5
	vector<int>freq(N,0);
	
	for(int i=0; i<vec.size(); i++){
	    ++freq[vec[i]];
	}
	
	int query, input;
	cout<<"Enter Query: ";
	cin>>query;
	
	for(int i=0; i<query; i++){
	    cin>>input;
	    int ans = freq[input];
	    ans != 0?cout<<"YES, it's frequency is "<<ans<<endl : cout<<"NO"<<endl;
	}
	//vdisplay(freq);
	//cout<<N;
	
	return 0;
}