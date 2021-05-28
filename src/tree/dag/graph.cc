// A C++ program to print topological sorting of a DAG
#include <iostream>
#include <list>
#include <set>
#include <stack>
#include <vector>
using namespace std;

// Class to represent a graph
//
// 笔记
// 邻接表的方式实现
// 这里使用了链表
// 使用数组也是可以的
class Graph {
  int V;  // No. of vertices'

  // Pointer to an array containing adjacency listsList
  list<int>* adj;

  // A function used by topologicalSort
  void topologicalSortUtil(int v, bool visited[], stack<int>& Stack);

 public:
  Graph(int V);  // Constructor

  // function to add an edge to graph
  void addEdge(int v, int w);

  // prints a Topological Sort of the complete graph
  void topologicalSort();

  // detect cycle
  bool detectCycle();
  bool processDfsTree(int i, vector<bool>& visited, stack<int>& s,
                      set<int>& collection);
  void printCycle(stack<int>& s);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
  adj[v].push_back(w);  // Add w to v’s list.
}

// A recursive function used by topologicalSort
void Graph::topologicalSortUtil(int v, bool visited[], stack<int>& Stack) {
  // Mark the current node as visited.
  visited[v] = true;

  // Recur for all the vertices adjacent to this vertex
  list<int>::iterator i;
  for (i = adj[v].begin(); i != adj[v].end(); ++i)
    if (!visited[*i]) topologicalSortUtil(*i, visited, Stack);

  // Push current vertex to stack which stores result
  Stack.push(v);
}

// The function to do Topological Sort. It uses recursive
// topologicalSortUtil()
// 笔记：
// 这个代码感觉有点神奇
// 无论从那个节点开始，最终栈的上的顺序是一致的
// 比如：
// 1->2->3
// 假设从2开始，stack里面为 3->2
// 最后1还没访问过，1入stack，结果stack为：3->2->1
void Graph::topologicalSort() {
  stack<int> Stack;

  // Mark all the vertices as not visited
  bool* visited = new bool[V];
  for (int i = 0; i < V; i++) visited[i] = false;

  // Call the recursive helper function to store Topological
  // Sort starting from all vertices one by one
  for (int i = 0; i < V; i++)
    if (visited[i] == false) topologicalSortUtil(i, visited, Stack);

  // Print contents of stack
  while (Stack.empty() == false) {
    cout << Stack.top() << " ";
    Stack.pop();
  }

  cout << endl;
}

bool Graph::processDfsTree(int i, vector<bool>& visited, stack<int>& s,
                           set<int>& collection) {
  for (auto e : adj[i]) {
    s.push(e);
    if (collection.find(e) != collection.end()) {
      return true;
    } else {
      collection.insert(e);
      visited[e] = true;
      if(processDfsTree(e, visited, s, collection))
        return true;
    }
  }
  return false;
}

// ref: https://www.baeldung.com/cs/detecting-cycles-in-directed-graph
// DAG环检测
// 接合遍历算法DFS(Depth-First-Search)实现,
// 如果某个node的路径上，出现了祖先节点被访问过的清空，则 判定存在环
bool Graph::detectCycle() {
  vector<bool> visited(V, false);
  for (int i = 0; i < V; ++i) {
    if (!visited[i]) {
      visited[i] = true;
      stack<int> s; // 辅助打印环
      set<int> collection; // 统计此DFS tree上出现的节点集合
      collection.insert(i);
      s.push(i);
      if (processDfsTree(i, visited, s, collection)) {
        std::cout << "contain cycle" << std::endl;
        printCycle(s);
        return true;
      }
    }
  }
  return false;
}

void Graph::printCycle(stack<int>& s) {
  while (!s.empty()) {
    int e = s.top();
    s.pop();
    std::cout << e << "->";
  }
  std::cout << std::endl;
}

// Driver program to test above functions
int main() {
  // Create a graph given in the above diagram
  Graph g(6);
  g.addEdge(5, 2);
  g.addEdge(5, 0);
  g.addEdge(4, 0);
  g.addEdge(4, 1);
  g.addEdge(2, 3);
  g.addEdge(3, 1);
  g.addEdge(1, 2);

  bool contain_cycle = g.detectCycle();
  cout << "detectCycle:" << contain_cycle << endl;

  if (!contain_cycle) {
    cout << "Following is a Topological Sort of the given graph n: ";
    g.topologicalSort();
  }

  return 0;
}
