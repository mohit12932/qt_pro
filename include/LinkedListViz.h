#ifndef QTPRO_LINKEDLISTVIZ_H
#define QTPRO_LINKEDLISTVIZ_H

#include <vector>
#include <functional>
#include <QApplication>

class mainWindow;

class ListNode {
public:
    int value;
    ListNode* next;
    
    ListNode(int val);
};

class LinkedListViz {
private:
    ListNode* head;
    mainWindow* window;
    
    void displayNodes();
    
public:
    LinkedListViz();
    ~LinkedListViz();
    
    void append(int value);
    void display(QApplication* app, std::function<void()> onBack = nullptr);
    
    static LinkedListViz* createSampleList();
};

#endif //QTPRO_LINKEDLISTVIZ_H
