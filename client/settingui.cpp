#include "settingui.h"
#include "client.h"
#include "QMessageBox"
settingUi::settingUi(QWidget *parent) :
    QDialog(parent)
{
    auto u = client::ins().getinfo();
    setupUi(this);
    this->birthdaybox->setDate(u->age);
    this->Genderbox->setCurrentIndex(u->gender);
}

void settingUi::on_pushButton_clicked()
{
    if (this->newpwdline->text().compare(this->reppwdline->text()))
    {
        this->reppwd->setStyleSheet("color : red");
        return ;
    }
    else {
        this->reppwd->setStyleSheet("color:black");
    }

    auto oldpwd = this->oldpwdline->text();
    auto newpwd = this->newpwdline->text();
    int flag = client::ins().changepw(oldpwd,newpwd);
    if (flag == 0){
        QMessageBox::information(nullptr,"Warning","Permission Denied!");
    }
    else if(flag == 1 ){
        this->oldpwd->setText("Incorrect old password!");
        this->oldpwd->setStyleSheet("color:red");
    }
    else if(flag == 2){
        this->oldpwd->setText("Old password");
        this->oldpwd->setStyleSheet("color:green");
        this->newpwd->setText("Invalid password format");
        this->newpwd->setStyleSheet("color:red");
    }
    else{

        this->oldpwdline->clear();
        this->newpwdline->clear();
        this->reppwdline->clear();

        this->oldpwd->setText("Old password");
        this->oldpwd->setStyleSheet("color:black");
        this->newpwd->setText("New password");
        this->newpwd->setStyleSheet("color:black");
        this->newpwd->setStyleSheet("color:black");
        this->reppwd->setStyleSheet("color:black");

        QMessageBox::information(nullptr,"Hint","Succeed!");
    }
}
void settingUi::closeEvent(QCloseEvent *event){
    auto age = this->birthdaybox->date();
    auto gender = this->Genderbox->currentIndex();
    client::ins().changeag(age,gender);
    this->accept();
}
