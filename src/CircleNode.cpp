//
// Created by Madhur Suman on 8/23/2024.
//

#include <QLabel>
#include "CircleNode.h"
#include <iostream>
#include <sstream>
#include <QWidget>
#include <QGridLayout>


CircleNode::CircleNode(QWidget *window, int value, QString color) : QLabel(window), nodeColor(color) {
    setAttribute(Qt::WA_StyledBackground);
    setText(QString::fromStdString(std::to_string(value)));
    setAlignment(Qt::AlignCenter);
    
    // Set font styling
    QFont font = this->font();
    font.setPointSize(14);
    font.setBold(true);
    setFont(font);
}

void CircleNode::resizeEvent(QResizeEvent *event) {
    int radius = qMin(this->height(), this->width()) / 2;
    int marginV = (this->height() - qMin(this->height(), this->width())) / 2;
    int marginH = (this->width() - qMin(this->height(), this->width())) / 2;
    
    QString style = QString(
        "border: 3px solid white;"
        "background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 %1, stop:1 %2);"
        "border-radius: %3px;"
        "margin: %4px %5px;"
        "color: white;"
        "font-weight: bold;"
    ).arg(nodeColor, nodeColor, QString::number(radius), 
          QString::number(marginV), QString::number(marginH));
    
    this->setStyleSheet(style);
}
//std::pair<int,int> getCenter (){
//    QPoint point =
//}


//    std::cout<<newWidth<<std::endl;


//    resize(newWidth, newHeight);
