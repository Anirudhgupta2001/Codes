//Replace Character Recursively

//Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
//Do this recursively.
//Input Format :
//The first line of input will contain an integer T, which will denote the value of number of test cases. In the following lines, T test cases will be written.
//The first line of each test case will contain a string S. 
//The following line of each test case will contain two space separated characters, c1 and c2, respectively.
//Output Format :
//For each test case, the first and only line of output contains the updated string S.
//Constraints :
// 1 <= T <= 100
// 1 <= Length of String S <= 100
//Sample Input :
//1
//abacd
//a x
//Sample Output :
//xbxcd

#include<bits/stdc++.h>
using namespace std;
void replace(char *s,char m,char r)
{
    if(s[0]=='\0')
    {
        return ;
    }
    if(s[0]==m)
    {
        s[0]=r;
    }
    replace(s+1,m,r);
}
int main(){
    
	int t;
    cin>>t;
    while(t>0)
    {
        char *s;
        char m,r;
        cin>>s>>m>>r;
        replace(s,m,r);
        cout<<s<<endl;
        t--;
    }
    return 0;
}
