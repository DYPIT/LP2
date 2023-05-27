#include <bits/stdc++.h>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[])
{
    int MST = 0;

    vector<int> vis(V, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    //{wt, node}

    while (!pq.empty())
    {

        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if (vis[node] == 1)
            continue;

        vis[node] = 1;
        MST += wt;

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWt = it[1];

            if (!vis[adjNode])
            {
                pq.push({edgeWt, adjNode});
            }
        }
    }
    return MST;
}

int main()
{   
    cout<<"Enter no of vertices and edges : "<<endl;
    int V, E;
    cin >> V >> E;

    vector<vector<int>> adj[V];

    int i = 0;
    cout<<"Enter u v and w : "<<endl;
    while (i++ < E)
    {
        int u, v, w;

        cin >> u >> v >> w;
        vector<int> t1, t2;

        t1.push_back(v);

        t1.push_back(w);

        adj[u].push_back(t1); 
        t2.push_back(u);

        t2.push_back(w);
        adj[v].push_back(t2);
    }

    cout<<spanningTree(V, adj);
    return 0;
}



// INPUT FORMAT 1
// Enter no of vertices and edges3 3
// Enter u v and w0 1 5
// 1 2 3
// 0 2 1

// OP->4


// INPUT FORMAT 2
// 2 1
// Enter u v and w : 
// 0 1 5
// OP->5