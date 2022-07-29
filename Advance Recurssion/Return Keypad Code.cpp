//Return Keypad Code

//Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
//The numbers and their corresponding codes are given below:
//0: ""
//1: ""
//2: "abc"
//3: "def"
//4: "ghi"
//5: "jkl"
//6: "mno"
//7: "pqrs"
//8: "tuv"
//9: "wxyz"
//Return empty string for numbers 0 and 1.
//Note:
//1. The order of strings are not important.
//2. The input number will have digits between: [2, 9].
//Input Format :
//First line of input will contain T number of test cases.
//Each input consists of a single line containing an integer n.
//Output Format :
//For each test case, print all possible strings in different lines.
//Constraints :
//1 <= T <= 100
//1 <= n <= 10^6
//Sample Input:
//1
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
using namespace std;
int code(int n,string out[])
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
        int num=code(n/10,out);
        int t=num;
        string s="abc";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];                
              //  cout<<out[t+j]<<" ";
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==3)
    {
    //	cout<<d;
        int num=code(n/10,out);
        int t=num;
        string s="def";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];                
               // cout<<out[t+j]<<" ";
            }
            
            t+=num;
        }
        
        return t;
    }
    else if(d==4)
    {
        int num=code(n/10,out);
        int t=num;
        string s="ghi";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];                
              //  cout<<out[t+j]<<" ";
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==5)
    {
        int num=code(n/10,out);
        int t=num;
        string s="jkl";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];                
              //  cout<<out[t+j]<<" ";
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==6)
    {
    	int num=code(n/10,out);
        int t=num;
        string s="mno";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];                
              //  cout<<out[t+j]<<" ";
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==7)
    {
        int num=code(n/10,out);
        int t=num;
        string s="pqrs";
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];                
              //  cout<<out[t+j]<<" ";
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==8)
    {
        int num=code(n/10,out);
        int t=num;
        string s="tuv";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];                
              //  cout<<out[t+j]<<" ";
            }
            
            t+=num;
        }
       
        return t;
    }
    else if(d==9)
    {
        int num=code(n/10,out);
        int t=num;
        string s="wxyz";
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<num;j++)
            {
                out[t+j]=out[j]+s[i];                
              //  cout<<out[t+j]<<" ";
            }
            
            t+=num;
        }
       
        return t;
    }        
}
int main()
{
    int t;
    cin>>t;
    while(t>0)
    {
   		 int n;
        cin>>n;
        int num=0;
        int temp=n;
        while(temp!=0)
        {
        	num++;
        	temp=temp/10;
		}
		//cout<<num;
        string *out=new string[10000];
        int  c=code(n,out);
        for(int i=0;i<c;i++)
        {
        //	cout<<out[3].length();
        	if(out[i].size()==num)
            cout<<out[i]<<endl;
        }
        t--;    
    }
    return 0;          
   
}
