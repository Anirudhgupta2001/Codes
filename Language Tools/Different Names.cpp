//Different Names

//In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
//Note: We don't have to mention names whose frequency is 1.
//Input Format:
//The only line of input will have a string ‘str’ with space separated first names of students.
//Output Format:
//Print the names of students along with their count if they are repeating. If no name is repeating, print -1
//Constraints:
//1 <= |str| <= 10^5
//Time Limit: 1 second
//Sample Input 1:
//Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
//Sample Output 1:
//harshit 2
//Ayush 3
//Iti 2
//Sample Input 2:
//Abhishek Harshit Ayush Iti
//Sample Output:
//-1



#include <iostream>
#include<vector>
#include<map>
using namespace std;
void print(string s)
{
    vector<string> v;
    int j=0;
    vector<string> :: iterator it;
    string wrd="";
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ')
        {
            v.push_back(wrd);
            j++;
            wrd="";
        }
        else
        {
            wrd=wrd+s[i];
        }
    }
    v.push_back(wrd);
    j++;
    map<string,int> m;
    map<string,int> :: iterator mt;
    bool flag=false;
    for(int i=0;i<j;i++)
    {
        if(m.find(v[i])==m.end())
        {
            m.insert(make_pair(v[i],1));
        }
        else
        {
            m[v[i]]++;
        }
    }
    
    for(mt=m.begin();mt!=m.end();mt++)
    {
        if(m[mt->first]>=2)
        {
            cout<<mt->first<<" "<<mt->second<<endl;
            flag=true;
        }
    }
    if(!flag)
    {
        cout<<-1;
    }
}
int main() 
{
    string s;
    getline(cin,s);
    print(s);
}
