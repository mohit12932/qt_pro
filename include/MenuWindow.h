#ifndef QTPRO_MENUWINDOW_H
#define QTPRO_MENUWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QApplication>

class MenuWindow : public QMainWindow {
    Q_OBJECT

private:
    QApplication* app;

public:
    explicit MenuWindow(QApplication* application, QWidget *parent = nullptr);
    ~MenuWindow();

private slots:
    void showBinaryTree();
    void showGraph();
    void showLinkedList();
    void showBST();

private:
    void setupUI();
    QPushButton* createStyledButton(const QString& text, const QString& color);
};

#endif //QTPRO_MENUWINDOW_H
