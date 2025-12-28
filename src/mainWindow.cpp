//
// Created by Madhur Suman on 8/22/2024.
//

#include "mainWindow.h"
#include <QApplication>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <QVBoxLayout>

mainWindow::mainWindow(int window_h, int window_w, QApplication* existingApp, QString windowTitle)
    : app(existingApp), height(window_h), width(window_w), onBackCallback(nullptr) {
    
    main_window = new QWidget();
    main_window->setWindowTitle(windowTitle);
    main_window->setStyleSheet(
        "background: qlineargradient(x1:0, y1:0, x2:0, y2:1, "
        "stop:0 #1a1a2e, stop:1 #16213e);"
    );
    main_window->resize(window_w, window_h);
    
    // Create compact icon-only back button
    backButton = new QPushButton("◄", main_window);
    backButton->setStyleSheet(
        "QPushButton {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #3498db, stop:1 #2980b9);"
        "   color: white;"
        "   border: 3px solid #ecf0f1;"
        "   border-radius: 25px;"
        "   padding: 0px;"
        "   font-size: 24px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #2980b9, stop:1 #21618c);"
        "   border: 3px solid white;"
        "}"
        "QPushButton:pressed {"
        "   background: #1f6391;"
        "}"
    );
    backButton->setGeometry(10, 10, 50, 50);
    backButton->setCursor(Qt::PointingHandCursor);
    backButton->setToolTip("Back to Menu");
    backButton->raise();
    
    QObject::connect(backButton, &QPushButton::clicked, [this]() {
        if (onBackCallback) {
            main_window->hide();
            onBackCallback();
        }
    });
}

mainWindow::~mainWindow() {
    delete main_window;
}

void mainWindow::displayWindow(bool blocking) {
    main_window->show();
    if (blocking && app) {
        app->exec();
    }
}

void mainWindow::setOnBackCallback(std::function<void()> callback) {
    onBackCallback = callback;
}

void mainWindow::hideWindow() {
    main_window->hide();
}

QWidget* mainWindow::getParentWindow() {
    return main_window;
}

int mainWindow::getHeight() {
    return main_window->height();
}

int mainWindow::getWidth() {
    return main_window->width();
}