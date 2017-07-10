/*
The puzzle before the program compiles is shown below.
530   070   000
600   195   000
098   000   060

800   060   003
400   803   001
700   020   006

060   000   280
000   419   005
000   080   079
Puzzle after compilation
530   070   000
600   195   000
098   000   060

800   060   003
400   803   001
700   020   006

060   000   280
000   419   005
000   080   079
Program ended with exit code: 0
*/
#include <stdio.h> 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool helper(vector<vector<int>>&board);
bool isValid(vector<vector<int>> & board, int num,int row,int col);
void willPrint(vector<vector<int>>& puzzle);

bool helper(vector<vector<int>>&board)
{
    for ( int i = 0; i<board.size();++i)
    {
        for ( int j = 0; j<board[i].size();++j)
        {
            if(board[i][j]!=0) continue;
            
            for ( int w = 1; w<10; ++w)
            {
                if(isValid(board,w,i,j))
                {
                    board[i][j]=w;
                    
                    if (helper(board)) return true;
                    board[i][j]=0;
                }
            }
            
            return false;
        }
    }
    
    return true;
}





bool isValid( vector<vector<int>>& board, int num, int row, int col)
{
    // check for rows
    for ( int i = 0; i<board.size();++i)
    {
        if (board[row][i]==num && i!=col)
        {
            return false;
        }
    }
    
    //check for columns
    for ( int j = 0; j<board.size();++j)
    {
        if (board[j][col]==num && j!=row)
        {
            return false;
        }
    }
    
    //check within boxes
    
    int a=0; int b =0;
    int x=3; int y=3;
    while (x<=row )
    {
        x+=x;
        a+=3;
    }
    
    while (y<=col)
    {
        y+=y;
        b+=3;
    }
    
    for ( a; a<x;++a) 
    {
        for ( b; b<y;++b)
        { if(board[a][b]==num && a!=row && b!=col)
        {
            return false;
        }
        }
    }
    return true;
}

void willPrint(vector<vector<int>>& puzzle){
  
    int t=3;
    
    for ( int i = 0; i<puzzle.size();++i)
    {
       int s=3;
        for ( int j = 0; j<puzzle[0].size();++j)
         {
            cout<<puzzle[i][j];
            if(j+1==s)
            {
                cout<<"   "; //separate columns
                 s+=s;
         }
    }
        
        if (i+1==t)
        {
            cout<<""<<endl;//separate rows
            t+=t;
        }
        cout<<endl;
    }
}

int main() {
    
    // your code goes here
    
    vector<int>columns(9,0); 
    
    vector<vector<int>>rows(9,columns); 
    
    rows[0][0]=5;  rows[0][4]=7;   rows[2][7]=6;
    
    rows[0][1]=3;  rows[1][3]=1;  
    
    rows[1][0]=6;  rows[1][4]=9;   
    
    rows[2][1]=9;  rows[1][5]=5;
    
    rows[2][2]=8;
    
    
    
    
    
    rows[3][0]=8;  rows[3][4]=6;   rows[3][8]=3;
    
    rows[4][0]=4;  rows[4][3]=8;   rows[4][8]=1;
    
    rows[5][0]=7;  rows[4][5]=3;   rows[5][8]=6;
    
    rows[5][4]=2;
    
    
    
    rows[6][1]=6;  rows[7][3]=4;   rows[6][6]=2;
    
    rows[7][4]=1;   rows[6][7]=8;
    
    rows[7][5]=9;  rows[8][4]=8;   rows[7][8]=5;
    
    rows[8][7]=7;
    
    rows[8][8]=9; //test inputs
    
    cout<< "The puzzle before compiling:"<<endl;
    willPrint(rows);
    
    
    helper(rows);
    
    
    cout<<"Puzzle after compilation"<<endl;
    willPrint(rows);
  
  
    return 0;
    
}
