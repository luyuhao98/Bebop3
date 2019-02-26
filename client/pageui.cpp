#include "pageui.h"
#include "ui_tabui.h"
#include"client.h"
#include "QListWidgetItem"
#include "postui.h"
#include "QMessageBox"

pageUi::pageUi(pagelet pg,QWidget *parent) :tabUi(parent)
{
    this->main = new QListWidget(this);
    this->ui->tablayout->addWidget(this->main);
    connect(this,SIGNAL(refreshsignal()),this,SLOT(refreshslot()));
    this->pg=pg;
    refresh();
}
void pageUi::refresh(){
    this->posts=client::ins().getposts(this->pg.pagelet_id);
    this->main->clear();

    QListWidgetItem *item = new QListWidgetItem();
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable);//unselectable
    item->setSizeHint(QSize(1000,100));
    auto title = new QLabel();
    title->setText("Title:\n"+this->pg.title);
    title->setStyleSheet("font: 75 italic 20pt \"Ubuntu Condensed\";");
    title->setWordWrap(true);
    this->main->addItem(item);
    this->main->setItemWidget(item,title);
    //this->main->setStyleSheet("border: 1px solid black");

    auto it = this->posts.begin();
    while(it!=this->posts.end()){
        QListWidgetItem *item = new QListWidgetItem();
        item->setFlags(item->flags() & ~Qt::ItemIsSelectable);//unselectable
        item->setSizeHint(QSize(1000,200));
        postUi * p = new postUi(&(*it),this);

        connect(p,SIGNAL(upvote(post*)),this,SLOT(addupvote(post*)));
        connect(p,SIGNAL(downvote(post*)),this,SLOT(adddownvote(post*)));
        connect(p,SIGNAL(comment(post*)),this,SLOT(comment(post*)));

        this->main->addItem(item);
        this->main->setItemWidget(item,p);
        it++;
    }

    item = new QListWidgetItem();
    item->setFlags(item->flags() & ~Qt::ItemIsSelectable);//unselectable
    item->setSizeHint(QSize(1000,400));

    this->editor = new commentpostUi(this);
    connect(editor,SIGNAL(submit(QString)),this,SLOT(submit(QString)));
    this->main->addItem(item);
    this->main->setItemWidget(item,editor);
    this->main->setStyleSheet("border: 1px solid black");
}
void pageUi::addupvote(post * p){
    client::ins().changevote(p->post_id,true);
}
void pageUi::adddownvote(post *p){
    QMessageBox::information(NULL,"Hint","Down!!!");
    client::ins().changevote(p->post_id,false);
}
void pageUi::comment(post*p){
    this->editor->geteditor()->setText(editor->geteditor()->toPlainText()+"@"+p->usr_id+" ");
}
void pageUi::submit(QString){
    post po;
    po.content=editor->geteditor()->toPlainText();
    po.page_id=this->pg.pagelet_id;
    int flag =client::ins().uploadpost(po);
    if(flag==0){
        QMessageBox::information(NULL,"Hint","Permission Denied");
    }
    else if(flag==1){
        this->editor->setwarning();
    }
    else {
        refresh();
        QMessageBox::information(NULL,"Hint","Submit successfully!");
    }

}
pageUi::~pageUi(){

}
void pageUi::refreshslot(){
    refresh();
}
