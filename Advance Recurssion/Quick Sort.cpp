//Quick Sort Code

//Sort an array A using Quick Sort.
//Change in the input array itself. So no need to return or print anything.
//
//
//Input format :
//First line will contain T number of test case and each tet case will consist of two lines.
//Line 1 : Integer n i.e. Array size
//Line 2 : Array elements (separated by space)
//Output format :
//for every test case print rray elements in increasing order (separated by space) in a new line.
//Constraints :
//1 <= T <= 10
//1 <= n <= 10^5
//0 <= arr[i] <= 10^9
//Sample Input 1 :
//1
//6 
//2 6 8 5 4 3
//Sample Output 1 :
//2 3 4 5 6 8
//Sample Input 2 :
//1
//5
//1 5 2 7 3
//Sample Output 2 :
//1 2 3 5 7 



#include<bits/stdc++.h>
using namespace std;
int part(int *a,int si,int en)
{
    int count=0;
    //cout<<a[si]<<" "<<a[en]<<" ";
    for(int i=si;i<=en;i++)
    {
        if(a[si]>a[i])
        {
            count++;
        }
    }
  //  cout<<count<<" "<<endl;
    
    int temp=a[si];
    a[si]=a[count+si];
    a[count+si]=a[si];
    int j=en;
    for(int i=si;i<=(count+si) && j>=(count+si);)
    {
        if(a[i]>temp && a[j]<=temp)
        {
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
            i++;
            j--;
        }
        if(a[i]<temp)
        {
            i++;
        }
        if(a[j]>temp)
        {
            j--;
        }                
    }
    
    return si+count;
}
void quick(int *a,int si,int en)
{
    if(si>=en)
    {
        return;
    }
    int c=part(a,si,en);
    quick(a,si,c-1);
    quick(a,c+1,en);
}
int main(){
    
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
        quick(a,0,n-1);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        t--;
    }
    return 0;
}
