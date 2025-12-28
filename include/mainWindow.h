//
// Created by Madhur Suman on 8/22/2024.
//

#ifndef QTPRO_MAINWINDOW_H
#define QTPRO_MAINWINDOW_H
#include <QApplication>
#include <QWidget>
#include <QString>
#include <QPushButton>
#include <functional>
#include <iostream>

class mainWindow {
    QApplication* app;
    QWidget* main_window;
    QPushButton* backButton;
    int height;
    int width;
    std::function<void()> onBackCallback;
public:
    mainWindow(int window_h,int window_w,QApplication* existingApp,QString windowTitle);
    ~mainWindow();
    QWidget* getParentWindow();
    void displayWindow(bool blocking = false);
    void setOnBackCallback(std::function<void()> callback);
    void hideWindow();
    int getHeight ();
    int getWidth ();

};


#endif //QTPRO_MAINWINDOW_H
