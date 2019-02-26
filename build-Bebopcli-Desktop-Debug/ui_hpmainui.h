/********************************************************************************
** Form generated from reading UI file 'hpmainui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPMAINUI_H
#define UI_HPMAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hpmainUi
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *leftsec;
    QVBoxLayout *verticalLayout;
    QLabel *left_label;
    QListWidget *left_list;
    QWidget *rightsec;
    QVBoxLayout *verticalLayout_2;
    QWidget *right_top;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *deletepost;
    QPushButton *selectpost;
    QPushButton *postbut;
    QListWidget *right_list;

    void setupUi(QWidget *hpmainUi)
    {
        if (hpmainUi->objectName().isEmpty())
            hpmainUi->setObjectName(QStringLiteral("hpmainUi"));
        hpmainUi->resize(981, 649);
        horizontalLayout = new QHBoxLayout(hpmainUi);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        leftsec = new QWidget(hpmainUi);
        leftsec->setObjectName(QStringLiteral("leftsec"));
        leftsec->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout = new QVBoxLayout(leftsec);
        verticalLayout->setSpacing(9);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        left_label = new QLabel(leftsec);
        left_label->setObjectName(QStringLiteral("left_label"));
        left_label->setStyleSheet(QStringLiteral("font: 75 20pt \"URW Bookman L\";"));

        verticalLayout->addWidget(left_label);

        left_list = new QListWidget(leftsec);
        new QListWidgetItem(left_list);
        new QListWidgetItem(left_list);
        new QListWidgetItem(left_list);
        left_list->setObjectName(QStringLiteral("left_list"));
        left_list->setStyleSheet(QLatin1String("font: 57 16pt \"Ubuntu\";\n"
"color: rgb(0, 0, 0);"));
        left_list->setAutoScrollMargin(16);
        left_list->setResizeMode(QListView::Adjust);
        left_list->setSpacing(15);

        verticalLayout->addWidget(left_list);


        horizontalLayout->addWidget(leftsec);

        rightsec = new QWidget(hpmainUi);
        rightsec->setObjectName(QStringLiteral("rightsec"));
        rightsec->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        verticalLayout_2 = new QVBoxLayout(rightsec);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        right_top = new QWidget(rightsec);
        right_top->setObjectName(QStringLiteral("right_top"));
        horizontalLayout_2 = new QHBoxLayout(right_top);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        deletepost = new QPushButton(right_top);
        deletepost->setObjectName(QStringLiteral("deletepost"));
        deletepost->setStyleSheet(QLatin1String("color: rgb(238, 238, 236);\n"
"background-color: rgb(239, 41, 41);"));

        horizontalLayout_2->addWidget(deletepost);

        selectpost = new QPushButton(right_top);
        selectpost->setObjectName(QStringLiteral("selectpost"));

        horizontalLayout_2->addWidget(selectpost);

        postbut = new QPushButton(right_top);
        postbut->setObjectName(QStringLiteral("postbut"));

        horizontalLayout_2->addWidget(postbut);


        verticalLayout_2->addWidget(right_top);

        right_list = new QListWidget(rightsec);
        right_list->setObjectName(QStringLiteral("right_list"));
        right_list->setStyleSheet(QLatin1String("font: 75 oblique 16pt \"Waree\";\n"
"\n"
""));
        right_list->setSpacing(14);
        right_list->setSelectionRectVisible(false);

        verticalLayout_2->addWidget(right_list);


        horizontalLayout->addWidget(rightsec);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 6);

        retranslateUi(hpmainUi);

        QMetaObject::connectSlotsByName(hpmainUi);
    } // setupUi

    void retranslateUi(QWidget *hpmainUi)
    {
        hpmainUi->setWindowTitle(QApplication::translate("hpmainUi", "Form", Q_NULLPTR));
        left_label->setText(QApplication::translate("hpmainUi", "Boards", Q_NULLPTR));

        const bool __sortingEnabled = left_list->isSortingEnabled();
        left_list->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = left_list->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("hpmainUi", "a1", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = left_list->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("hpmainUi", "b2", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem2 = left_list->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("hpmainUi", "c3", Q_NULLPTR));
        left_list->setSortingEnabled(__sortingEnabled);

        deletepost->setText(QApplication::translate("hpmainUi", "Delete", Q_NULLPTR));
        selectpost->setText(QApplication::translate("hpmainUi", "Select", Q_NULLPTR));
        postbut->setText(QApplication::translate("hpmainUi", "Post", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class hpmainUi: public Ui_hpmainUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPMAINUI_H
