#include "fakedialog.h"
#include "server.h"
fakedialog::fakedialog(QWidget *parent) :
    QDialog(parent)
{
    server::ins();
    setupUi(this);
    this->setWindowTitle("Console");
    this->console->clear();
    connect(&server::ins(),SIGNAL(print(QString)),this,SLOT(print(QString)));
    connect(&server::ins(),SIGNAL(connum(int)),this,SLOT(connum(int)));

}
void fakedialog::on_buttonBox_accepted()
{
    this->accept();
}
void fakedialog::print(QString output){
    this->console->append(output+"\n");
}
void fakedialog::connum(int num){
    this->con_num->setText("Connection Number: "+QString::number(num));
}
