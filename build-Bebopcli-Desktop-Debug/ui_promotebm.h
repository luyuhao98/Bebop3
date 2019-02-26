/********************************************************************************
** Form generated from reading UI file 'promotebm.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROMOTEBM_H
#define UI_PROMOTEBM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_promotebm
{
public:
    QGridLayout *gridLayout;
    QLabel *usr;
    QComboBox *combo;
    QLineEdit *lineEdit;
    QPushButton *submit;

    void setupUi(QDialog *promotebm)
    {
        if (promotebm->objectName().isEmpty())
            promotebm->setObjectName(QStringLiteral("promotebm"));
        promotebm->resize(446, 268);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(promotebm->sizePolicy().hasHeightForWidth());
        promotebm->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(promotebm);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        usr = new QLabel(promotebm);
        usr->setObjectName(QStringLiteral("usr"));

        gridLayout->addWidget(usr, 0, 0, 1, 1);

        combo = new QComboBox(promotebm);
        combo->setObjectName(QStringLiteral("combo"));

        gridLayout->addWidget(combo, 0, 1, 1, 1);

        lineEdit = new QLineEdit(promotebm);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 2);

        submit = new QPushButton(promotebm);
        submit->setObjectName(QStringLiteral("submit"));

        gridLayout->addWidget(submit, 2, 0, 1, 2);


        retranslateUi(promotebm);

        QMetaObject::connectSlotsByName(promotebm);
    } // setupUi

    void retranslateUi(QDialog *promotebm)
    {
        promotebm->setWindowTitle(QApplication::translate("promotebm", "Dialog", Q_NULLPTR));
        usr->setText(QApplication::translate("promotebm", "TextLabel", Q_NULLPTR));
        submit->setText(QApplication::translate("promotebm", "submit", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class promotebm: public Ui_promotebm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROMOTEBM_H
