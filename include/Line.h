
#ifndef TRY_LINE_H
#define TRY_LINE_H


#include <QWidget>
#include <QPainter>

class Line : public QWidget {
Q_OBJECT

public:
    explicit Line(QWidget* parent, int x1 , int y1 , int x2 , int y2);

//protected:
    void paintEvent(QPaintEvent *event) override;
    void setPosition(int x1, int y1, int x2, int y2);
private:
    int m_x1{}, m_y1{}, m_x2{}, m_y2{};


};

#endif //TRY_LINE_H
