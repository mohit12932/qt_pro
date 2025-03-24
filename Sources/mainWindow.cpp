//
// Created by Madhur Suman on 8/22/2024.
//

#include "mainWindow.h"
#include <QApplication>
#include <QWidget>
#include <QString>



mainWindow::mainWindow(int window_h, int window_w,int argc,char*argv[],QString windowTitle): app(argc,argv),height(window_h),width(window_w) {
    main_window.setWindowTitle(windowTitle);
    main_window.setStyleSheet("border:2px white solid");
    main_window.resize(window_w,window_h);

}

void mainWindow::displayWindow() {
    main_window.show();
    app.exec();
}

QWidget* mainWindow::getParentWindow() {
    return &main_window;
}
int mainWindow::getHeight() {
    return  main_window.height();
}
int mainWindow::getwidth() {
    return main_window.width();
}