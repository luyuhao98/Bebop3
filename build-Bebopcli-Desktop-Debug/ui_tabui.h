/********************************************************************************
** Form generated from reading UI file 'tabui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABUI_H
#define UI_TABUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tabUi
{
public:
    QGridLayout *tablayout;
    QWidget *topbar;
    QHBoxLayout *horizontalLayout;
    QPushButton *logo;
    QSpacerItem *tophorizontalSpacer;
    QPushButton *pushButton;
    QPushButton *usrbut;

    void setupUi(QWidget *tabUi)
    {
        if (tabUi->objectName().isEmpty())
            tabUi->setObjectName(QStringLiteral("tabUi"));
        tabUi->resize(1145, 781);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabUi->sizePolicy().hasHeightForWidth());
        tabUi->setSizePolicy(sizePolicy);
        tabUi->setMinimumSize(QSize(1000, 750));
        tabUi->setStyleSheet(QStringLiteral(""));
        tablayout = new QGridLayout(tabUi);
        tablayout->setSpacing(0);
        tablayout->setObjectName(QStringLiteral("tablayout"));
        tablayout->setSizeConstraint(QLayout::SetMinimumSize);
        tablayout->setContentsMargins(0, 0, 0, 0);
        topbar = new QWidget(tabUi);
        topbar->setObjectName(QStringLiteral("topbar"));
        topbar->setMinimumSize(QSize(0, 51));
        topbar->setMaximumSize(QSize(16777215, 51));
        topbar->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        horizontalLayout = new QHBoxLayout(topbar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        logo = new QPushButton(topbar);
        logo->setObjectName(QStringLiteral("logo"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy1);
        logo->setStyleSheet(QStringLiteral("text-align : left;"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/bebopb.png"), QSize(), QIcon::Normal, QIcon::Off);
        logo->setIcon(icon);
        logo->setIconSize(QSize(100, 45));
        logo->setFlat(true);

        horizontalLayout->addWidget(logo);

        tophorizontalSpacer = new QSpacerItem(40, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(tophorizontalSpacer);

        pushButton = new QPushButton(topbar);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QIcon icon1(QIcon::fromTheme(QStringLiteral("refresh")));
        pushButton->setIcon(icon1);
        pushButton->setFlat(true);

        horizontalLayout->addWidget(pushButton);

        usrbut = new QPushButton(topbar);
        usrbut->setObjectName(QStringLiteral("usrbut"));
#ifndef QT_NO_ACCESSIBILITY
        usrbut->setAccessibleDescription(QStringLiteral(""));
#endif // QT_NO_ACCESSIBILITY
        usrbut->setLayoutDirection(Qt::LeftToRight);
        usrbut->setStyleSheet(QLatin1String("color: rgb(255, 255, 255);\n"
"font: 75 14pt \"URW Bookman L\";\n"
"text-align : right;"));
        usrbut->setFlat(true);

        horizontalLayout->addWidget(usrbut);


        tablayout->addWidget(topbar, 0, 0, 1, 1);


        retranslateUi(tabUi);

        QMetaObject::connectSlotsByName(tabUi);
    } // setupUi

    void retranslateUi(QWidget *tabUi)
    {
        tabUi->setWindowTitle(QApplication::translate("tabUi", "Form", Q_NULLPTR));
        logo->setText(QString());
        pushButton->setText(QString());
        usrbut->setText(QApplication::translate("tabUi", "username", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class tabUi: public Ui_tabUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABUI_H
