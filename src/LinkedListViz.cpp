#include "LinkedListViz.h"
#include "mainWindow.h"
#include "CircleNode.h"
#include "Line.h"
#include <QLabel>

ListNode::ListNode(int val) : value(val), next(nullptr) {}

LinkedListViz::LinkedListViz() : head(nullptr), window(nullptr) {}

LinkedListViz::~LinkedListViz() {
    ListNode* current = head;
    while (current) {
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

void LinkedListViz::append(int value) {
    ListNode* newNode = new ListNode(value);
    if (!head) {
        head = newNode;
        return;
    }
    
    ListNode* current = head;
    while (current->next) {
        current = current->next;
    }
    current->next = newNode;
}

void LinkedListViz::display(QApplication* app, std::function<void()> onBack) {
    window = new mainWindow(900, 200, app, "Linked List Visualization");
    
    if (onBack) {
        window->setOnBackCallback(onBack);
    }
    
    ListNode* current = head;
    int x = 50;
    int y = 75;
    int spacing = 120;
    
    while (current) {
        CircleNode* node = new CircleNode(window->getParentWindow(), current->value);
        node->setGeometry(x, y, 50, 50);
        node->show();
        
        if (current->next) {
            Line* arrow = new Line(window->getParentWindow(), 
                                  x + 50, y + 25, 
                                  x + spacing - 20, y + 25);
            arrow->setAttribute(Qt::WA_TransparentForMouseEvents);
            arrow->lower();
            arrow->show();
        }
        
        x += spacing;
        current = current->next;
    }
    
    window->displayWindow(false);
}

LinkedListViz* LinkedListViz::createSampleList() {
    LinkedListViz* list = new LinkedListViz();
    
    list->append(10);
    list->append(20);
    list->append(30);
    list->append(40);
    list->append(50);
    
    return list;
}
