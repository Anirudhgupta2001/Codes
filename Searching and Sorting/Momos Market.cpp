//Momos Market

//Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ?n? number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ?q? days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
//Input Format:
//First-line will have an integer ?n? denoting the number of shops in the market.
//The next line will have ?n? numbers denoting the price of one momo of each shop.
//The next line will have an integer ?q? denoting the number of days she will visit the market.
//Next ?q? lines will have one integer ?X? denoting the money she saved after buying vegetables.
//Constraints:
//1 <= n <= 10^5
//1 <= q <= 10^4
//1 <= X <= 10^9
//1 <= rate per momo <=10^9 (for each shop)
//Output:
//There will be ?q? lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
//Sample Input:
//4
//2 1 6 3
//1
//11
//Sample Output:
//3 2
//Explanation:
//Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR.

#include<bits/stdc++.h>
using namespace std;
long long binary(long long *a,long long left,long long n,long long x)
{
    long long mid=(left+n)/2;    
    if(a[mid+1]>x && a[mid]<=x)
    {
        return mid;
    }
    else if(a[mid]>x)
    {
        return binary(a,left,mid-1,x);
    }
    else if(a[mid]<x)
    {
        return binary(a,mid+1,n,x);
    }
}
int main()
{
	long long n;
    cin>>n;    
    long long *a=new long long[n];
    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        cin>>a[i];        
        sum+=a[i];
        a[i]=sum;
    }
    sort(a,a+n);
    long long q;
    cin>>q;
    
    while(q>0)
    {
        long long x;
    	cin>>x;
        if(x<a[n-1])
        {
            long long index=binary(a,0,n,x);
            cout<<index+1<<" ";
            cout<<x-a[index]<<endl;
        }
        else
        {
            cout<<n<<" "<<x-a[n-1]<<endl;            
        }
    	
        q--;
    }
    
    return 0;
}
