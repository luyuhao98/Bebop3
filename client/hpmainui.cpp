#include "hpmainui.h"
#include "client.h"
#include "QCheckBox"
#include "QMessageBox"
#include "pagelet.h"
#include "post.h"

hpmainUi::hpmainUi(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    mode = true;
    refreshleft();
    refreshright();
    //initpostbox();
}
void hpmainUi::on_left_list_itemClicked(QListWidgetItem *item)
{
    this->currentboard = item->text();
    refreshrightview();
}
void hpmainUi::refreshleft(){
    client::ins().updatehomepage();
    this->left_label->setText("Boards");
    this->left_list->clear();

    auto it= client::ins().gethomepage()->begin();
    while(it!= client::ins().gethomepage()->end()){
        QListWidgetItem *item = new QListWidgetItem();
        item->setFlags(item->flags() & ~Qt::ItemIsSelectable);//unselectable
        item->setText(it.key());
        this->left_list->addItem(item);
        it++;
    }
}

void hpmainUi::refreshrightview(){
    //right_top
    this->deletepost->hide();
    this->selectpost->setText("Select");
    //rightmain
    //this->right_list->setSelectionMode(QAbstractItemView::ExtendedSelection);
    if(!currentboard.compare("")){//init
        currentboard=client::ins().gethomepage()->begin().key();
    }
    this->right_list->clear();
    auto it = client::ins().gethomepage()->begin();
    while(it!=client::ins().gethomepage()->end()){
        if(!it.key().compare(currentboard)){
            auto pg = it.value().begin();
            while(pg!=it.value().end()){
                QListWidgetItem *item = new QListWidgetItem();
                item->setFlags(item->flags() & ~Qt::ItemIsSelectable);//unselectable
                item->setText(pg->title);
                this->right_list->addItem(item);
                //this->right_list->setItemWidget(item,pg->title);
                //this->right_list->addItem(pg->title);
                pg++;
            }
            break;
        }
        it++;
    }
}
void hpmainUi::refreshrightselect(){
    //right_top
    this->deletepost->show();
    this->selectpost->setText("Cancel");
    //right main

    //this->right_list->setSelectionMode(QAbstractItemView::ExtendedSelection);
    if(!currentboard.compare("")){//init
        currentboard=client::ins().gethomepage()->begin().key();
    }
    this->right_list->clear();
    this->boxes.clear();

    auto it = client::ins().gethomepage()->begin();
    while(it!=client::ins().gethomepage()->end()){
        if(!it.key().compare(currentboard)){
            auto pg = it.value().begin();
            while(pg!=it.value().end()){
                auto cpg =new QCheckBox;
                cpg->setText(pg->title);
                cpg->setCheckState(Qt::Unchecked);

                boxes.push_back(cpg);
                QListWidgetItem *item = new QListWidgetItem();
                item->setFlags(item->flags() & ~Qt::ItemIsSelectable);//unselectable

                this->right_list->addItem(item);
                this->right_list->setItemWidget(item,cpg);
                pg++;
            }
            break;
        }
        it++;
    }

}

void hpmainUi::refreshright(){
    if(this->mode)
        refreshrightview();
    else refreshrightselect();
}
void hpmainUi::on_right_list_itemClicked(QListWidgetItem *item)
{
    int i = this->right_list->row(item);
    if(this->mode){
         pagelet pt = client::ins().gethomepage()->value(this->currentboard)[i];
         QString title = client::ins().gethomepage()->value(this->currentboard)[i].title;
         emit postpage(pt,title);
    }
    else{
        this->boxes[i]->setCheckState(this->boxes[i]->checkState()==Qt::Unchecked?Qt::Checked:Qt::Unchecked);
    }
}

void hpmainUi::on_selectpost_clicked()
{
    this->mode = !this->mode;
    refreshright();
}

void hpmainUi::on_deletepost_clicked()
{
    bool noall=0;
    bool yesall = 0;
    QMessageBox::StandardButton reply =QMessageBox::Yes;

    auto it = boxes.begin();
    while(it!= boxes.end()){
        if((*it)->checkState()==Qt::Checked){
            if(!yesall&&!noall){
                reply = QMessageBox::question(this, "Hint", "Delete Post <<"+(*it)->text()+">> ?",
                                              QMessageBox::Yes|QMessageBox::YesAll|QMessageBox::No|QMessageBox::NoAll);

                if (reply == QMessageBox::YesAll){
                    yesall =1;
                    reply =QMessageBox::Yes;
                }
                else if(reply == QMessageBox::NoAll){
                    noall = 1;
                    reply = QMessageBox::No;
                }
                else{
                    ;//nothing changed
                }
            }

            if (reply == QMessageBox::Yes) {
                switch (client::ins().deletepage(client::ins().gethomepage()->value(this->currentboard).at(it-boxes.begin()).pagelet_id)) {
                case 1:
                    QMessageBox::information(NULL,"Hint","Delete Post <<"+(*it)->text()+">> Successfully!");
                    break;
                case 2:
                    QMessageBox::information(NULL,"Hint","Fail to delete Post <<"+(*it)->text()+">>\n More than one posts exists");
                    break;
                default:
                    QMessageBox::information(NULL,"Hint","Fail to delete Post <<"+(*it)->text()+">> \n Permissions denied");

                }
            }

        }
        it++;
    }
    client::ins().updatehomepage();
    this->mode = true;
    refreshright();
}

void hpmainUi:: initpostbox(){
    this->postbox = new QDialog(this);
    this->postbox->resize(QSize(600,400));
    this->postsec = new commentpostUi(this);
    QVBoxLayout * postlayout = new QVBoxLayout();
    postlayout->setContentsMargins(9,9,9,9);
    this->postbox->setLayout(postlayout);



    this->posttitle = new QLabel(this);
    this->posttitle->setText("Title:");
    this->posttitle->setStyleSheet("font: 75 italic 20pt \"Samyak Tamil\";");
    postlayout->addWidget(this->posttitle);

    this->postline = new QLineEdit(this);
    this->postline->setClearButtonEnabled(true);
    this->postline->setStyleSheet("background-color:rgb(255,255,255);font: 16pt \"Ubuntu\";");
    postlayout->addWidget(postline);


    this->postwarning = new QLabel(this);
    this->postwarning->setText("Length: 1~64");
    this->postwarning->setStyleSheet("border-color: rgb(255, 255, 255);color: rgb(239, 41, 41);");
    this->postwarning->hide();
    postlayout->addWidget(this->postwarning);


    this->postsec->geteditor()->setPlaceholderText("More detailed description...");
    this->postsec->geteditor()->setStyleSheet("background-color:rgb(255,255,255);;font: 14pt \"Ubuntu Mono\";");

    postlayout->addWidget(this->postsec);

    connect(this->postsec,SIGNAL(submit(QString)),this,SLOT(addpost(QString)));

}

void hpmainUi::addpost(QString content){

    pagelet pgl;
    pgl.title=this->postline->text();
    pgl.board_id=this->currentboard;
    post po;
    po.content=content;

    int flag =client::ins().createpage(pgl,po);
    if(flag ==0){
        QMessageBox::information(NULL,"Hint","Permission Denied");
    }
    else if(flag ==1){
        this->postwarning->show();
    }
    else if(flag ==2){
        this->postsec->setwarning();
    }
    else {
        QMessageBox::information(NULL,"Hint","Success!");
        client::ins().updatehomepage();
        this->postbox->accept();
        this->postline->clear();
        refreshright();
    }

}

void hpmainUi::on_postbut_clicked()
{
    initpostbox();
    this->postbox->exec();
}
void hpmainUi::refreshslot(){
    refreshleft();
    refreshright();
}

