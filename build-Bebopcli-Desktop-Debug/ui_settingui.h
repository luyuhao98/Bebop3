/********************************************************************************
** Form generated from reading UI file 'settingui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGUI_H
#define UI_SETTINGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingUi
{
public:
    QGridLayout *gridLayout;
    QToolBox *toolBox;
    QWidget *changepassword;
    QFormLayout *formLayout;
    QLabel *oldpwd;
    QLineEdit *oldpwdline;
    QLabel *newpwd;
    QLineEdit *newpwdline;
    QLabel *reppwd;
    QLineEdit *reppwdline;
    QPushButton *pushButton;
    QWidget *changeprofile;
    QGridLayout *gridLayout_2;
    QComboBox *Genderbox;
    QLabel *Gender;
    QDateEdit *birthdaybox;
    QLabel *birthday;

    void setupUi(QDialog *settingUi)
    {
        if (settingUi->objectName().isEmpty())
            settingUi->setObjectName(QStringLiteral("settingUi"));
        settingUi->resize(433, 337);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(settingUi->sizePolicy().hasHeightForWidth());
        settingUi->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(settingUi);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        toolBox = new QToolBox(settingUi);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        changepassword = new QWidget();
        changepassword->setObjectName(QStringLiteral("changepassword"));
        changepassword->setGeometry(QRect(0, 0, 415, 257));
        formLayout = new QFormLayout(changepassword);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(10);
        formLayout->setVerticalSpacing(10);
        formLayout->setContentsMargins(9, 18, -1, -1);
        oldpwd = new QLabel(changepassword);
        oldpwd->setObjectName(QStringLiteral("oldpwd"));
        oldpwd->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        formLayout->setWidget(0, QFormLayout::LabelRole, oldpwd);

        oldpwdline = new QLineEdit(changepassword);
        oldpwdline->setObjectName(QStringLiteral("oldpwdline"));
        oldpwdline->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::SpanningRole, oldpwdline);

        newpwd = new QLabel(changepassword);
        newpwd->setObjectName(QStringLiteral("newpwd"));
        newpwd->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        formLayout->setWidget(2, QFormLayout::SpanningRole, newpwd);

        newpwdline = new QLineEdit(changepassword);
        newpwdline->setObjectName(QStringLiteral("newpwdline"));
        newpwdline->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(3, QFormLayout::SpanningRole, newpwdline);

        reppwd = new QLabel(changepassword);
        reppwd->setObjectName(QStringLiteral("reppwd"));
        reppwd->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        formLayout->setWidget(4, QFormLayout::LabelRole, reppwd);

        reppwdline = new QLineEdit(changepassword);
        reppwdline->setObjectName(QStringLiteral("reppwdline"));
        reppwdline->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(5, QFormLayout::SpanningRole, reppwdline);

        pushButton = new QPushButton(changepassword);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        formLayout->setWidget(6, QFormLayout::FieldRole, pushButton);

        toolBox->addItem(changepassword, QStringLiteral("Change Password"));
        changeprofile = new QWidget();
        changeprofile->setObjectName(QStringLiteral("changeprofile"));
        changeprofile->setGeometry(QRect(0, 0, 415, 257));
        gridLayout_2 = new QGridLayout(changeprofile);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        Genderbox = new QComboBox(changeprofile);
        Genderbox->setObjectName(QStringLiteral("Genderbox"));

        gridLayout_2->addWidget(Genderbox, 1, 1, 1, 1);

        Gender = new QLabel(changeprofile);
        Gender->setObjectName(QStringLiteral("Gender"));
        Gender->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        gridLayout_2->addWidget(Gender, 1, 0, 1, 1);

        birthdaybox = new QDateEdit(changeprofile);
        birthdaybox->setObjectName(QStringLiteral("birthdaybox"));

        gridLayout_2->addWidget(birthdaybox, 0, 1, 1, 1);

        birthday = new QLabel(changeprofile);
        birthday->setObjectName(QStringLiteral("birthday"));
        birthday->setLayoutDirection(Qt::LeftToRight);
        birthday->setStyleSheet(QStringLiteral("font: 57 12pt \"Ubuntu\";"));

        gridLayout_2->addWidget(birthday, 0, 0, 1, 1);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 2);
        toolBox->addItem(changeprofile, QStringLiteral("Change Profile"));

        gridLayout->addWidget(toolBox, 0, 0, 1, 1);


        retranslateUi(settingUi);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(settingUi);
    } // setupUi

    void retranslateUi(QDialog *settingUi)
    {
        settingUi->setWindowTitle(QApplication::translate("settingUi", "Dialog", Q_NULLPTR));
        oldpwd->setText(QApplication::translate("settingUi", "Old password", Q_NULLPTR));
        newpwd->setText(QApplication::translate("settingUi", "New password", Q_NULLPTR));
        reppwd->setText(QApplication::translate("settingUi", "Repeat your new password", Q_NULLPTR));
        pushButton->setText(QApplication::translate("settingUi", "Submit", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(changepassword), QApplication::translate("settingUi", "Change Password", Q_NULLPTR));
        Genderbox->clear();
        Genderbox->insertItems(0, QStringList()
         << QApplication::translate("settingUi", "Female", Q_NULLPTR)
         << QApplication::translate("settingUi", "Male", Q_NULLPTR)
         << QApplication::translate("settingUi", "Others", Q_NULLPTR)
        );
        Gender->setText(QApplication::translate("settingUi", "Gender", Q_NULLPTR));
        birthday->setText(QApplication::translate("settingUi", "Birthday", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(changeprofile), QApplication::translate("settingUi", "Change Profile", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class settingUi: public Ui_settingUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGUI_H
