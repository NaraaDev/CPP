#include<bits/stdc++.h>
using namespace std;
int main(){
		map<string, int> a, b;
    string e[20000];
    int d[2000],m=0,n,i;	
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>e[i]>>d[i];
        a[e[i]]=a[e[i]]+d[i];
    }
    for(i=1; i<=n; i++) {
		m=max(m, a[e[i]]);}
    for(i=1; a[e[i]]<m || (b[e[i]]=b[e[i]]+d[i])<m; i++);
  {
	
	cout<<e[i];
}
}