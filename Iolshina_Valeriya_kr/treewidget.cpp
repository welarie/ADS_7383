#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include<QRegExpValidator>
#include "treewidget.h"
#include <iostream>

TreeWidget::TreeWidget(QWidget *parent) : QWidget(parent)
{
view_ = new TreeView(this);
view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
// "Введите искомый элемент: "
QLabel *label = new QLabel("Введите искомый элемент: ");
// Окошко для вводимых значений
lineEdit_ = new QLineEdit();
lineEdit_->setValidator( new QIntValidator( -2147483648, 2147483647 ) );
// Кнопки
button_ins = new QPushButton( "Найти или добавить" );
button_del = new QPushButton("Удалить");
step = new QLabel("Начните строить дерево");
// Горизонтальные виджеты (1)
QHBoxLayout *layout = new QHBoxLayout;
layout->addWidget(label);
layout->addWidget(lineEdit_);
layout->addWidget(button_ins);
layout->addWidget(button_del);
// Горизонтальные виджеты (2)
QHBoxLayout *infLayout=new QHBoxLayout;
infLayout->addWidget(step);
// Выравниваем виджеты
QVBoxLayout *mainLayout = new QVBoxLayout;
mainLayout->addLayout(layout);
mainLayout->addLayout(infLayout);
mainLayout->addWidget(view_);
setLayout(mainLayout);
connect(button_ins, &QPushButton::clicked, this, &TreeWidget::insert);
connect(button_del, &QPushButton::clicked, this, &TreeWidget::del );
}

void TreeWidget::del()
{
//Считываем число из строчки
int k = lineEdit_->text().toInt();
view_->Push_key(k);
//Если дерево пусто - игнорируем запрос на удаление
if (view_->tree == NULL)
{
    step->setText(QString::asprintf("Дерево пусто"));
    return;
}
if (view_->tree->find(view_->tree, k))
{
    int gl = view_->tree->key;
    if((view_->tree->delete_el((view_->tree), k, gl))!=NULL)
    step->setText(QString::asprintf("Элемент удалён"));
}
else
    step->setText(QString::asprintf("Элемент отсутствует"));
update();
}

void TreeWidget::insert()
{
int a = lineEdit_->text().toInt();
view_->Push_key(a);
if (view_->tree == NULL)
{
    step->setText(QString::asprintf("Постройка дерева начата"));
    view_->tree = new BST(a);
    view_->Push_flag(false);
}
else if (view_->tree->find_add(view_->tree, a))
{
    step->setText(QString::asprintf("Элемент уже есть"));
    view_->Push_flag(true);
}
else
{
    step->setText(QString::asprintf("Элемент добавлен"));
    view_->Push_flag(false);
}
update();
}
