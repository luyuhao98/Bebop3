#include "promotebm.h"
#include "client.h"
#include "QMessageBox"
promotebm::promotebm(QString usr,QWidget *parent) :
    QDialog(parent)
{
    setupUi(this);
    QStringList choose;
    choose<<"<New Board>";

    auto tempboards = client::ins().getboards();
    auto it = tempboards.begin();
    while(it != tempboards.end()){
        choose << it->name;
        it++;
    }
  //  this->combo = new QComboBox;
    this->combo->addItems(choose);
    this->usr->setText(usr);
}
void promotebm::refresh(){

}
QComboBox * promotebm ::getcombo(){
    return this->combo;
}

void promotebm::on_submit_clicked()
{
    if(this->newboard){
        emit submit(this->lineEdit->text());
    }
    else{
        emit submit(this->getcombo()->currentText());
    }

    this->accept();
}

void promotebm::on_combo_currentTextChanged(const QString &arg1)
{
    if(!arg1.compare("<New Board>")){
        this->lineEdit->show();
        this->newboard =true;
    }
    else{
        this->lineEdit->hide();
        this->newboard =false;
    }
}
