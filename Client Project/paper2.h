#ifndef PAPER2_H
#define PAPER2_H

#include <QWidget>
#include <qlabel.h>
#include <Qdir>

QT_BEGIN_NAMESPACE
namespace Ui { class Paper2;}
QT_END_NAMESPACE



class Paper2;


class MyLabel: public QLabel
{
private:
    Paper2* papa;   // клас реімплементованого вікна, на якому буде розміщений цей об'єкт - *this
    short casel;    //номер ініціалізування
public:
    MyLabel(Paper2 *parent, short casel, const QString& text="");//констр. для ініціалізації номером лейбла
    void mouseReleaseEvent(QMouseEvent *ev);        // слот для опрацювання вибору юзера
};






class Paper2 : public QWidget
{
    //Q_OBJECT //макрос для декларування деяких сигналів, слотів які використовують сервіс служби QT MOS (meta object system)

public:
    Paper2( QWidget *parent=0);
    ~Paper2();


    Ui::Paper2 *ui;     //вказівник на клас форми, в якому розміщений код параметрів об'єктів (об'єкти, розміри, координати)
    static int shared;
    QLabel lbl1;

private:




};



#endif // PAPER2_H
