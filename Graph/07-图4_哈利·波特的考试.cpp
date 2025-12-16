#include<iostream>
#include<vector>
#include <climits>

using namespace std;

#define Vertex int
#define WeightType int
#define DataType vector<string>
#define ERROR -1

struct GNode {
    int Nv;
    int Ne;
    std::vector<std::vector<int>> G;
    DataType Data;
};

GNode* CreatGraph(int Nv) {//空图
    GNode* Graph = new GNode;
    Graph->Nv = Nv;
    Graph->Ne = 0;
    for (int i = 0; i < Nv; i++) {
        vector<int>col;
        for (int j = 0; j < Nv; j++) {
            col.push_back(INT_MAX);//初始化为无穷大，表示无边
        }
        Graph->G.push_back(col);
    }

    return Graph;
}

typedef struct ENode* PtrToENode;
struct ENode {//Edge是插入的中介
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

void InsertEdge(GNode* Graph, Edge E) {
    Graph->G[E->V1][E->V2] = E->Weight;
    //如果是无向图还要加边<V2,V1>
    Graph->G[E->V2][E->V1] = E->Weight;
    return;
}

GNode* BuildGraph() {
    GNode* G; int Nv, Ne;
    cin >> Nv;
    G = CreatGraph(Nv);

    Edge E;
    cin >> Ne;
    if (Ne) {
        E = new ENode;
        for (int i = 0; i < Ne; i++) {
            Vertex V1, V2; WeightType Weight;
            cin >> V1 >> V2;
            E->V1 = V1 - 1; E->V2 = V2 - 1;
            cin >> Weight;
            E->Weight = Weight;
            InsertEdge(G, E);
        }
        delete E;

    }
    //if 有顶点数据
    /*Vertex V;
    for (V = 0; V < Nv; V++) {
        string y;
        cin >> y;
        G->Data.push_back(y);
    }*/
    return G;
}



int FindMinDist(GNode* G, vector<int>dist, vector<int>collected) {
    //寻找未被收录的顶点中dist最小的顶点
    Vertex MinVertex;
    int MinDist = INT_MAX;
    for (int V = 0; V < G->Nv; V++) {
        if (!collected[V] && dist[V] < MinDist) {
            MinDist = dist[V];
            MinVertex = V;
        }
    }
    if (MinDist < INT_MAX)
        return MinVertex;
    else
        return ERROR;//如果没找到，可能是这个点与剩下点都不连通
    //或所有顶点都被收录了
}

bool Dijkstra(GNode* G, vector<int>& dist, vector<int>& path, Vertex S) {
    vector<int>collected;

    for (int V = 0; V < G->Nv; V++) {
        //初始化dist
        dist.push_back(0);      //这里是占位，不占位会越界，下面再赋值
        dist[V] = G->G[S][V];   //根据邻接矩阵初始化dist
        //初始化path
        if (G->G[S][V] < INT_MAX)
            path.push_back(S);      //与0有边的点，前驱设为0
        else path.push_back(-1);    //其他用-1表示无前驱
        collected.push_back(0);     //初始化collected
    }
    dist[S] = 0;     //源点到自己的距离为0
    collected[S] = 1;//收录源点

    Vertex V;
    while (1) {
        //开始处理
        V = FindMinDist(G, dist, collected);//取未收录的dist最小的点
        if (V == ERROR)
            break;                          //不存在和退出条件
        collected[V] = 1;                   //收录该点
        for (int W = 0; W < G->Nv; W++) {   //对图中每个顶点W
            //若W是V的邻接点且未被收录
            if (!collected[W] && G->G[V][W] < INT_MAX) {
                //若有负权边，算法失败，返回false
                if (G->G[V][W] < 0)
                    return false;
                //若经V到W的距离更短，则更新dist和path
                if (dist[V] + G->G[V][W] < dist[W]) {
                    dist[W] = dist[V] + G->G[V][W];
                    path[W] = V;
                }
            }
        }
    }
    //如果有没colloected的，证明顶点S不能到达所有顶点，图不联通
    for (int i = 0; i < collected.size(); i++) {
        if (!collected[i])
            return false;
    }
    return true;
}
void PrintMinPath(vector<int>path, Vertex V) {
    while (path[V] != -1) {
        cout << V << " ";
        V = path[V];
    }
    cout << endl;
}
void MaxDist(vector<int>dist, vector<int>& maxdist) {
    int maxnum = 0;
    for (int i = 0; i < dist.size(); i++) {
        maxnum = maxnum > dist[i] ? maxnum : dist[i];
    }
    maxdist.push_back(maxnum);
}
int main() {
    GNode* Graph = BuildGraph();
    vector<int>dist, path;
    vector<int>maxdist;
    bool IsConnectedGraph = true;
    for (int V = 0; V < Graph->Nv; V++) {
        if (Dijkstra(Graph, dist, path, V)) {//当源点为0
            MaxDist(dist, maxdist);
        }
        else {
            cout << 0;
            IsConnectedGraph = false;
            break;
        }
    }
    if (IsConnectedGraph) {
        int minN = 0;
        for (int i = 0; i < maxdist.size(); i++) {
            minN = maxdist[minN] <= maxdist[i] ? minN : i;
        }
        cout << minN + 1 << " " << maxdist[minN];
    }
    return 0;
}
