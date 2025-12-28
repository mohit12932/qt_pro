#include "Line.h"
#include <QResizeEvent>
#include<QPainter>
#include <iostream>


Line::Line(QWidget* mainwindow, int x1, int y1, int x2, int y2): QWidget(mainwindow), m_x1(x1), m_y1(y1), m_x2(x2), m_y2(y2){
      setAttribute(Qt::WA_StyledBackground);

    setPosition(x1,y1,x2,y2);




}

void Line::paintEvent(QPaintEvent *event) {

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(Qt::white);
    painter.drawLine(m_x1, m_y1, m_x2, m_y2);
}

void Line::setPosition(int x1, int y1, int x2, int y2){
    m_x1 = x1;
    m_x2= x2;
    m_y1 = y1;
    m_y2 = y2;
    int width = std::abs(x2-x1);
    int height = std::abs(y2-y1);
    resize(width,height);
    int minX=std::min(x1,x2);
    int minY=std::min(y1,y2);
    move(minX,minY);

    m_x1 -= minX;
    m_y1 -= minY;
    m_x2 -= minX;
    m_y2 -= minY;
    repaint();


}