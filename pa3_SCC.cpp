#include<iostream>
#define repi(i,a,b) for(lli i = (a); i < (b); i++)

using namespace std;
typedef long int li;
typedef long long int lli;

class Node{
    public:
        lli val;
        Node* next = NULL;
        Node(lli val){
            this->val = val;
        }
};

template<class T>
    class List{
        public:
        T* Head;
        List(){
            Head = NULL;
        }
        
        void addEdge(lli val){
            Node* node = new T(val);
            node -> next = Head;
            Head = node;
        }
    };

lli t = 0;

void dfs_graph(List <Node>* g, lli* fin, lli* vis, lli v){
    vis[v] = 1;
    for(auto cnode = g[v].Head; cnode != NULL; cnode = cnode -> next){
        if(vis[cnode->val] == 0)
            dfs_graph(g, fin, vis, cnode->val);
    }
    fin[v] = t++;
}

lli count = 0;
void dfs_transpose(List <Node>* g, lli* vis, lli node){
    vis[node] = 1;
    count++;
    for(auto cnode = g[node].Head; cnode != NULL; cnode = cnode -> next){
        if(vis[cnode->val] == 0){
            dfs_transpose(g, vis, cnode->val);
        }
    }
}

void getscc(){
    lli v, e;
    cin >> v >> e;
    List<Node> g[v], ig[v];
    lli f[v];
    lli vis[v];
    
    repi(i, 0, v) vis[i] = 0;
    t = 0;
    repi(i, 0, e){
        lli x, y;
        cin >> x >> y;
        g[x].addEdge(y);
        ig[y].addEdge(x);
    }
    
    repi(node, 0, v){
        if(vis[node] == 0)
            dfs_graph(g, f, vis, node);
    }
    
    lli ord[v];
    repi(i, 0, v){
        vis[i] = 0;
        ord[v - f[i] - 1] = i;
    }
    
    lli max_count = -1;
    repi(node_i, 0, v){
        if(vis[ord[node_i]] == 0){
            dfs_transpose(ig, vis, ord[node_i]);
        }
        
        if(count > max_count){
            max_count = count;
        }
        count = 0;
    }
    cout << max_count << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        getscc();
    }
}
