//Love for Characters


//Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
//Input:
//First line contains an integer denoting length of the string.
//Next line contains the string.
//Constraints:
//1<=n<=10^5
//‘a’<= each character of string <= ‘z’
//Output:
//Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
//Sample Input:
//6
//aabsas
//Sample output:
//3 2 0

#include<bits/stdc++.h>
#include<map>
#include<string>
using namespace std;
void print(string s)
{
    map<int,int> m;   
    int j=0;
    for(int i=0;i<s.length();i++)
    {     
        m[s[i]-97]++;
    }
    cout<<m[0]<<" "<<m[18]<<" "<<m[15];
    return;
}
int main()
{
    string s;
    int n;
    cin>>n;
    cin>>s;
    print(s,);
	return 0;
}

