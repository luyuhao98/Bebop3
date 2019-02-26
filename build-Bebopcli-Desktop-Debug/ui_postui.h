/********************************************************************************
** Form generated from reading UI file 'postui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POSTUI_H
#define UI_POSTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_postUi
{
public:
    QGridLayout *gridLayout;
    QLabel *content;
    QLabel *status;
    QPushButton *downvotebut;
    QPushButton *commentbut;
    QPushButton *upvotebut;
    QLabel *usr;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *postUi)
    {
        if (postUi->objectName().isEmpty())
            postUi->setObjectName(QStringLiteral("postUi"));
        postUi->resize(733, 217);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(postUi->sizePolicy().hasHeightForWidth());
        postUi->setSizePolicy(sizePolicy);
        postUi->setStyleSheet(QStringLiteral("background-color: rgb(211, 215, 207);"));
        gridLayout = new QGridLayout(postUi);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(6, 6, 6, 2);
        content = new QLabel(postUi);
        content->setObjectName(QStringLiteral("content"));
        content->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(content, 0, 1, 1, 5);

        status = new QLabel(postUi);
        status->setObjectName(QStringLiteral("status"));
        status->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(status, 1, 1, 1, 5);

        downvotebut = new QPushButton(postUi);
        downvotebut->setObjectName(QStringLiteral("downvotebut"));
        downvotebut->setStyleSheet(QStringLiteral("background-color: rgb(239, 41, 41);"));

        gridLayout->addWidget(downvotebut, 2, 4, 1, 1);

        commentbut = new QPushButton(postUi);
        commentbut->setObjectName(QStringLiteral("commentbut"));

        gridLayout->addWidget(commentbut, 2, 5, 1, 1);

        upvotebut = new QPushButton(postUi);
        upvotebut->setObjectName(QStringLiteral("upvotebut"));
        upvotebut->setStyleSheet(QStringLiteral("background-color: rgb(115, 210, 22);"));

        gridLayout->addWidget(upvotebut, 2, 3, 1, 1);

        usr = new QLabel(postUi);
        usr->setObjectName(QStringLiteral("usr"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(usr->sizePolicy().hasHeightForWidth());
        usr->setSizePolicy(sizePolicy1);
        usr->setMinimumSize(QSize(100, 0));
        usr->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(usr, 0, 0, 2, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 0, 1, 3);

        gridLayout->setRowStretch(0, 1);

        retranslateUi(postUi);

        QMetaObject::connectSlotsByName(postUi);
    } // setupUi

    void retranslateUi(QWidget *postUi)
    {
        postUi->setWindowTitle(QApplication::translate("postUi", "Form", Q_NULLPTR));
        content->setText(QApplication::translate("postUi", "content", Q_NULLPTR));
        status->setText(QApplication::translate("postUi", "status", Q_NULLPTR));
        downvotebut->setText(QApplication::translate("postUi", "downvote", Q_NULLPTR));
        commentbut->setText(QApplication::translate("postUi", "comment", Q_NULLPTR));
        upvotebut->setText(QApplication::translate("postUi", "upvote", Q_NULLPTR));
        usr->setText(QApplication::translate("postUi", "usr", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class postUi: public Ui_postUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POSTUI_H
