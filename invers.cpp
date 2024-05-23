#include<iostream>
#include<vector>
using namespace std;

void Mirge(vector<int>& a, int l, int m, int r,int& inv){
	int i = l;
	int j = m;
	int k = 0;
	int c[r-l];
	while(i < m && j < r){
		if(a[i] < a[j]){
			c[k++] = a[i];
			++i;
		}
		else{
			c[k++] = a[j];
			inv += m - i;
			j++;
		}
	}
	while(i < m){
		c[k++] = a[i];
		++i;
	}
	while(j < r){
		c[k++] = a[j];
		++j; 
	}
	for(int s = l; s < r; s++){
		a[s] = c[s-l];
	}
}

void MirgeSort(vector<int>& a,int l, int r,int& inv){
 	if(r-l<=1) return;
 	int m = (l+r)/2;
 	MirgeSort(a,l,m,inv);
 	MirgeSort(a,m,r,inv);
 	Mirge(a,l,m,r,inv);
}


int main(){
	vector<int> v = {7,6,5,4,3,2,1};
	int n = v.size();
	int inv = 0;
	MirgeSort(v,0,n,inv);
	cout << inv << endl;
	for(auto now: v){
		cout << now << " ";
	}
	return 0;
}
