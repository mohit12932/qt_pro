//
// Created by Madhur Suman on 8/23/2024.
//

#ifndef QTPRO_CIRCLENODE_H
#define QTPRO_CIRCLENODE_H
#include <QWidget>
#include <QLabel>
#include <iostream>


class CircleNode:public QLabel{
    bool resizehandle;
public:
    CircleNode(QWidget* window,int value);

    void resizeEvent(QResizeEvent *event) override;

};



#endif //QTPRO_CIRCLENODE_H
