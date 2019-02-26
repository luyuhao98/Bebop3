#include "loginui.h"
#include "ui_loginui.h"
#include "client.h"
#include "signupui.h"
#include "QMessageBox"
loginUi::loginUi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loginUi)
{
    ui->setupUi(this);
}

loginUi::~loginUi()
{
    delete ui;
}

void loginUi::on_signin_clicked()
{

    int status = client::ins().login(ui->in_usrlineEdit->text(),ui->in_pwdlineEdit->text());
    if (status == 0 )
       {
        QMessageBox::information(nullptr,"Hint","Permision Denied");
        }
    else if (status == 1){
          ui->lab_in_usr->setText("User name doesn't exist");
          ui->lab_in_usr->setStyleSheet("color:red");
          ui->lab_in_pwd->setStyleSheet("color:red");

       }
    else if(status ==2 ){
        ui->lab_in_usr->setText("Username");
        ui->lab_in_usr->setStyleSheet("color:green");
        ui->lab_in_pwd->setText("Wrong Password");
        ui->lab_in_pwd->setStyleSheet("color:red");

    }
    else this->accept();

}

void loginUi::on_tosignup_clicked()
{
    signupUi signup;
    this->hide();
    if( signup.exec() == QDialog::Accepted)
        this->accept();
}


void loginUi::closeEvent(QCloseEvent *event)
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
