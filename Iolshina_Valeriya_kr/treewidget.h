#ifndef TREEWIDGET_H
#define TREEWIDGET_H
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include "treeview.h"
class TreeWidget : public QWidget
{
Q_OBJECT
public:
explicit TreeWidget(QWidget *parent = nullptr);
TreeView *view_;

private:
QLineEdit *lineEdit_;
QPushButton *button_ins;
QPushButton *button_del;
QLabel *step;

public slots:
void insert();
void del();

};

#endif // TREEWIDGET_
