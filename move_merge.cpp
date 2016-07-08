#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int board[20][20]={0};

void board_transpose(int board[][20], int N){
	for(int row=0;row<N;row++)
		for(int col=row+1;col<N;col++){
			swap(board[row][col],board[col][row]);
			/* int temp=board[row][col];
			board[row][col] = board[col][row];
			board[col][row] = temp;
			*/ 
		}
}

void mergerow(int board[][20],int N){
	int k=0,left=0;
	for(int row=0;row<N;row++){
		for(int col=0;col<N;col++) {
			if(board[row][col]==0) continue;
			k=col+1;
			while(k<N && board[row][k]==0) k++;
			if(board[row][col]==board[row][k]){
				board[row][col]*=2;
				board[row][k] = 0;
			}
		}

		left=k=0;
		while(k<N){
			if(board[row][left]==0){
				k = max(left+1,k);
				while(k<N && board[row][k]==0) k++;
				board[row][left] = board[row][k];
				board[row][k] = 0;
			}
			left+=1;
		}
		/*
		for(int col=0;col<N;col++){
			if(board[row][col]==0){
				k=col+1;
				while(k<N && board[row][k]==0) k++;
				board[row][col] = board[row][k];
				board[row][k] = 0;
			}
		}
		*/
		/* int left=0,right=1;
		 while(right<N){
			while(right<N && board[row][right]==0){
				right++;
			}
			if(board[row][left] == board[row][right]){
				board[row][left] = 2*board[row][left];
				board[row][right] = 0;
				left+=1;
				right+=1;
			}
			else{
				left+=1;
				board[row][left] = board[row][right];
				if(left!=right) board[row][right] = 0;
				right+=1;
			}
		}
		left=right=0;
		while(right<N){
			while(right<N && board[row][right]==0) right++;
			board[row][left] = board[row][right];
			if(left!=right) board[row][right] = 0;
			left++;
			right++;
		}
		*/
	}
	
}

void reverserow(int board[][20],int N){
	for(int row=0;row<N;row++){
		reverse(board[row],board[row]+N);		
		/*
		for(int col=0;col<N/2;col++){
			swap(board[row][col],board[row][N-1-col]);
		}
		*/
	}
}

int main(){
	string action;
	int totalcase;
	int N;
	cin >> totalcase;
	for(int caseno=1;caseno <= totalcase;caseno++){
		cin >> N >> action;
		for(int row=0;row<N;row++){
			for(int col=0;col<N;col++){
				cin>>board[row][col];
			}
		}
		if(action.compare("up") == 0){
			board_transpose(board,N);
			mergerow(board,N);
			board_transpose(board,N);
		}
		else if(action.compare("right") == 0){
			reverserow(board,N);
			mergerow(board,N);
			reverserow(board,N);
		}
		else if(action.compare("down") == 0){
			board_transpose(board,N);
			reverserow(board,N);
			mergerow(board,N);
			reverserow(board,N);
			board_transpose(board,N);
		}
		else if(action.compare("left") == 0){
			mergerow(board,N);
		}
		else{
			cout << "unknown operation." << endl;
		}
		printf("Case #%d:\n",caseno);
		for(int row=0;row<N;row++){
			for(int col=0;col<N-1;col++){
				cout<<board[row][col]<<" ";
			}
			cout<<board[row][N-1]<<endl;
		}
	}

	
}
