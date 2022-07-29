//
//Merge Sort Code

//Sort an array A using Merge Sort.
//Change in the input array itself. So no need to return or print anything.
//Input format :
//First line of input will contain T number of test cases
//First line of every input will contain a single integer N size of the input array.
//second line of each input will contain N space-separated integers.
//Output format :
//For every test case print, array elements in increasing order (separated by space) in a separate line.
//Constraints :
//1 <= T <= 10
//1 <= n <= 10^5
//Sample Input 1 :
//1
//6 
//2 6 8 5 4 3
//Sample Output 1 :
//2 3 4 5 6 8
//Sample Input 2 :
//1
//5
//2 1 5 2 3
//Sample Output 2 :
//1 2 2 3 5 


#include<bits/stdc++.h>
using namespace std;
void mergesort(int *a,int *b,int si,int en)
{
    if(si>=en)
    {
        return ;
    }
    int mid=(en-si)/2 + si;
    mergesort(a,b,si,mid);
    mergesort(a,b,mid+1,en);
    merge(a,b,si,mid+1,en);        
}
int main()
{
	int t;
    cin>>t;
    while(t>0)
    {
        int n;
        cin>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int *b = new int[n];
        mergesort(a,b,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
		cout<<endl;
        t--;
    }
    return 0;
}
