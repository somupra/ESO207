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

template<class T>
class Queue{
    private:
    T* queue;
    lli front;
    lli back;
    lli n;

    public:
    Queue(lli N){
        queue = new T[N];
        front = 0;
        back = 0;
        n = N;
    }

    void enqueue(T val){
        queue[back++] = val;
        back %= n;
    }

    T dequeue(){
        T tmp = queue[front++];
        front %= n;
        return temp;
    }

    bool isEmpty(){
        return (front == back) ? true : false;
    }

    void clear(){
        delete [] queue;
    }
};

int isBipartite(List<Node>* adj, lli n){
    Queue<lli> q(10011);
    repi(i, 0, n){

    }
}
bool checkBipartite(){
    lli v, e;
    cin >> v >> e;
    List<Node> graph[v];
    lli vis[v] = {0}, dis[v] = {0};
    Queue<lli> q(10011);

    repi(i, 0, e){
        lli x, y;
        cin >> x >> y;
        graph[x].addEdge(y);
    }
    
    repi(i, 0, v){
        if(vis[i] == 0) q.enqueue(i);
        lli u, v;
        while(!q.isEmpty()){
            u = q.dequeue();
            vis[u] = 1;
            for(auto child = graph[u].Head; child != NULL; child = child -> next){
                if(vis[child->val] == 0){
                    q.enqueue(child->val);
                    vis[child->val] = 1;
                    dis[child->val] += 1;
                }
                else if(dis[child->val] == dis[u]) return false;
            }
        }
    }
    return true;
    q.clear();
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cout << checkBipartite() ? "Yes\n" : "No\n";
    }
}
