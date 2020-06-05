#include <bits/stdc++.h>
#define MAXN 100001

using namespace std;

int n;
int nodes[MAXN];
vector<int> mem[MAXN];
vector<int> graph[MAXN];

void change(int u, int x, bool cmp){
    vector<bool> mark(n, false);
    mark[u] = true;
    mem[u].push_back(u);

    queue<int> childs;
    childs.push(u);

    if(nodes[u] > x || cmp)
        nodes[u] = x;

    while(!childs.empty()){
        int v = childs.front();
        childs.pop();

        int sv = (int)graph[v].size();
        for(int i = 0; i < sv; i++){
            if(mark[graph[v][i]])
                continue;

            int w = graph[v][i];
            mem[u].push_back(w);
            mark[w] = true;

            if(nodes[w] > x || cmp)
                nodes[w] = x;

            int sw = mem[w].size();
            if(!sw){
                childs.push(w);
                continue;
            }

            for(int j = 0; j < sw; j++){
                if(mark[mem[w][j]])
                    continue;

                int z = mem[w][j];
                mem[u].push_back(z);
                mark[z] = true;
                if(nodes[z] > x || cmp)
                    nodes[z] = x;
            }
        }
    }
}

int main() {
    int m, q, u, v, i, s;

    cin >> n >> m >> q;
    while(m--){
        cin >> u >> v;
        graph[u-1].push_back(v-1);
    }

    while(q--){
        cin >> m >> u;
        u--;
        switch(m){
            case 1:
                cin >> v;
                s = mem[u].size();
                if(s)
                    for(i = 0; i < s; i++)
                        nodes[mem[u][i]] = v;
                else
                    change(u, v, true);
                break;
            case 2:
                cin >> v;
                s = mem[u].size();
                if(s){
                    for(i = 0; i < s; i++)
                        if(nodes[mem[u][i]] > v)
                            nodes[mem[u][i]] = v;
                }
                else
                    change(u, v, false);
                break;
            default:
                cout << nodes[u] << '\n';
                break;
        }
    }

    return 0;
}
//https://www.hackerrank.com/rest/contests/w25/challenges/dag-queries/hackers/raghumdani/download_solution