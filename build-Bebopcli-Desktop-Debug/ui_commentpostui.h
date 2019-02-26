/********************************************************************************
** Form generated from reading UI file 'commentpostui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTPOSTUI_H
#define UI_COMMENTPOSTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_commentpostUi
{
public:
    QGridLayout *gridLayout;
    QPushButton *post;
    QPushButton *clear;
    QSpacerItem *horizontalSpacer;
    QLabel *warning;
    QTextEdit *textEdit;
    QLabel *label;

    void setupUi(QWidget *commentpostUi)
    {
        if (commentpostUi->objectName().isEmpty())
            commentpostUi->setObjectName(QStringLiteral("commentpostUi"));
        commentpostUi->resize(615, 337);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(commentpostUi->sizePolicy().hasHeightForWidth());
        commentpostUi->setSizePolicy(sizePolicy);
        commentpostUi->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        gridLayout = new QGridLayout(commentpostUi);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        post = new QPushButton(commentpostUi);
        post->setObjectName(QStringLiteral("post"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(post->sizePolicy().hasHeightForWidth());
        post->setSizePolicy(sizePolicy1);
        post->setStyleSheet(QStringLiteral("background-color: rgb(138, 226, 52);"));

        gridLayout->addWidget(post, 5, 3, 1, 1);

        clear = new QPushButton(commentpostUi);
        clear->setObjectName(QStringLiteral("clear"));
        sizePolicy1.setHeightForWidth(clear->sizePolicy().hasHeightForWidth());
        clear->setSizePolicy(sizePolicy1);
        clear->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(clear, 5, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(332, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 5, 1, 1, 1);

        warning = new QLabel(commentpostUi);
        warning->setObjectName(QStringLiteral("warning"));
        sizePolicy1.setHeightForWidth(warning->sizePolicy().hasHeightForWidth());
        warning->setSizePolicy(sizePolicy1);
        warning->setStyleSheet(QLatin1String("border-color: rgb(255, 255, 255);\n"
"color: rgb(239, 41, 41);"));

        gridLayout->addWidget(warning, 5, 0, 1, 1);

        textEdit = new QTextEdit(commentpostUi);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setStyleSheet(QLatin1String("background-color: rgb(255, 255, 255);\n"
"font: 14pt \"Ubuntu Mono\";"));
        textEdit->setAcceptRichText(false);

        gridLayout->addWidget(textEdit, 2, 0, 1, 4);

        label = new QLabel(commentpostUi);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("font: 75 italic 20pt \"Samyak Tamil\";\n"
"background-color: rgb(255, 255, 255);"));

        gridLayout->addWidget(label, 0, 0, 1, 4);

        gridLayout->setColumnStretch(0, 5);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 2);
        gridLayout->setColumnMinimumWidth(2, 10);

        retranslateUi(commentpostUi);

        QMetaObject::connectSlotsByName(commentpostUi);
    } // setupUi

    void retranslateUi(QWidget *commentpostUi)
    {
        commentpostUi->setWindowTitle(QApplication::translate("commentpostUi", "Form", Q_NULLPTR));
        post->setText(QApplication::translate("commentpostUi", "Post!", Q_NULLPTR));
        clear->setText(QApplication::translate("commentpostUi", "Clear", Q_NULLPTR));
        warning->setText(QString());
        textEdit->setPlaceholderText(QApplication::translate("commentpostUi", "Write your post!", Q_NULLPTR));
        label->setText(QApplication::translate("commentpostUi", "Comment", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class commentpostUi: public Ui_commentpostUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTPOSTUI_H
