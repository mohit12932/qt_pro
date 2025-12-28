//
// Created by Madhur Suman on 8/26/2024.
//

#include "Layout.h"
#include "CircleNode.h"
#include "mainWindow.h"


Layout::Layout(mainWindow *mainWindow, int row,int column):main(mainWindow){
    rows = row;
    columns = column;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            addWidget(new QLabel(mainWindow->getParentWindow()),i,j);
        }
        mainWindow->getParentWindow()->setLayout(this);
    }


}
void Layout::setGeometry(const QRect &rect) {
    QGridLayout::setGeometry(rect);
    for (auto i : lines){
        setLine(i.first,i.second[0],i.second[1],i.second[2],i.second[3]);
    }


}
void Layout::addNode(int Node_Value, int row, int column) {
    CircleNode *node = new CircleNode(main->getParentWindow(),Node_Value);
    addWidget(node,row,column);
}
void Layout::addLine(int row1,int column1,int row2,int column2){
    Line * line = new Line(main->getParentWindow(),0,0,0,0);


    lines[line][0] = row1 ;
    lines[line][1] = column1 ;
    lines[line][2] = row2;
    lines[line][3] = column2 ;
//   setLine(line,row1,column1,row2,column2);




}
void Layout::setLine(Line *line,int row1,int column1,int row2,int column2){

    int y1 = getCellCenter(row1,column1)->first;
    int y2 = getCellCenter(row2,column2)->first;
    int x1 = getCellCenter(row1,column1)->second;
    int x2 = getCellCenter(row2,column2)->second;
    line->setPosition( x1,  y1, x2, y2);

}
std::pair<int,int> * Layout::getCellCenter(int row,int col) {
    std::pair<int,int> *p = new std::pair<int,int>;
    p->first=((main->getHeight())/rows*row)+(main->getHeight()/rows/2);
    p->second = ((main->getwidth())/columns*col)+(main->getwidth()/(columns*2));
    return p;

}
