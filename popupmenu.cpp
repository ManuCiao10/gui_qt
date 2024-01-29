#include "popupmenu.h"

#include <QPushButton>

PopupMenu::PopupMenu(QPushButton* button, QWidget* parent) : QMenu(parent), b(button)
{
    //print the value
     // qDebug() << "button name is " << button->text();

//    connect(&action01, &QAction::triggered, this, [&action01,=]() {getAction(action01); });
//    connect(&action02, &QAction::triggered, this, [&action02,=]() {getAction(action02); });


}


void PopupMenu::showEvent(QShowEvent* event)
{
    QPoint p = this->pos();
    QRect geo = b->geometry();
    this->move(p.x()+geo.width()-this->geometry().width(), p.y());

    //read the action selected value
    // qDebug() << "action selected is " << this->actions().at(0)->text();

    QMenu::showEvent(event);

}
