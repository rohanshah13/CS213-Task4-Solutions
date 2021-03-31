#include<bits/stdc++.h>

using namespace std;
int minm = 1e9;
int leaf = 1;

void calc_shortest(vector<vector<int> > &graph, vector<int> &parent , int par, int root, int depth){
    
    int child = 0;
    for(int i=0;i<graph[root].size();i++){
        if(graph[root][i] != par){
            parent[graph[root][i]] = root;
            calc_shortest(graph, parent, root, graph[root][i], depth+1);
            child++;
        }
    }
    if(child==0){
        // minm = min(minm, depth);
        if(minm>depth){
            minm = depth;
            leaf = root;
        }
    }
    return;
}

int main(){
    

    int n;
    cin>>n;
    vector<vector<int> > graph(n+1);
    vector<int> parent(n+1);

    for(int i =0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    calc_shortest(graph,parent, 1,1, 0);

    // cout<<leaf<<endl;
    vector<int> path;
    while(leaf!=1){
        path.push_back(leaf);
        leaf = parent[leaf];
    }
    
    cout<<1<<" ";
    while(path.size()>0){
        cout<<path.back()<<" ";
        path.pop_back();
    }

    cout<<"\n";
    
}