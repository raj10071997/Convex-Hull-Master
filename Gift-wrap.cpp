#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<limits>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#define gcd __gcd
#define pb(x) push_back(x)
#define ll long long
#define in(x) scanf("%d",&x)
#define mod 1000000007
#define sz(x) x.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define pii pair<int,int>
#define F first
#define S second
#define m_p make_pair
#define all(v) (v.begin(),v.end())
using namespace std;
int orientation(pii p,pii q,pii r)
{
	int res=(q.S-p.S)*(r.F-q.F)-(r.S-q.S)*(q.F-p.F);
	if(res==0)
		return 0;//collinear
	if(res<0)
		return 2;//counter-clockwise
	return 1;// clockwise
}
int main()
{
    ios::sync_with_stdio(0);
    cout<<"enter the number of points\n";
    int n;
    cin>>n;
    pii a[n];
    cout<<"enter the points\n";
    for(int i=0;i<n;i++)
    	cin>>a[i].F>>a[i].S;
    if(n<3)
	{
		cout<<"convex hull not possible\n";
		return 0;
	}
	vector<pii>hull;
	int p=0;
	for(int i=1;i<n;i++)
	{
		if(a[p].F<a[i].F)
			p=i;
	}
	int same=p;
	do
	{
		hull.pb(a[p]);
		int q=(p+1)%n;
		for(int i=0;i<n;i++)
		{
			if(orientation(a[p],a[i],a[q])==2)
				q=i;
		}
		p=q;
	}
	while(p!=same);
	cout<<"the points in convex hull are:\n";
	for(auto e:hull)
		cout<<"("<<e.F<<","<<e.S<<")"<<endl;
    return 0;
}

