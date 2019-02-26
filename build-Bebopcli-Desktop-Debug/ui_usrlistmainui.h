/********************************************************************************
** Form generated from reading UI file 'usrlistmainui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USRLISTMAINUI_H
#define UI_USRLISTMAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_usrlistmainUi
{
public:
    QGridLayout *gridLayout;
    QWidget *usrlist;
    QVBoxLayout *verticalLayout_2;
    QFrame *line;
    QTableWidget *tbWidget;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *levelup;
    QPushButton *deleteuser;

    void setupUi(QWidget *usrlistmainUi)
    {
        if (usrlistmainUi->objectName().isEmpty())
            usrlistmainUi->setObjectName(QStringLiteral("usrlistmainUi"));
        usrlistmainUi->resize(1015, 610);
        gridLayout = new QGridLayout(usrlistmainUi);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        usrlist = new QWidget(usrlistmainUi);
        usrlist->setObjectName(QStringLiteral("usrlist"));
        usrlist->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(usrlist);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(usrlist);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        tbWidget = new QTableWidget(usrlist);
        if (tbWidget->columnCount() < 3)
            tbWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tbWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tbWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tbWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tbWidget->setObjectName(QStringLiteral("tbWidget"));
        tbWidget->setStyleSheet(QStringLiteral(""));
        tbWidget->setShowGrid(true);
        tbWidget->setCornerButtonEnabled(true);
        tbWidget->horizontalHeader()->setCascadingSectionResizes(false);
        tbWidget->horizontalHeader()->setDefaultSectionSize(200);
        tbWidget->horizontalHeader()->setStretchLastSection(true);
        tbWidget->verticalHeader()->setVisible(false);
        tbWidget->verticalHeader()->setDefaultSectionSize(40);
        tbWidget->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_2->addWidget(tbWidget);

        widget = new QWidget(usrlist);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QStringLiteral("background-color: rgb(136, 138, 133);"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        levelup = new QPushButton(widget);
        levelup->setObjectName(QStringLiteral("levelup"));

        horizontalLayout_2->addWidget(levelup);

        deleteuser = new QPushButton(widget);
        deleteuser->setObjectName(QStringLiteral("deleteuser"));

        horizontalLayout_2->addWidget(deleteuser);


        verticalLayout_2->addWidget(widget);

        verticalLayout_2->setStretch(1, 9);

        gridLayout->addWidget(usrlist, 0, 0, 1, 1);


        retranslateUi(usrlistmainUi);

        QMetaObject::connectSlotsByName(usrlistmainUi);
    } // setupUi

    void retranslateUi(QWidget *usrlistmainUi)
    {
        usrlistmainUi->setWindowTitle(QApplication::translate("usrlistmainUi", "Form", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tbWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("usrlistmainUi", "User_id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tbWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("usrlistmainUi", "Right", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tbWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("usrlistmainUi", "Remark", Q_NULLPTR));
        levelup->setText(QApplication::translate("usrlistmainUi", "level up", Q_NULLPTR));
        deleteuser->setText(QApplication::translate("usrlistmainUi", "delete user", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class usrlistmainUi: public Ui_usrlistmainUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USRLISTMAINUI_H
