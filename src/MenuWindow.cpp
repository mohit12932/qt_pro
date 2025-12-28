#include "MenuWindow.h"
#include "TreeNode.h"
#include "Graph.h"
#include "LinkedListViz.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFont>

MenuWindow::MenuWindow(QApplication* application, QWidget *parent) 
    : QMainWindow(parent), app(application) {
    setupUI();
}

MenuWindow::~MenuWindow() {}

void MenuWindow::setupUI() {
    setWindowTitle("Data Structure Visualizer");
    resize(500, 600);
    
    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    
    // Title
    QLabel* title = new QLabel("Data Structure Visualizer", this);
    QFont titleFont("Arial", 24, QFont::Bold);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    title->setStyleSheet("color: white; padding: 20px;");
    layout->addWidget(title);
    
    // Subtitle
    QLabel* subtitle = new QLabel("Choose a data structure to visualize:", this);
    subtitle->setAlignment(Qt::AlignCenter);
    subtitle->setStyleSheet("color: #cccccc; font-size: 14px; padding-bottom: 20px;");
    layout->addWidget(subtitle);
    
    // Buttons
    layout->addWidget(createStyledButton("🌳 Binary Tree", "#e74c3c"));
    layout->addWidget(createStyledButton("🔗 Graph", "#3498db"));
    layout->addWidget(createStyledButton("➡️ Linked List", "#2ecc71"));
    layout->addWidget(createStyledButton("🔍 Binary Search Tree", "#f39c12"));
    
    layout->addStretch();
    
    // Footer
    QLabel* footer = new QLabel("Built with Qt6 | 2025", this);
    footer->setAlignment(Qt::AlignCenter);
    footer->setStyleSheet("color: #666666; font-size: 12px; padding: 10px;");
    layout->addWidget(footer);
    
    centralWidget->setLayout(layout);
    setCentralWidget(centralWidget);
    
    // Window styling
    setStyleSheet("QMainWindow { background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
                  "stop:0 #2c3e50, stop:1 #34495e); }");
    
    // Connect buttons
    QList<QPushButton*> buttons = centralWidget->findChildren<QPushButton*>();
    if (buttons.size() >= 4) {
        connect(buttons[0], &QPushButton::clicked, this, &MenuWindow::showBinaryTree);
        connect(buttons[1], &QPushButton::clicked, this, &MenuWindow::showGraph);
        connect(buttons[2], &QPushButton::clicked, this, &MenuWindow::showLinkedList);
        connect(buttons[3], &QPushButton::clicked, this, &MenuWindow::showBST);
    }
}

QPushButton* MenuWindow::createStyledButton(const QString& text, const QString& color) {
    QPushButton* button = new QPushButton(text, this);
    button->setMinimumHeight(70);
    button->setFont(QFont("Arial", 16));
    button->setCursor(Qt::PointingHandCursor);
    
    QString style = QString(
        "QPushButton {"
        "   background-color: %1;"
        "   color: white;"
        "   border: none;"
        "   border-radius: 10px;"
        "   padding: 15px;"
        "   margin: 5px 30px;"
        "   text-align: left;"
        "}"
        "QPushButton:hover {"
        "   background-color: %2;"
        "}"
        "QPushButton:pressed {"
        "   background-color: %3;"
        "}"
    ).arg(color, color, color);
    
    button->setStyleSheet(style);
    return button;
}

void MenuWindow::showBinaryTree() {
    hide();
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);
    
    root->display(app, [this]() {
        show();
        raise();
        activateWindow();
    });
}

void MenuWindow::showGraph() {
    hide();
    
    Graph* graph = Graph::createSampleGraph();
    graph->display(app, [this]() {
        show();
        raise();
        activateWindow();
    });
}

void MenuWindow::showLinkedList() {
    hide();
    
    LinkedListViz* list = LinkedListViz::createSampleList();
    list->display(app, [this]() {
        show();
        raise();
        activateWindow();
    });
}

void MenuWindow::showBST() {
    hide();
    
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(30);
    root->right = new TreeNode(70);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(40);
    root->right->left = new TreeNode(60);
    root->right->right = new TreeNode(80);
    root->left->left->left = new TreeNode(10);
    root->right->right->right = new TreeNode(90);
    
    root->display(app, [this]() {
        show();
        raise();
        activateWindow();
    });
}
