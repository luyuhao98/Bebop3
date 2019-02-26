/********************************************************************************
** Form generated from reading UI file 'loginui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINUI_H
#define UI_LOGINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_loginUi
{
public:
    QLabel *logo;
    QLineEdit *in_pwdlineEdit;
    QPushButton *signin;
    QLabel *lab_in_newto;
    QLabel *lab_in_pwd;
    QPushButton *tosignup;
    QLabel *lab_in_usr;
    QLineEdit *in_usrlineEdit;

    void setupUi(QDialog *loginUi)
    {
        if (loginUi->objectName().isEmpty())
            loginUi->setObjectName(QStringLiteral("loginUi"));
        loginUi->resize(340, 480);
        loginUi->setMinimumSize(QSize(340, 480));
        loginUi->setMaximumSize(QSize(340, 480));
        logo = new QLabel(loginUi);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(52, 30, 241, 121));
        logo->setStyleSheet(QStringLiteral("image: url(:/Bebopw.png);"));
        in_pwdlineEdit = new QLineEdit(loginUi);
        in_pwdlineEdit->setObjectName(QStringLiteral("in_pwdlineEdit"));
        in_pwdlineEdit->setGeometry(QRect(52, 280, 251, 31));
        in_pwdlineEdit->setFocusPolicy(Qt::StrongFocus);
        in_pwdlineEdit->setAutoFillBackground(false);
        in_pwdlineEdit->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(252, 253, 149);\n"
""));
        in_pwdlineEdit->setEchoMode(QLineEdit::Password);
        in_pwdlineEdit->setClearButtonEnabled(true);
        signin = new QPushButton(loginUi);
        signin->setObjectName(QStringLiteral("signin"));
        signin->setGeometry(QRect(52, 350, 251, 31));
        QFont font;
        font.setFamily(QStringLiteral("TakaoPGothic"));
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        signin->setFont(font);
        signin->setStyleSheet(QLatin1String("color: rgb(243, 243, 243);\n"
"background-color: qradialgradient(spread:pad, cx:0.479, cy:0.5, radius:2, fx:0.479, fy:0.5, stop:0.195876 rgba(0, 150, 29, 255), stop:1 rgba(255, 255, 255, 255));"));
        lab_in_newto = new QLabel(loginUi);
        lab_in_newto->setObjectName(QStringLiteral("lab_in_newto"));
        lab_in_newto->setGeometry(QRect(56, 410, 111, 20));
        lab_in_pwd = new QLabel(loginUi);
        lab_in_pwd->setObjectName(QStringLiteral("lab_in_pwd"));
        lab_in_pwd->setGeometry(QRect(40, 240, 261, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("Ubuntu Condensed"));
        font1.setPointSize(14);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setWeight(9);
        lab_in_pwd->setFont(font1);
        lab_in_pwd->setStyleSheet(QStringLiteral("font: 75 italic 14pt \"Ubuntu Condensed\";"));
        tosignup = new QPushButton(loginUi);
        tosignup->setObjectName(QStringLiteral("tosignup"));
        tosignup->setGeometry(QRect(165, 410, 131, 21));
        tosignup->setFocusPolicy(Qt::StrongFocus);
        tosignup->setStyleSheet(QStringLiteral("color: rgb(32, 74, 135);"));
        tosignup->setFlat(true);
        lab_in_usr = new QLabel(loginUi);
        lab_in_usr->setObjectName(QStringLiteral("lab_in_usr"));
        lab_in_usr->setGeometry(QRect(38, 176, 261, 31));
        lab_in_usr->setFont(font1);
        lab_in_usr->setStyleSheet(QStringLiteral("font: 75 italic 14pt \"Ubuntu Condensed\";"));
        in_usrlineEdit = new QLineEdit(loginUi);
        in_usrlineEdit->setObjectName(QStringLiteral("in_usrlineEdit"));
        in_usrlineEdit->setGeometry(QRect(52, 210, 251, 31));
        in_usrlineEdit->setFocusPolicy(Qt::StrongFocus);
        in_usrlineEdit->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(252, 253, 149);\n"
"alternate-background-color: rgb(255, 255, 255);"));
        in_usrlineEdit->setClearButtonEnabled(true);

        retranslateUi(loginUi);

        QMetaObject::connectSlotsByName(loginUi);
    } // setupUi

    void retranslateUi(QDialog *loginUi)
    {
        loginUi->setWindowTitle(QString());
        logo->setText(QString());
        in_pwdlineEdit->setText(QApplication::translate("loginUi", "123456", Q_NULLPTR));
        in_pwdlineEdit->setPlaceholderText(QString());
        signin->setText(QApplication::translate("loginUi", "Sign in", Q_NULLPTR));
        lab_in_newto->setText(QApplication::translate("loginUi", "New to Bebop?", Q_NULLPTR));
        lab_in_pwd->setText(QApplication::translate("loginUi", "Password", Q_NULLPTR));
        tosignup->setText(QApplication::translate("loginUi", "Create an account", Q_NULLPTR));
        lab_in_usr->setText(QApplication::translate("loginUi", "Username", Q_NULLPTR));
        in_usrlineEdit->setText(QApplication::translate("loginUi", "root", Q_NULLPTR));
        in_usrlineEdit->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class loginUi: public Ui_loginUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINUI_H
