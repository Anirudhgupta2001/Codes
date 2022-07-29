//Sudoku Solver

//Coding Ninjas has provided you a 9*9 sudoku board. The board contains non zero and zero values. Non zero values lie in the range: [1, 9]. Cells with zero value indicate that the particular cell is empty and can be replaced by non zero values.
//You need to find out whether the sudoku board can be solved. If the sudoku board can be solved, then print true, otherwise print false.
//Input Format:
//There are nine lines in input. Each of the nine lines contain nine space separated integers. These nine lines represent the sudoku board.
//Output Format:
//The first and only line of output contains boolean value, either true or false, as described in problem statement.
//Constraints:
//The cell values lie in the range: [0, 9]
//Time Limit: 1 second 
//Note:
//Input are given in a way that backtracking solution will work in the provided time limit.
//Sample Input 1:
//9 0 0 0 2 0 7 5 0 
//6 0 0 0 5 0 0 4 0 
//0 2 0 4 0 0 0 1 0 
//2 0 8 0 0 0 0 0 0 
//0 7 0 5 0 9 0 6 0 
//0 0 0 0 0 0 4 0 1 
//0 1 0 0 0 5 0 8 0 
//0 9 0 0 7 0 0 0 4 
//0 8 2 0 4 0 0 0 6
//Sample Output 1:
//true

#include<bits/stdc++.h>
using namespace std;
# define n 9
bool empty(int **a,int &row,int &col)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i][j]==0)
            {
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false;
}
bool checkgrid(int  **a,int row,int col,int num)
{
    int rf=row-(row%3);
    int cf=col-(col%3);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(a[i+rf][j+cf]==num)
            {
                return false;
            }
        }
    }
    return true;
}
bool checkrow(int  **a,int col,int num)
{
    for(int i=0;i<n;i++)
    {
        if(a[i][col]==num)
        {
            return false;
        }        
    }
    return true;
}
bool checkcol(int  **a,int row,int num)
{
    for(int i=0;i<n;i++)
    {
        if(a[row][i]==num)
        {
            return false;
        }        
    }
    return true;
}
bool check(int **a,int row,int col,int i)
{
    return (checkcol(a,row,i) && checkrow(a,col,i) && checkgrid(a,row,col,i));
}
bool solve(int **a)
{
    int row,col;
   if(!empty(a,row,col))
   {
       return true;
   }
    for(int i=1;i<=n;i++)
    {
        if(check(a,row,col,i))
        {
            a[row][col]=i;
            if(solve(a))
            {
                return true;                
            }
            a[row][col]=0;
        }
       // else
       // {
    }
            return false;
    }
int main()
{
	int **a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[n];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    if(solve(a))
    {
       cout<<"true";
    }
    else
    {
        cout<<"false";
    }
    return 0;
}
