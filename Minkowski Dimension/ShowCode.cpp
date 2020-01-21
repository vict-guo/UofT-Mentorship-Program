#include<bits/stdc++.h>
#define PI 3.14159265358

using namespace std;
typedef pair<int,int> pii;

set<pii> s;//set of unique pairs
double M,a,b;
int n,N,num;
int main(){

	a = 0.5;
	b = 3;
	n = 100000;
	N = 50;
	M = 5000;//this can easily be made to vary
	for(int i = 0; i <= n ; i++){//iterate over all n of the points to sample
		int x,z;
		double y = 0;
		x = floor((double)i/n*M);
		for(int j = 0; j <= N; j++){//calculate the value of the function at i/n
			y+= pow(a,j) * cos(2*PI*pow(b,j)*i/n);
		}
		z = floor(y*M);
		s.insert(make_pair(x,z));//insert the pair into a set which guarantees uniqueness
		}



	num = s.size(); //find the number of unique pairs

	cout<<M<<" "<<log(num)/log(M)<<"\n";

	return 0;
}


