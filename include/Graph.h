#ifndef QTPRO_GRAPH_H
#define QTPRO_GRAPH_H

#include <vector>
#include <map>
#include <string>
#include <functional>
#include <QApplication>

class mainWindow;
class Layout;

class GraphNode {
public:
    int id;
    std::string label;
    int x, y;
    
    GraphNode(int nodeId, std::string nodeLabel = "");
};

class GraphEdge {
public:
    int from;
    int to;
    int weight;
    bool directed;
    
    GraphEdge(int fromNode, int toNode, int edgeWeight = 1, bool isDirected = false);
};

class Graph {
private:
    std::vector<GraphNode*> nodes;
    std::vector<GraphEdge*> edges;
    mainWindow* window;
    bool isDirected;
    
    void calculateLayout();
    void displayNodes();
    void displayEdges();
    
public:
    Graph(bool directed = false);
    ~Graph();
    
    void addNode(int id, std::string label = "");
    void addEdge(int from, int to, int weight = 1);
    void display(QApplication* app, std::function<void()> onBack = nullptr);
    
    static Graph* createSampleGraph();
};

#endif //QTPRO_GRAPH_H
