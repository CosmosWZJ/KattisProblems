#include<iostream>  
#include<algorithm>  
#include<map>  
#include<cmath>  
using namespace std;  
  
char p[25005];  
  
map<char,int>   themap,newmap;  
  
int  cmp(char a,char b)  
{  
    if(themap[a]<themap[b])  return 1;  
    else return 0;  
}  
  
int main()  
{  
    int cas;  
    cin>>cas;  
    int n;  
    while(cas--)  
    {  
        themap.clear();  
        newmap.clear();  
        cin>>n;  
        char ch;  
        for(int i=0;i<n;i++)  
        {  
            cin>>ch;  
            p[i]=ch;  
            themap[ch]=i;  
        }  
          
        sort(p,p+n,cmp);  
          
        for(int i=0;i<n;i++)  
        {  
             newmap[p[i]]=i;  
        }  
        int ans=0;  
        for(int i=0;i<n;i++)  
        {  
            ans+=abs(themap[p[i]]-newmap[p[i]]);  
        }  
        ans*=5;  
        cout<<ans<<endl;  
          
          
    }  
}  