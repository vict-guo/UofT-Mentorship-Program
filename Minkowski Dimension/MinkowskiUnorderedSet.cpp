#include<bits/stdc++.h>
#define PI 3.14159265358

using namespace std;
struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};
typedef pair<int,int> pii;
double M,a,b,expA[201],expB[201];
int n,N,num;
set<pii,pair_hash> s;

int main(){
	ofstream fout("FifthRunMinkowski.txt");
	a = 0.4;
	b = 5;
	for(int i = 0; i <= 200; i++){
		expA[i] = pow(a,i);
		expB[i] = pow(b,i);
	}

	//program run
	/*
	cout<<"Enter n and N:"<<"\n";
	cin >> n >> N;
	

	cout <<"Enter M between "<<floor(sqrt(n))<<" and "<<floor(n/10)<<"\n";
	cin >> M;
	*/
	n = 100000;
	N = 50;
	//for(int k = 1000; k <= 80000; k+=1000){
		M = floor(sqrt(n));
		for(int i = 0; i <= n ; i++){
			int x,z;
			double y = 0;
			x = floor((double)i/n*M);
			for(int j = 0; j <= N; j++){
				y+= expA[j] * cos(2*PI*expB[j]*i/n);
			}
			z = floor(y*M);
			s.insert(make_pair(x,z));
		}
		num = s.size();
		cout<<M<<" "<<log(num)/(log(M)- (1.0/2) * log(2))<<"\n";
		s.clear();
	//}
	return 0;
}

