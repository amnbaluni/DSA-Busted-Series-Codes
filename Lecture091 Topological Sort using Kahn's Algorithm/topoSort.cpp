#include <bits/stdc++.h> 
#include <unordered_map>
#include <queue>
#include <list>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    //create adjaceny list
    unordered_map<int,list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }

    //find all indegree
    vector<int> indegree(v);
    for(auto i:adj){
      for(auto j:i.second){
        indegree[j]++;
      }
    }

    //zero indegree walo ko queue mein daaldo
    queue<int> q;
    for(int i=0; i<v; i++){
      if(indegree[i]==0){
        q.push(i);
      }
    }

    //do bfs
    vector<int> ans;
    while(!q.empty()){
      int front = q.front();
      q.pop();
      ans.push_back(front);

      //neighbour ki indegree bhi to nikalo
      for(auto neighbour:adj[front]){
        indegree[neighbour]--;
        if(indegree[neighbour]==0){
          q.push(neighbour);
        }
      }
    }
    return ans;
}

Time Complexity - O(N+E)
Space Complexity - O(N+E)
  
