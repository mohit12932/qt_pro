//
// Created by Madhur Suman on 8/26/2024.
//


#ifndef QTPRO_LAYOUT_H
#define QTPRO_LAYOUT_H
#include <QGridLayout>
#include "mainWindow.h"
#include "Line.h"

class Layout : public QGridLayout{
    int rows;
    int columns;
    mainWindow *main;
    std::map<Line * ,int[4]> lines;
public:
    Layout(mainWindow * mainWindow,int row,int column);
    void addNode(int Node_Value,int row,int column);
    std::pair<int,int> *getCellCenter(int row,int column);
    void setGeometry(const QRect &rect) override;

   void setLine(Line *line,int row1, int column1, int row2, int column2);

    void addLine(int row1, int column1, int row2, int column2);
};



#endif //QTPRO_LAYOUT_H
