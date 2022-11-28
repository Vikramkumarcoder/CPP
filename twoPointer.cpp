#include<iostream>
#include<vector>


using namespace std;
void vdisplay(vector<int> &vec){
    cout<<"[";
    for(int ele: vec){
	    cout<<ele<<",";
	}
	cout<<"]";
	cout<<endl;
}
string hasPairSum(vector<int>&arr, int x){
    for(int i=0; i<arr.size(); i++){
	    int t = x-arr[i];
	    for(int j=i+1; j<arr.size(); j++){
	        if(arr[j]==t){
	            return "Yes"; 
	        }
	    }
	}
	return "No";
}

string hasPairDifference(vector<int>&arr, int x){
    for(int i=0; i<arr.size(); i++){
	    for(int j=i+1; j<arr.size(); j++){
	        if(abs(arr[i]-arr[j])==x){
	            return "Yes"; 
	        }
	    }
	}
	return "No";
}

void sortSquaresOfNum(vector<int>&v){
    vector<int>ans;
    int left = 0, right = v.size()-1;
    while(left<=right){
        if(abs(v[left])>abs(v[right])){
            ans.push_back(v[left]*v[left]);
            left++;
        }
        else if(abs(v[left])<abs(v[right])){
            ans.push_back(v[right]*v[right]);
            right--;
        }
        else if(left==right){
            int t = v[right]*v[right];
            ans.push_back(t);
            right--;
            left++;
        }
        else{
            int j = v[right]*v[right];
            ans.push_back(j);
            ans.push_back(j);
            right--;
            left++;
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<"size: "<<ans.size()<<endl;
    for(int ele: ans){
        cout<<ele<<" ";
    }
}

int find3sum(vector<int>&v, int target){
    int l,r;
    int count = 0;
    for(int i=0; i<v.size()-2; i++){
        l = i+1;
        r = v.size()-1;
        while(l<r){
            if(v[l]+v[i]+v[r] == target){
                cout<<v[i]<<"+"<<v[l]<<"+"<<v[r]<<endl;
                count++;
                r--;
            }
            else if(v[l]+v[i]+v[r] > target){
                r--;
            }
            else l++;
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
	vector<int>v={1,0,1,1,0,1, 1, 0,0,0,1};
	
	//sorting array for 0 and 1
	int n = v.size();
	int low = 0, high = n-1;
	while(low<high){
	    if(v[low] == 1 and v[high] == 0){
	        v[low++] = 0;
	        v[high--] = 1;
	    }
	    else if(v[low] == 1 and v[high] == 1) high--;
	    else low++;
	}
	vdisplay(v);
	
	//sorting array for evens and odds
	v = {1,2,3,4,5};
	n = v.size();
	low = 0;
	high = n-1;
	while(low<high){
	    if(v[low]%2 == 1 and v[high]%2 == 0){
	        int temp = v[low];
	        v[low++] = v[high];
	        v[high--] = temp;
	    }
	    else if(v[low]%2 == 1 and v[high]%2 == 1) high--;
	    else low++;
	}
	vdisplay(v);
	
	//sorting square of sorted array
	/*int x;
	cout<<"Enter no. of element: ";
	cin>>x;
	vector<int>arr;
	for(int i=0; i<x; i++){
	    int ele;
	    cin>>ele;
	    arr.push_back(ele);
	}
	vdisplay(arr);
	sortSquaresOfNum(arr);*/
	
	//Merse two sorted arrays and sort it
	int arr1[] = {1,22,32,42,52};
	int arr2[] = {6,7,8,9,10};
	int len1 = sizeof(arr1)/4;
	int len2 = sizeof(arr2)/4;
	int total = len1+len2;
	int i = len1-1,j = len2-1, k = total-1;
	int ans[total];
	while(i>=0 || j>=0){
	    //cout<<i<<" "<<j<<":|"<<k<<"|:";
	    if (arr1[i]<arr2[j] && j>=0){
	        ans[k--] = arr2[j--];
	    }
	    else{
	        ans[k--] = arr1[i--];
	    }
	}
	for(int ele:ans){
	    cout<<ele<<" ";
	}
	cout<<endl;
	
	//is there exist pair of sum exactly x
	vector<int>arr3 = {-1,0,1,2,3};
	int y = 2;
	cout<<hasPairSum(arr3, y)<<endl;
	cout<<hasPairDifference(arr3, 5)<<endl;
	
	//pairs of sum
	arr3 = {2,2,2};
	int c = 0;
	int tar = 4;
	for(int i=0; i<arr3.size(); i++){
	    int t = tar-arr3[i];
	    for(int j=i+1; j<arr3.size(); j++){
	        if(arr3[j]==t){
	            c++; 
	        }
	    }
	}
	cout<<c;
	
	//count targert triplet sum
	arr3 = {-2, -1,0,1,2};
	int goal = 0;
	cout<<endl;
	cout<<find3sum(arr3, goal);
	
	
	return 0;
}