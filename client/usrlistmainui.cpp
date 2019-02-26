#include "usrlistmainui.h"
#include "client.h"
#include "QMessageBox"
usrlistmainUi::usrlistmainUi(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    refresh();
}


void usrlistmainUi:: refresh(){

    //init table
    this->tbWidget->clear();
    this->tbWidget->setRowCount(0);
    QStringList headers;

    headers<<"User_id"<<"Right"<<"Remark";
    this->tbWidget->setHorizontalHeaderLabels(headers);
    this->tbWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->tbWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    this->tbWidget->setSelectionMode(QAbstractItemView::SingleSelection);

    //fill in data
    this->usr_info_list = client::ins().getuserlist();
    this->boards = client::ins().getboards();

    auto it =this->usr_info_list.begin();
    int row = 0;
    while(it!=this->usr_info_list.end()){
        this->tbWidget->insertRow(this->tbWidget->rowCount());
        QString rightstr;
        QString remarkstr;
        switch (it->right) {

        case 0: rightstr = "Guest";break;
        case 1: rightstr = "Normal";break;
        case 2:
        {       rightstr = "Board Manager";
                remarkstr = "ERROR";
                auto it2 = boards.begin();
                while(it2!=boards.end()){
                    if(!it2->manager_id.compare(it->id)){
                        remarkstr = it2->name;
                        break;
                    }
                    it2++;
                }
                break;
        }
        case 3 : rightstr = "Admin";break;
        }

        QTableWidgetItem *item = new QTableWidgetItem (it->id);
        this->tbWidget->setItem(row,0,item);
        item = new QTableWidgetItem (rightstr);
        this->tbWidget->setItem(row,1,item);
        item = new QTableWidgetItem (remarkstr);
        this->tbWidget->setItem(row,2,item);
        row++;
        it++;
    }
}

void usrlistmainUi::on_deleteuser_clicked()
{
   auto items = this->tbWidget->selectedItems();
   QAbstractItemModel *modessl = this->tbWidget->model();

   int rownum = this->tbWidget->row(items.at(0));
   QModelIndex indextemp = modessl->index(rownum,0);

   QString  usrr = modessl->data(indextemp).toString();

   if(!usrr.compare(client::ins().getinfo()->id)){
        QMessageBox::warning(NULL,"Warning","You can't delete yourself");
        return ;
   }
   client::ins().deleteusr(usrr);
   refresh();
}


void usrlistmainUi::on_levelup_clicked()
{
        auto items = this->tbWidget->selectedItems();
        QAbstractItemModel *modessl = this->tbWidget->model();
        int rownum = this->tbWidget->row(items.at(0));
        QModelIndex indextemp = modessl->index(rownum,0);
        selectedusr= modessl->data(indextemp).toString();
        this->ptb = new promotebm(selectedusr,this);
        connect(this->ptb,SIGNAL(submit(QString)),this,SLOT(cbox_submit(QString)));
        this->ptb->exec();
}

void usrlistmainUi::cbox_submit(QString boardname){

    int flag= client::ins().changebm(boardname,selectedusr);
    if(flag==0){
        QMessageBox::warning(NULL,"Warning","Illegal request!");
    }
    if(flag==1){
        QMessageBox::warning(NULL,"Warning","Invalid new board name");
    }
    else if(flag==2){
        QMessageBox::warning(NULL,"Hint","Succeed");
        refresh();
    }
}
void usrlistmainUi:: refreshslot(){
    refresh();
}
