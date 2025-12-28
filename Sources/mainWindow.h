//
// Created by Madhur Suman on 8/22/2024.
//

#ifndef QTPRO_MAINWINDOW_H
#define QTPRO_MAINWINDOW_H
#include <QApplication>
#include <QWidget>
#include <QString>
#include <iostream>

class mainWindow {
    QApplication app;
    QWidget main_window;
    int height;
    int width;
public:
    mainWindow(int window_h,int window_w,int argc,char*argv[],QString windowTitle);
    QWidget* getParentWindow();
    void displayWindow();
    int getHeight ();
    int getwidth ();

};


#endif //QTPRO_MAINWINDOW_H
