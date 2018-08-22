#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void longestCorrectSecquence(vector<ll> &c, vector<ll> &o, string &s1, ll n)
{
	stack<ll> st;
	for (ll i = 0; i < n; i++)
	{
		if (s1[i] == '(')
			st.push(i);
		else if (s1[i] == ')')
		{
			if (!st.empty())
			{
				c[i] = 1;
				o[st.top()] = 1;
				st.pop();
			}
			else
				c[i] = 0;
		}
	}
	for (ll i = 1; i < n; i++)
	{
		c[i] += c[i - 1];
		o[i] += o[i - 1];
	}
}
ll query(vector<ll> &o, vector<ll> &c, ll s, ll e)
{
	if (s == 0)
		return 2 * c[e];
	else
		return (c[e] - (o[s - 1] - c[s - 1])) * 2;
}
int main()
{
	ll t;
		ll s, e;
		string s1;
		cin >> s1;
		ll n = s1.size();
		vector<ll> o(n + 1, 0), c(n + 1, 0);
		longestCorrectSecquence(c, o, s1, n);
		cin >> s >> e;
		cout << query(o, c, s, e) << '\n';
}
