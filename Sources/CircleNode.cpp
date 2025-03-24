//
// Created by Madhur Suman on 8/23/2024.
//

#include <QLabel>
#include "CircleNode.h"
#include <iostream>
#include <sstream>
#include <QWidget>
#include <QGridLayout>


CircleNode::CircleNode(QWidget *window, int value) : QLabel(window) {
    setAttribute(Qt::WA_StyledBackground);
    setText(QString::fromStdString(std::to_string(value)));
    std::ostringstream oss;
    oss << "background-color:red;border:2px solid white;";
    setAlignment(Qt::AlignCenter);


}

void CircleNode::resizeEvent(QResizeEvent *event) {

    this->setStyleSheet(
            QString::fromStdString(
                    "border: 2px solid white;background-color:red;border-radius:" + std::to_string(qMin(this->height(), this->width()) / 2) +
                    "px;margin:" + std::to_string((this->height()-qMin(this->height(), this->width()))/2) + " " +
                    std::to_string((this->width()-qMin(this->height(), this->width()))/2)));
}
//std::pair<int,int> getCenter (){
//    QPoint point =
//}


//    std::cout<<newWidth<<std::endl;


//    resize(newWidth, newHeight);
