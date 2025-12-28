//
// Created by Madhur Suman on 8/23/2024.
//

#ifndef QTPRO_CIRCLENODE_H
#define QTPRO_CIRCLENODE_H
#include <QWidget>
#include <QLabel>
#include <QString>
#include <iostream>


class CircleNode:public QLabel{
    QString nodeColor;
public:
    CircleNode(QWidget* window, int value, QString color = "#e74c3c");

    void resizeEvent(QResizeEvent *event) override;

};



#endif //QTPRO_CIRCLENODE_H
