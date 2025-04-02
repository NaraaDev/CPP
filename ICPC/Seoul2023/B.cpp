#include <bits/stdc++.h>
using namespace std;

// fenwick tree
int main()
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	vector<int> BIT(n);
	auto change=[&](int pos,int d)
	{
		pos++;
		for(int x=pos;x<=n;x+=x&-x)
			BIT[x]+=d;
	};
	auto query=[&](int pos)
	{
		pos++;
		int ret=0;
		for(int x=pos;x;x-=x&-x)
			ret+=BIT[x];
		return ret;
	};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		change(i,1);
	}
	swap(a[0],a[a[n-1]%(n-1)]);
	int m=0,p=n;
	for(int i=0;i<n;i++)
	{
		int x=a[i];
		int l=0,r=n-1;
		while(l<r)
		{
			int mid=(l+r)/2;
			if(query(mid)>=m+1)r=mid;
			else l=mid+1;
		}
		b[l]=x;
		change(l,-1);
		
		p-=1;
		if(p)
			m=(x+m-1)%p;
	}
	for(int i=0;i<n;i++)
		cout<<b[i]<<"\n";
	return 0;
}