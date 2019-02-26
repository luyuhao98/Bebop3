#include "commentpostui.h"

commentpostUi::commentpostUi(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->warning->hide();
}

void commentpostUi::on_clear_clicked()
{
    this->textEdit->clear();
}

void commentpostUi::on_post_clicked()
{
    emit submit(this->textEdit->toPlainText());
    //this->textEdit->clear();
}
void commentpostUi:: setwarning(){
    this->warning->show();
    this->warning->setText("Length: 1~2000");
    this->warning->setStyleSheet("border-color: rgb(255, 255, 255);color: rgb(239, 41, 41);");
}
QTextEdit * commentpostUi:: geteditor(){
    return this->textEdit;
}
