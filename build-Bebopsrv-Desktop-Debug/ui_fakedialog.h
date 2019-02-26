/********************************************************************************
** Form generated from reading UI file 'fakedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FAKEDIALOG_H
#define UI_FAKEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_fakedialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *con_num;
    QTextBrowser *console;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *fakedialog)
    {
        if (fakedialog->objectName().isEmpty())
            fakedialog->setObjectName(QStringLiteral("fakedialog"));
        fakedialog->resize(518, 408);
        gridLayout = new QGridLayout(fakedialog);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(fakedialog);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QLatin1String("\n"
"font: 75 20pt \"URW Bookman L\";"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        con_num = new QLabel(fakedialog);
        con_num->setObjectName(QStringLiteral("con_num"));
        con_num->setLayoutDirection(Qt::LeftToRight);
        con_num->setStyleSheet(QLatin1String("font: 75 14pt \"Ubuntu Condensed\";\n"
"color: rgb(204, 0, 0);"));
        con_num->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(con_num, 0, 1, 1, 1);

        console = new QTextBrowser(fakedialog);
        console->setObjectName(QStringLiteral("console"));

        gridLayout->addWidget(console, 1, 0, 1, 2);

        buttonBox = new QDialogButtonBox(fakedialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(fakedialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), fakedialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fakedialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(fakedialog);
    } // setupUi

    void retranslateUi(QDialog *fakedialog)
    {
        fakedialog->setWindowTitle(QApplication::translate("fakedialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("fakedialog", "Console", Q_NULLPTR));
        con_num->setText(QApplication::translate("fakedialog", "Connection Number : 0", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fakedialog: public Ui_fakedialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FAKEDIALOG_H
