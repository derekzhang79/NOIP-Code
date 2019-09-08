#include <iostream>
#include <queue>

using namespace std;

const int N = 10010, M = 200010;
int n, m, s, t, he[N], ver[M], ne[M], HE[N], VER[M], NE[M], tot(0), TOT(0);
int can[N], inroad[N], dis[N];
queue<int> q;

void add(int u, int v)
{
	ver[++tot] = v; ne[tot] = he[u]; he[u] = tot;
}

void ADD(int u, int v)
{
	VER[++TOT] = v; NE[TOT] = HE[u]; HE[u] = TOT;
}


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		add(u, v);
		ADD(v, u);
	}
	cin >> s >> t;


	q.push(t);
	while (q.size())
	{
		int u = q.front(); q.pop();
		can[u] = true;
		for (int i = HE[u]; i; i = NE[i])
		{
			int v = VER[i];
			if (!can[v])
				q.push(v);
		}
	}


	if (!can[s])
	{
		puts("-1");
		return 0;
	}


	for (int i = 1; i <= n; i++)
	{
		if (can[s])
		{
			inroad[i] = 1;
			for (int j = he[i]; j; j = ne[j])
			{
				if (!can[ver[j]])
				{
					inroad[i] = 0;
					break;
				}
			}
		}
	}

	
	while (q.size()) q.pop();
	q.push(s);
	while (q.size())
	{
		int u = q.front(); q.pop();
		if (u == t)
		{
			cout << dis[t] << endl;
			return 0;
		}
		for (int i = he[u]; i; i = ne[i])
		{
			int v = ver[i];
			if (inroad[v] && !dis[v])
			{
				dis[v] = dis[u] + 1;
				q.push(v);
			}
		}
	}
	puts("-1");

	return 0;
}