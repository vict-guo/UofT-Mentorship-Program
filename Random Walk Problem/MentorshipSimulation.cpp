#include<bits/stdc++.h>

using namespace std;
//2D array represents probability of winning in that position
double p[1001][1001];  //first index represents how far you are from the finish, second index indicates your opponent
int decision[1001][1001];
const double maxn = 99999.0;

bool cmpf(double A, double B, double epsilon = 0.005f)
{ 
    return (fabs(A - B) < epsilon);
}

double dp(int i, int j){
	if(p[i][j] != -1){
		return p[i][j];
	}
	else if(j == 0){ //if second index is less than or equal to 0 than your opponent has won
		p[i][j] = 0;
		return 0;
	}
	else if(i == 0){ //if first index is less than or equal to 0 you have won
		p[i][j] = 1;
		return 1;
	}
	else{
		double ans1,ans2,ans3;
		
		ans1 = 1 - dp(j-1,i);
		
		if(i >= 2)
			ans2 = 1 - 1.0/2 * dp(j,i-2) - 1.0/2* (1.0 - dp(i-1,j));
		else //if i < 2
			ans2 = 1 - 1.0/2* (1.0 - dp(i-1,j));
			
		if(i >= 2 && j >= 2)
			ans3 = 4.0/3 * (1- 1.0/2 * dp(j,i-2) - 1.0/2*(1-1.0/2*dp(i,j-2)));
		else if(i < 2 && j < 2)
			ans3 = 4.0/3 * (1-0.5);
		else if(i < 2)
			ans3 = 4.0/3 * (1 - 1.0/2*(1-1.0/2*dp(i,j-2)));
		else //if j < 2 and i > 2
			ans3 = 4.0/3 * (1- 1.0/2 * dp(j,i-2) - 1.0/2);
		
		double max1 = max(ans1,min(ans2,ans3));
		
		//decision tracking
		if(cmpf(ans1,max1))
			decision[i][j] = 1;
		else
			decision[i][j] = 2;
		
		p[i][j] = max1;
		return max1;
	}
}

int main(){
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0; i <= 1000; i++){
		for(int j = 0; j <= 1000; j++){
			p[i][j] = -1;
		}
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			printf("%.6f ", dp(i,j)); //print probabilities: rows are i and columns are j
		}
		cout<<"\n";
	}
	
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			printf("%d ", decision[i][j]); //print probabilities: rows are i and columns are j
		}
		cout<<"\n";
	}

	
	/*//code to check if values are right
	for(int i = 2; i <= n; i++){
		for(int j = 2; j <= n; j++){
			//if(p[i][j] != max(1.0-p[j-1][i],min(1.0-1.0/2*p[j][i-2]-1.0/2*(1-p[i-1][j]), 1.0 - 1.0/2 * p[j][i-2] - 1.0/2 * (1.0 - 1.0/2 * p[i][j-2] - 1.0/2*p[i][j]))))
				printf("%1.6f", max(1.0-p[j-1][i],min(1.0-1.0/2*p[j][i-2]-1.0/2*(1-p[i-1][j]), 1.0 - 1.0/2 * p[j][i-2] - 1.0/2 * (1.0 - 1.0/2 * p[i][j-2] - 1.0/2*p[i][j]))));
		}
		cout<<"\n";
	}*/

	return 0;
}
