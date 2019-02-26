#include "signupui.h"
#include "ui_signupui.h"
#include "client.h"
#include "loginui.h"
#include "QMessageBox"
signupUi::signupUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupUi)
{
    ui->setupUi(this);
}

signupUi::~signupUi()
{
    delete ui;
}


void signupUi::on_up_usrlineEdit_editingFinished()
{
    ui->lab_up_usr->setWordWrap(true);
    switch(client::ins().signupusrcheck(ui->up_usrlineEdit->text())){
    case 0:
        ui->lab_up_usr->setText("           Username is already taken");
        ui->lab_up_usr->setStyleSheet("color: red");
        break;
    case 1:
        ui->lab_up_usr->setText("           Username");
        ui->lab_up_usr->setStyleSheet("color: green");
        break;
    case 2:
        ui->lab_up_usr->setText("At least 8 characters, including at least one uppercase character, one lowercase character and one number");
        ui->lab_up_usr->setStyleSheet("color: red");
        break;
    }
}

void signupUi::on_up_email_lineEdit_editingFinished()
{
    if(client::ins().signupemailcheck(ui->up_email_lineEdit->text())){
        ui->lab_up_email->setText("           Email");
        ui->lab_up_email->setStyleSheet("color: green");
    } else{
        ui->lab_up_email->setText("           Email is invalid");
        ui->lab_up_email->setStyleSheet("color: red");
    }
}


void signupUi::on_tosignin_clicked()
{
    loginUi *login = new loginUi;
    this->hide();
    if(login->exec()==QDialog::Accepted){
        this->accept();
    }
}

void signupUi::on_up_pwdlineEdit_editingFinished()
{
    ui->lab_up_pwd->setWordWrap(true);
    if(client::ins().signuppwdcheck(ui->up_pwdlineEdit->text())){
        ui->lab_up_pwd->setText("           Password");
        ui->lab_up_pwd->setStyleSheet("color: green");
    } else{
        ui->lab_up_pwd->setText("At least 8 characters,including a number, a uppercase char and a lowercase char");
        ui->lab_up_pwd->setStyleSheet("color: red");
    }
    ui->lab_up_pwd->setWordWrap(true);;
}

void signupUi::on_up_rpt_pwdlineEdit_editingFinished()
{

    if(ui->up_rpt_pwdlineEdit->text().compare(ui->up_pwdlineEdit->text())){
        ui->lab_up_rpt_pwd->setText("           Repeat Error");
        ui->lab_up_rpt_pwd->setStyleSheet("color: red");
    }else{
        ui->lab_up_rpt_pwd->setText("           Repeat Correctly");
        ui->lab_up_rpt_pwd->setStyleSheet("color: green");
    }

}

void signupUi::on_signup_clicked()
{
    bool match=!ui->up_rpt_pwdlineEdit->text().compare(ui->up_pwdlineEdit->text());

    if (match&&client::ins().signup(ui->up_usrlineEdit->text(),ui->up_pwdlineEdit->text(),ui->up_email_lineEdit->text()))
    {
        int token = client::ins().login(ui->up_usrlineEdit->text(),ui->up_pwdlineEdit->text());
        if(token == 3 )
        {
            this->accept();
            return;
        }

    }
    else{
    on_up_usrlineEdit_editingFinished();
    on_up_email_lineEdit_editingFinished();
    on_up_pwdlineEdit_editingFinished();
    on_up_rpt_pwdlineEdit_editingFinished();
    }
}


void signupUi::closeEvent(QCloseEvent *event)
{
    QMessageBox msgBox;
    msgBox.setText("Do you want to visit as a guest?");
    //msgBox.setInformativeText("yes");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    switch(ret)
    {
    case QMessageBox::Yes:
        event->accept();
        if(!client::ins().guestin()){
            QMessageBox::information(NULL,"Hint","Guest request denied!");
            event->ignore();
            break;
        }
        this->accept();
        break;
    case QMessageBox::No:
        event->accept();
        this->close();
        break;
    default:
        event->ignore();
        break;
    }


}
