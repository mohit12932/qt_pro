#include "Graph.h"
#include "mainWindow.h"
#include "Layout.h"
#include "CircleNode.h"
#include "Line.h"
#include <cmath>
#include <algorithm>

GraphNode::GraphNode(int nodeId, std::string nodeLabel) 
    : id(nodeId), label(nodeLabel.empty() ? std::to_string(nodeId) : nodeLabel), x(0), y(0) {}

GraphEdge::GraphEdge(int fromNode, int toNode, int edgeWeight, bool isDirected)
    : from(fromNode), to(toNode), weight(edgeWeight), directed(isDirected) {}

Graph::Graph(bool directed) : isDirected(directed), window(nullptr) {}

Graph::~Graph() {
    for (auto node : nodes) delete node;
    for (auto edge : edges) delete edge;
}

void Graph::addNode(int id, std::string label) {
    nodes.push_back(new GraphNode(id, label));
}

void Graph::addEdge(int from, int to, int weight) {
    edges.push_back(new GraphEdge(from, to, weight, isDirected));
}

void Graph::calculateLayout() {
    int n = nodes.size();
    if (n == 0) return;
    
    // Circular layout
    double radius = 250.0;
    double centerX = 400.0;
    double centerY = 400.0;
    double angleStep = 2.0 * M_PI / n;
    
    for (int i = 0; i < n; i++) {
        double angle = i * angleStep - M_PI / 2;
        nodes[i]->x = centerX + radius * cos(angle);
        nodes[i]->y = centerY + radius * sin(angle);
    }
}

void Graph::display(QApplication* app, std::function<void()> onBack) {
    window = new mainWindow(800, 800, app, "Graph Visualization");
    
    if (onBack) {
        window->setOnBackCallback(onBack);
    }
    
    calculateLayout();
    
    // Draw edges first (behind nodes)
    for (auto edge : edges) {
        GraphNode* fromNode = nullptr;
        GraphNode* toNode = nullptr;
        
        for (auto node : nodes) {
            if (node->id == edge->from) fromNode = node;
            if (node->id == edge->to) toNode = node;
        }
        
        if (fromNode && toNode) {
            Line* line = new Line(window->getParentWindow(), 
                                fromNode->x, fromNode->y, 
                                toNode->x, toNode->y);
            line->show();
        }
    }
    
    // Draw nodes
    for (auto node : nodes) {
        CircleNode* circleNode = new CircleNode(window->getParentWindow(), node->id);
        circleNode->setGeometry(node->x - 25, node->y - 25, 50, 50);
        circleNode->show();
    }
    
    window->displayWindow(false);
}

Graph* Graph::createSampleGraph() {
    Graph* graph = new Graph(false);
    
    // Create a sample graph
    for (int i = 1; i <= 6; i++) {
        graph->addNode(i);
    }
    
    graph->addEdge(1, 2);
    graph->addEdge(1, 3);
    graph->addEdge(2, 4);
    graph->addEdge(2, 5);
    graph->addEdge(3, 5);
    graph->addEdge(4, 6);
    graph->addEdge(5, 6);
    
    return graph;
}
