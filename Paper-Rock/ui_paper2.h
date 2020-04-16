/********************************************************************************
** Form generated from reading UI file 'paper2.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAPER2_H
#define UI_PAPER2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Paper2
{
public:
    QLabel *label;
    QFrame *line;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *case2;
    QLabel *case3;
    QLabel *case1;
    QLabel *you;
    QLabel *lblop;
    QLabel *myscore;
    QLabel *opscore;
    QLabel *opcup;
    QLabel *mycup;

    void setupUi(QWidget *Paper2)
    {
        if (Paper2->objectName().isEmpty())
            Paper2->setObjectName(QString::fromUtf8("Paper2"));
        Paper2->resize(296, 446);
        label = new QLabel(Paper2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 150, 171, 16));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        line = new QFrame(Paper2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 130, 311, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(Paper2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 47, 14));
        label_3 = new QLabel(Paper2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(230, 10, 47, 14));
        case2 = new QLabel(Paper2);
        case2->setObjectName(QString::fromUtf8("case2"));
        case2->setGeometry(QRect(200, 200, 81, 121));
        case3 = new QLabel(Paper2);
        case3->setObjectName(QString::fromUtf8("case3"));
        case3->setGeometry(QRect(100, 320, 91, 111));
        case1 = new QLabel(Paper2);
        case1->setObjectName(QString::fromUtf8("case1"));
        case1->setGeometry(QRect(40, 210, 71, 111));
        you = new QLabel(Paper2);
        you->setObjectName(QString::fromUtf8("you"));
        you->setGeometry(QRect(210, 40, 61, 71));
        lblop = new QLabel(Paper2);
        lblop->setObjectName(QString::fromUtf8("lblop"));
        lblop->setGeometry(QRect(10, 40, 61, 71));
        myscore = new QLabel(Paper2);
        myscore->setObjectName(QString::fromUtf8("myscore"));
        myscore->setGeometry(QRect(180, 10, 21, 16));
        QFont font1;
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        myscore->setFont(font1);
        opscore = new QLabel(Paper2);
        opscore->setObjectName(QString::fromUtf8("opscore"));
        opscore->setGeometry(QRect(110, 10, 21, 16));
        opscore->setFont(font1);
        opcup = new QLabel(Paper2);
        opcup->setObjectName(QString::fromUtf8("opcup"));
        opcup->setGeometry(QRect(110, 30, 21, 31));
        mycup = new QLabel(Paper2);
        mycup->setObjectName(QString::fromUtf8("mycup"));
        mycup->setGeometry(QRect(180, 30, 21, 31));

        retranslateUi(Paper2);

        QMetaObject::connectSlotsByName(Paper2);
    } // setupUi

    void retranslateUi(QWidget *Paper2)
    {
        Paper2->setWindowTitle(QCoreApplication::translate("Paper2", "Paper2", nullptr));
        label->setText(QCoreApplication::translate("Paper2", "\320\222\320\270\320\261\320\265\321\200\321\226\321\202\321\214 \321\205\321\226\320\264", nullptr));
        label_2->setText(QCoreApplication::translate("Paper2", "\320\236\320\277\320\276\320\275\320\265\320\275\321\202", nullptr));
        label_3->setText(QCoreApplication::translate("Paper2", " \320\222\320\270", nullptr));
        case2->setText(QCoreApplication::translate("Paper2", "TextLabel", nullptr));
        case3->setText(QCoreApplication::translate("Paper2", "TextLabel", nullptr));
        case1->setText(QCoreApplication::translate("Paper2", "TextLabel", nullptr));
        you->setText(QString());
        lblop->setText(QString());
        myscore->setText(QCoreApplication::translate("Paper2", "0", nullptr));
        opscore->setText(QCoreApplication::translate("Paper2", "0", nullptr));
        opcup->setText(QString());
        mycup->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Paper2: public Ui_Paper2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAPER2_H
