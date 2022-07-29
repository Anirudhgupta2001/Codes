//Print Keypad Combinations Code

//Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
//Note : The order of strings are not important. Just print different strings in new lines.
//Input Format :
//Integer n
//Output Format :
//All possible strings in different lines
//Constraints :
//1 <= n <= 10^6
//Sample Input:
//23
//Sample Output:
//ad
//ae
//af
//bd
//be
//bf
//cd
//ce
//cf


#include<bits/stdc++.h>
#include<string>
using namespace std;
int code(int n,string out[],int nut)
{
    int d=n%10;
    //cout<<"!";
    if(d==0 || d==1)
    {
    //	cout<<d;
        out[0]="";
        return 1;
    }
    else if(d==2)
    {
    	//cout<<d;
        int num=code(n/10,out,nut);
        int t=num;
        string s="abc";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];  
				if(out[t+j].size()==nut)              
               cout<<out[t+j]<<endl;
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==3)
    {
    //	cout<<d;
        int num=code(n/10,out,nut);
        int t=num;
        string s="def";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i]; 
				if(out[t+j].size()==nut)               
                cout<<out[t+j]<<endl;
            }
            
            t+=num;
        }
        
        return t;
    }
    
    else if(d==4)
    {
        int num=code(n/10,out,nut);
        int t=num;
        string s="ghi";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i]; 
				if(out[t+j].size()==nut)               
                cout<<out[t+j]<<endl;
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==5)
    {
        int num=code(n/10,out,nut);
        int t=num;
        string s="jkl";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];                
                if(out[t+j].size()==nut)               
                cout<<out[t+j]<<endl;
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==6)
    {
    	int num=code(n/10,out,nut);
        int t=num;
        string s="mno";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];    
				if(out[t+j].size()==nut)               
                cout<<out[t+j]<<endl;
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==7)
    {
        int num=code(n/10,out,nut);
        int t=num;
        string s="pqrs";
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i]; 
				if(out[t+j].size()==nut)               
                cout<<out[t+j]<<endl;
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==8)
    {
        int num=code(n/10,out,nut);
        int t=num;
        string s="tuv";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];   
				if(out[t+j].size()==nut)               
                cout<<out[t+j]<<endl;
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==9)
    {
        int num=code(n/10,out,nut);
        int t=num;
        string s="wxyz";
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];
				if(out[t+j].size()==nut)               
                cout<<out[t+j]<<endl;
            }
            
            t+=num;
        }
       
        return t;
    }        
}
void printKeypad(int num)
{
	int n=0;
    int temp=num;
    string *out=new string[10000];
    while(temp!=0)
    {
        n++;
        temp=temp/10;
    }
   int m= code(num,out,n);
}

