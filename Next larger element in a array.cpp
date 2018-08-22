#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void f1(vector<ll> v1, ll n)
{
	vector<ll> Map(10000);
	stack<ll> st;
	st.push(v1[0]);
	for (ll i = 1; i < n; i++)
	{
		if (st.empty())
		{
			st.push(v1[i]);
			continue;
		}
		while (!st.empty() && v1[i] > st.top())
		{
			Map[st.top()] = v1[i];
			st.pop();
		}
		st.push(v1[i]);
	}
	while (!st.empty())
	{
		Map[st.top()] = -1;
		st.pop();
	}
	for (ll i = 0; i < n; i++)
	{
		cout << Map[v1[i]] << ' ';
	}

}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		vector<ll> v1;
		ll n, a;
		cin >> n;
		for (ll i = 0; i < n; i++)
		{
			cin >> a;
			v1.push_back(a);
		}
		f1(v1, n);
		cout << '\n';
	}
}
