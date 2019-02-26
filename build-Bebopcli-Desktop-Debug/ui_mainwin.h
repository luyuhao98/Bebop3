/********************************************************************************
** Form generated from reading UI file 'mainwin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mainwin
{
public:
    QVBoxLayout *mainlayout;
    QTabWidget *tabWidget;

    void setupUi(QWidget *Mainwin)
    {
        if (Mainwin->objectName().isEmpty())
            Mainwin->setObjectName(QStringLiteral("Mainwin"));
        Mainwin->resize(1049, 779);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Mainwin->sizePolicy().hasHeightForWidth());
        Mainwin->setSizePolicy(sizePolicy);
        Mainwin->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        mainlayout = new QVBoxLayout(Mainwin);
        mainlayout->setSpacing(6);
        mainlayout->setContentsMargins(11, 11, 11, 11);
        mainlayout->setObjectName(QStringLiteral("mainlayout"));
        mainlayout->setSizeConstraint(QLayout::SetMinimumSize);
        mainlayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(Mainwin);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setContextMenuPolicy(Qt::DefaultContextMenu);
        tabWidget->setStyleSheet(QLatin1String("color: rgb(46, 52, 54);\n"
"background-color: rgb(255, 255, 255);"));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setTabsClosable(false);
        tabWidget->setMovable(false);
        tabWidget->setTabBarAutoHide(false);

        mainlayout->addWidget(tabWidget);


        retranslateUi(Mainwin);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Mainwin);
    } // setupUi

    void retranslateUi(QWidget *Mainwin)
    {
        Mainwin->setWindowTitle(QApplication::translate("Mainwin", "Mainwin", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Mainwin: public Ui_Mainwin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
