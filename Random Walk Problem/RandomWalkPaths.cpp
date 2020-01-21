#include<bits/stdc++.h>
#include <stdlib.h>  
using namespace std;

//2D array named "p" represents probability of winning in that position
double p[1003][1003];  //first index represents how far you are from the finish, second index indicates your opponent
int decision[1003][1003];//decision matrix (made up of 1s and 2s) -> 1 if definitive step, 2 if flip a coin
int path1[1002];
int path2[1002];

bool cmpf(double A, double B, double epsilon = 0.005f)//method used to compare two decimal numbers, returns true if they're equal
{ 
    return (fabs(A - B) < epsilon);
}

double dp(int i, int j){//recursive method to calculate the probability of winning from a certain position
	if(i < 0){//in case negative values are passed
		return 1;
	}
	else if(j < 0){//in case negative values are passed
		return 0;
	}
	else if(p[i][j] != -1){
		return p[i][j];
	}
	else if(i == 0){ //if second index is less than or equal to 0 than your opponent has won
		p[i][j] = 1;
		return 1;
	}
	else if(j == 0){ //if first index is less than or equal to 0 you have won
		p[i][j] = 0;
		return 0;
	}
	else{
		double ans1,ans2,ans3;
		
		ans1 = 1 - dp(j,i-1);
		
		ans2 = 1- 1.0/2*dp(j,i-2) + 1.0/2*dp(i,j-1);
		
		ans3 = 2.0/3 - 2.0/3*dp(j,i-2) + 1.0/3*dp(i,j-2);
		
		double max1 = max(ans1,min(ans2,ans3));//calculate probability
		
		//decision tracking
		if(cmpf(max1,ans1))//if ans1 is equal to max1
			decision[i][j] = 1;
		else
			decision[i][j] = 2;
		
		p[i][j] = max1;
		return max1;
	}
}

int main(){
	ofstream fout ("output4.text");
	int n;
	cout<<"Input:";
	scanf("%d", &n);//receive input for how far away you should start
	
	for(int i = 0; i <= 1001; i++){//initialize array set all probabilities to undefined
		for(int j = 0; j <= 1001; j++){
			p[i][j] = -1;
		}
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			dp(i,j);//calculate probabilities
		}
	}
	
	int p1=n,p2=n;//let p1 and p2 denote the distance from goal of player 1 and 2
	printf("Run simulation(the goal is to reach %d):\n", n);
	srand (time(NULL));//initialize random generator
	int turn = 0;
	while(p1 > 0 && p2 > 0){
		turn++;
		//Player 1 move
		if(decision[p1][p2] == 1){
			p1--;
		}
		else{
			int random = rand()%2+1;
			if(random == 1){//heads
				p1-=2;
			}
		}
		if(p1 <= 0){
			fout<<turn<<" "<<n-p1<<" "<<n-p2<<"\n";
			break;
		}
		//Player 2 move
		if(decision[p2][p1] == 1){
			p2--;
		}
		else{
			int random = rand()%2+1;
			if(random == 1){//heads
				p2-=2;
			}
		}
		//Print progress
		fout<<turn<<" "<<n-p1<<" "<<n-p2<<"\n";
	}
	if(p1 <= 0){
		cout<<"Player 1 won";
	}
	else{
		cout<<"Player 2 won";
	}
	return 0;
}
