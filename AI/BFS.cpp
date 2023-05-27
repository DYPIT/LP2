#include <bits/stdc++.h>
using namespace std;

void bfs(int V, vector<int> adj[], vector<int> &vis)
{

    // int vis[V]={0};
    queue<int> q;
    q.push(0);
    vis[0] =1;
    
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        vis[node] = 1;
        cout<<node<<" ";
        for(auto it: adj[node]) {
            if(!vis[it]) {
                q.push(it);
                vis[it] =1;
            }
        }
    }
}


int main()
{
    int row,col;
    cout<<"Enter no of Rows"<<endl;
    cin>>row;
    cout<<"Enter no of Cols"<<endl;
    cin>>col;

    vector<vector<int>> matrix(row, vector<int> (col,0));
    cout<<"Enter the matrix values"<<endl;
    for(int i=0; i<row; i++) {
        for(int j=0;j<col;j++) {
            cin>>matrix[i][j];
        }
    }

    int V = matrix.size();
    vector<int> adj[V];
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            if (i != j && matrix[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
        {
            bfs(V, adj,vis);
        }
    }

    return 0;
}


// INPUT FORMAT 1

// Enter no of Rows
// 5
// Enter no of Cols
// 5
// Enter the matrix values
// 0 1 0 0 1
// 1 0 1 0 1
// 0 1 0 1 0
// 0 0 1 0 1
// 0 1 0 1 0 
//o/p=0 1 4 2 3


// INPUT FORMAT 2
// Enter no of Rows
// 5
// Enter no of Cols
// 5
// Enter the matrix values
// 0 1 0 0 1
// 1 0 1 0 1
// 0 1 0 1 0
// 0 0 1 0 1
// 0 1 0 1 0

//o/p= 0 1 4 2 3