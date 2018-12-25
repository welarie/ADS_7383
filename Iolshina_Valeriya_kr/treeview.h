#ifndef TREEVIEW_H
#define TREEVIEW_H
#include "bst.h"

class TreeView : public QWidget
{
Q_OBJECT
public:
explicit TreeView(QWidget *parent = nullptr);
void Push_key(int a);
void Push_flag(bool a);
BST* tree;
protected:
void paintEvent(QPaintEvent *event) override;
int Pop_key();
bool Pop_flag();

private:
void drawNode(QPainter *painter, BST *root, int x, int y);
// Ширина/Высота элемента
int nodeWidth{ 120 };
int nodeHeight{ 25 };
int key; // Имя искомого/добавляемого элемента
bool flag; // true - элемент был, false - элемент добавили
};
#endif // TREEVIEW_H
