//Remove Duplicates Recursively

//Given a string S, remove consecutive duplicates from it recursively.
//Input Format :
//First line of input will contain T number of test cases
//Next T line will contain the string S
//Output Format :
//For every test case print the answer in a separate line
//Constraints :
//1 <= T <= 10
//1 <= |S| <= 10^4
//where |S| represents the length of string
//Sample Input 1 :
//1
//aabccba
//Sample Output 1 :
//abcba
//Sample Input 2 :
//1
//xxxyyyzwwzzz
//Sample Output 2 :
//xyzwz


#include<bits/stdc++.h>
using namespace std;
void remove(char *c)
{
    if(c[0]=='\0' || c[1]=='\0')
    {
        return ;
    }
    if(c[0]==c[1])
    {
        int i=1;
        for(;c[i]!='\0';i++)
        {
            c[i-1]=c[i];
        }
        c[i-1]='\0';
        remove(c);
    }
    else
    {
        remove(c+1);
    }
    
}
int main(){
    
    int t;
    cin>>t;
    while(t>0)
    {
    	char *c;
        cin>>c;
        remove(c);
        cout<<c<<endl;
        t--;
    }
    return 0;
}
