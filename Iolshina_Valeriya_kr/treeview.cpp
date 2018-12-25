#include <QPainter>
#include <QFontMetrics>
#include <sstream>
#include <cmath>
#include "treeview.h"
#include "bst.h"
#include<iostream>

TreeView::TreeView(QWidget *parent) : QWidget(parent), tree(nullptr)
{
    tree = NULL;
}

void TreeView::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    drawNode(&painter, tree, 0, 0);
}

// Ставим, проверяем искомый элемент

void TreeView::Push_key(int a)
{
    key = a;
}

int TreeView::Pop_key()
{
    return key;
}

// Ставим, проверяем флаг

void TreeView::Push_flag(bool a)
{
    flag = a;
}

bool TreeView::Pop_flag()
{
    return flag;
}

// Отрисовываем дерево

void TreeView::drawNode(QPainter *painter, BST* root, int x, int y)
{
    if(root==nullptr)
        return;
    painter->save();
    int k = Pop_key();
    int root_k = root->key;
    bool f = Pop_flag();
// Описываем точку, от которой рисуем элемент
    QPoint p(width() / pow(2, y) * x + width() / pow(2, y+1), nodeHeight * y);
// Описываем прямоугольник (рамку)
    QRect rec(p.x() - nodeWidth/4, p.y(), nodeWidth/2, nodeHeight/2);
// Веделяем цветом искомый/добавленый элемент
    if (k == root_k)
    {
        if ( f )
            painter->setPen(Qt::green);
        else
            painter->setPen(Qt::red);
    }
// Рисуем рамку
    painter->drawRect(rec);
// Шрифт текста
    QFont font = painter->font() ;
    font.setPointSize(10);
    painter->setFont(font);
// Текст
    std::stringstream str;
//str<< root->Height(root) << std::endl <<root->key;
    str << root->key;
// Пишем текст
    QString text = fontMetrics().elidedText( QString::fromLatin1(str.str().c_str()), Qt::ElideLeft, rec.width() );
    painter->drawText(rec, Qt::AlignCenter, text);
// Рисуем левго ребенка
    if(root->left != nullptr)
    {
    painter->setPen(Qt::blue);
    painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() - width()/pow(2, y+2), p.y() + nodeHeight);
    painter->setPen(Qt::black);
    drawNode(painter, root->left, 2*x, y+1);
    }
// Рисуем правого ребенка
    if(root->right != nullptr)
    {
        painter->setPen(Qt::blue);
        painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() + width()/pow(2, y+2), p.y() + nodeHeight);
        painter->setPen(Qt::black);
        drawNode(painter, root->right, 2*x + 1, y+1);
    }
    painter->restore();
    }
