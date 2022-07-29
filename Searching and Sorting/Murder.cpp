//Murder

//Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.
//Answer may not fit in integer . You have to take long.
//Input Format:
//First line of input contains an integer T, representing number of test case.
//For each test case, first line of input contains integer N, representing the number of stairs.
//For each test case, second line of input contains N space separated integers, representing numbers written on the stairs.
//Constraints
//T<=10^5
//1<=N<=10^5
//All numbers will be between 0 and 10^9
//Sum of N over all test cases doesn't exceed 5*10^5
//Output Format
//For each test case output one line giving the final sum for each test case.
//Sample Input 1:
//1
//5
//1 5 3 6 4
//Sample Output 1:
//15
//Explanation:
//For the first number, the contribution to the sum is 0.
//For the second number, the contribution to the sum is 1.
//For the third number, the contribution to the sum is 1.
//For the fourth number, the contribution to the sum is 9 (1+5+3).
//For the fifth number, the contribution to the sum is 4 (1+3).
//Hence the sum is 15 (0+1+1+9+4).

#include<bits/stdc++.h>
using namespace std;
long long merge(int* A,int left,int mid,int right)
{
    int i=left,j=mid,k=0;
 	int temp[right-left+1];
	long long sum = 0;
    long long ans = 0;
	while(i<mid && j<=right)
    {
		if(A[i] < A[j])
        {
            sum+=A[i];
			temp[k++] = A[i++];
            
		}else
        {
         	ans += (right - j + 1) * sum;  
            sum = 0;
			temp[k++] = A[j++];
			//sum +=A[i];
		}
	}
    ans += (right - j + 1) * sum;
	while(i<mid)
    {
		temp[k++] = A[i++];
	}
	while(j<=right)
    {
		temp[k++] = A[j++];
	}
	for(int i=left,k=0;i<=right;i++,k++)
    {
		A[i] = temp[k];
	}
	return ans;   
}
long long sum(int *a,int left,int right)
{
    long long count=0;
    if(left<right)
    {
        long long mid=(left+right)/2;
        return sum(a,left,mid) + sum(a,mid+1,right) + merge(a,left,mid+1,right);
    }
    return count;
    
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
        
        cout<<sum(a,0,n - 1)<<endl;
        t--;
    }
	
    return 0;
}
