#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[])
{
    vis[node] = 1;
    cout<<node<<" ";
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj);
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
            dfs(i, vis, adj);
        }
    }

    return 0;
}


// INPUT FORMAT
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

// o/p = 0 1 2 3 4 


// INTPUT FORMAT 2
// Enter no of Rows
// 5
// Enter no of Cols
// 5
// Enter the matrix values
// 0 0 0 0 1 
// 1 0 1 0 1
// 0 1 0 1 0
// 0 0 1 0 1
// 0 1 0 1 0  

//op = 0 4 1 2 3