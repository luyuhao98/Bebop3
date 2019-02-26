/********************************************************************************
** Form generated from reading UI file 'signupui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIGNUPUI_H
#define UI_SIGNUPUI_H

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

class Ui_signupUi
{
public:
    QLabel *lab_up_rpt_pwd;
    QLineEdit *up_pwdlineEdit;
    QPushButton *tosignin;
    QLabel *lab_newto;
    QLabel *logo;
    QPushButton *signup;
    QLineEdit *up_email_lineEdit;
    QLabel *lab_up_pwd;
    QLabel *lab_up_email;
    QLineEdit *up_rpt_pwdlineEdit;
    QLineEdit *up_usrlineEdit;
    QLabel *lab_up_usr;

    void setupUi(QDialog *signupUi)
    {
        if (signupUi->objectName().isEmpty())
            signupUi->setObjectName(QStringLiteral("signupUi"));
        signupUi->resize(420, 680);
        signupUi->setMinimumSize(QSize(420, 680));
        signupUi->setMaximumSize(QSize(420, 680));
        lab_up_rpt_pwd = new QLabel(signupUi);
        lab_up_rpt_pwd->setObjectName(QStringLiteral("lab_up_rpt_pwd"));
        lab_up_rpt_pwd->setGeometry(QRect(13, 438, 391, 41));
        QFont font;
        font.setFamily(QStringLiteral("Ubuntu Condensed"));
        font.setPointSize(14);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(9);
        lab_up_rpt_pwd->setFont(font);
        lab_up_rpt_pwd->setStyleSheet(QStringLiteral("font: 75 italic 14pt \"Ubuntu Condensed\";"));
        up_pwdlineEdit = new QLineEdit(signupUi);
        up_pwdlineEdit->setObjectName(QStringLiteral("up_pwdlineEdit"));
        up_pwdlineEdit->setGeometry(QRect(88, 401, 250, 31));
        up_pwdlineEdit->setFocusPolicy(Qt::StrongFocus);
        up_pwdlineEdit->setAutoFillBackground(false);
        up_pwdlineEdit->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(252, 253, 149);\n"
""));
        up_pwdlineEdit->setEchoMode(QLineEdit::Password);
        up_pwdlineEdit->setClearButtonEnabled(true);
        tosignin = new QPushButton(signupUi);
        tosignin->setObjectName(QStringLiteral("tosignin"));
        tosignin->setGeometry(QRect(234, 544, 61, 21));
        tosignin->setFocusPolicy(Qt::StrongFocus);
        tosignin->setStyleSheet(QStringLiteral("color: rgb(32, 74, 135);"));
        tosignin->setFlat(true);
        lab_newto = new QLabel(signupUi);
        lab_newto->setObjectName(QStringLiteral("lab_newto"));
        lab_newto->setGeometry(QRect(104, 544, 111, 20));
        logo = new QLabel(signupUi);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(85, 32, 241, 121));
        logo->setStyleSheet(QStringLiteral("image: url(:/Bebopw.png);"));
        signup = new QPushButton(signupUi);
        signup->setObjectName(QStringLiteral("signup"));
        signup->setGeometry(QRect(88, 603, 251, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("TakaoPGothic"));
        font1.setPointSize(15);
        font1.setBold(true);
        font1.setWeight(75);
        signup->setFont(font1);
        signup->setStyleSheet(QLatin1String("color: rgb(243, 243, 243);\n"
"background-color: qradialgradient(spread:pad, cx:0.479, cy:0.5, radius:2, fx:0.479, fy:0.5, stop:0.195876 rgba(0, 150, 29, 255), stop:1 rgba(255, 255, 255, 255));"));
        up_email_lineEdit = new QLineEdit(signupUi);
        up_email_lineEdit->setObjectName(QStringLiteral("up_email_lineEdit"));
        up_email_lineEdit->setGeometry(QRect(87, 313, 251, 31));
        up_email_lineEdit->setFocusPolicy(Qt::StrongFocus);
        up_email_lineEdit->setAutoFillBackground(false);
        up_email_lineEdit->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(252, 253, 149);\n"
""));
        up_email_lineEdit->setEchoMode(QLineEdit::Normal);
        up_email_lineEdit->setClearButtonEnabled(true);
        lab_up_pwd = new QLabel(signupUi);
        lab_up_pwd->setObjectName(QStringLiteral("lab_up_pwd"));
        lab_up_pwd->setGeometry(QRect(14, 345, 391, 51));
        lab_up_pwd->setFont(font);
        lab_up_pwd->setStyleSheet(QStringLiteral("font: 75 italic 14pt \"Ubuntu Condensed\";"));
        lab_up_email = new QLabel(signupUi);
        lab_up_email->setObjectName(QStringLiteral("lab_up_email"));
        lab_up_email->setGeometry(QRect(14, 267, 381, 41));
        lab_up_email->setFont(font);
        lab_up_email->setStyleSheet(QStringLiteral("font: 75 italic 14pt \"Ubuntu Condensed\";"));
        up_rpt_pwdlineEdit = new QLineEdit(signupUi);
        up_rpt_pwdlineEdit->setObjectName(QStringLiteral("up_rpt_pwdlineEdit"));
        up_rpt_pwdlineEdit->setGeometry(QRect(87, 486, 251, 31));
        up_rpt_pwdlineEdit->setFocusPolicy(Qt::StrongFocus);
        up_rpt_pwdlineEdit->setAutoFillBackground(false);
        up_rpt_pwdlineEdit->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(252, 253, 149);\n"
""));
        up_rpt_pwdlineEdit->setEchoMode(QLineEdit::Password);
        up_rpt_pwdlineEdit->setClearButtonEnabled(true);
        up_usrlineEdit = new QLineEdit(signupUi);
        up_usrlineEdit->setObjectName(QStringLiteral("up_usrlineEdit"));
        up_usrlineEdit->setGeometry(QRect(87, 223, 251, 31));
        up_usrlineEdit->setFocusPolicy(Qt::StrongFocus);
        up_usrlineEdit->setAcceptDrops(true);
        up_usrlineEdit->setStyleSheet(QLatin1String("border-color: rgb(0, 0, 0);\n"
"background-color: rgb(252, 253, 149);\n"
"alternate-background-color: rgb(255, 255, 255);"));
        up_usrlineEdit->setClearButtonEnabled(true);
        lab_up_usr = new QLabel(signupUi);
        lab_up_usr->setObjectName(QStringLiteral("lab_up_usr"));
        lab_up_usr->setGeometry(QRect(14, 177, 381, 41));
        lab_up_usr->setFont(font);
        lab_up_usr->setStyleSheet(QStringLiteral("font: 75 italic 14pt \"Ubuntu Condensed\";"));

        retranslateUi(signupUi);

        QMetaObject::connectSlotsByName(signupUi);
    } // setupUi

    void retranslateUi(QDialog *signupUi)
    {
        signupUi->setWindowTitle(QApplication::translate("signupUi", "Dialog", Q_NULLPTR));
        lab_up_rpt_pwd->setText(QApplication::translate("signupUi", "           Repeat your password", Q_NULLPTR));
        up_pwdlineEdit->setText(QApplication::translate("signupUi", "123qwe!@#QWE", Q_NULLPTR));
        tosignin->setText(QApplication::translate("signupUi", "Sign in", Q_NULLPTR));
        lab_newto->setText(QApplication::translate("signupUi", "Has an account?", Q_NULLPTR));
        logo->setText(QString());
        signup->setText(QApplication::translate("signupUi", "Sign up for Bebop", Q_NULLPTR));
        up_email_lineEdit->setText(QApplication::translate("signupUi", "249691892@qq.com", Q_NULLPTR));
        lab_up_pwd->setText(QApplication::translate("signupUi", "           Password", Q_NULLPTR));
        lab_up_email->setText(QApplication::translate("signupUi", "           Email", Q_NULLPTR));
        up_rpt_pwdlineEdit->setText(QApplication::translate("signupUi", "123qwe!@#QWE", Q_NULLPTR));
        up_usrlineEdit->setText(QApplication::translate("signupUi", "matrix98", Q_NULLPTR));
        up_usrlineEdit->setPlaceholderText(QString());
        lab_up_usr->setText(QApplication::translate("signupUi", "           Username", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class signupUi: public Ui_signupUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIGNUPUI_H
