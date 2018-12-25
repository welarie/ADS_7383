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

void TreeView::Push_key(int a)
{
    key = a;
}

int TreeView::Pop_key()
{
    return key;
}

void TreeView::Push_flag(bool a)
{
    flag = a;
}

bool TreeView::Pop_flag()
{
    return flag;
}

void TreeView::drawNode(QPainter *painter, BST* root, int x, int y)
{
    if(root==nullptr)
        return;
    painter->save();
    int k = Pop_key();
    int root_k = root->key;
    bool f = Pop_flag();

    QPoint p(width() / pow(2, y) * x + width() / pow(2, y+1), nodeHeight * y);

    QRect rec(p.x() - nodeWidth/4, p.y(), nodeWidth/2, nodeHeight/2);

    if (k == root_k)
    {
        if ( f )
            painter->setPen(Qt::green);
        else
            painter->setPen(Qt::red);
    }

    painter->drawRect(rec);

    QFont font = painter->font() ;
    font.setPointSize(10);
    painter->setFont(font);

    std::stringstream str;

    str << root->key;

    QString text = fontMetrics().elidedText( QString::fromLatin1(str.str().c_str()), Qt::ElideLeft, rec.width() );
    painter->drawText(rec, Qt::AlignCenter, text);

    if(root->left != nullptr)
    {
    painter->setPen(Qt::blue);
    painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() - width()/pow(2, y+2), p.y() + nodeHeight);
    painter->setPen(Qt::black);
    drawNode(painter, root->left, 2*x, y+1);
    }

    if(root->right != nullptr)
    {
        painter->setPen(Qt::blue);
        painter->drawLine(p.x(), p.y() + nodeHeight / 2, p.x() + width()/pow(2, y+2), p.y() + nodeHeight);
        painter->setPen(Qt::black);
        drawNode(painter, root->right, 2*x + 1, y+1);
    }
    painter->restore();
    }
