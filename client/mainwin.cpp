#include "mainwin.h"
#include "ui_mainwin.h"
#include "QMessageBox"
#include "QVBoxLayout"
#include "QProcess"
#include "client.h"
#include "pageui.h"
#include "usrlistui.h"
#include "settingui.h"
Mainwin::Mainwin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mainwin)
{
    ui->setupUi(this);
    ui->mainlayout->setAlignment(Qt::AlignTop);
    ui->tabWidget->setTabsClosable(true);
    ui->tabWidget->setMovable(true);
    homepage();
}

Mainwin::~Mainwin()
{
    client::ins().logout();
    delete ui;
}
void Mainwin::newtab(tabUi*tab,QString title){
    int index = ui->tabWidget->addTab(tab,title);
    ui->tabWidget->setCurrentIndex(index);
    connect(tab,SIGNAL(gohomepage()),this,SLOT(homepage()));
    connect(tab,SIGNAL(profile()),this,SLOT(profile()));
    connect(tab,SIGNAL(help()),this,SLOT(help()));
    connect(tab,SIGNAL(setting()),this,SLOT(setting()));
    connect(tab,SIGNAL(logout()),this,SLOT(logout()));
    connect(tab,SIGNAL(usrlist()),this,SLOT(usrlist()));
}
void Mainwin::homepage(){
    auto hp = new homepageUi(this);
    connect(hp->hpmain,SIGNAL(postpage(pagelet,QString)),this,SLOT(postpage(pagelet,QString)));
    newtab(hp,"Home");
}
void Mainwin::postpage(pagelet pg,QString title){
    auto ptpg = new pageUi(pg,this);
    newtab(ptpg,title);
}

void Mainwin::profile(){

    auto p = client::ins().getinfo();
    client::ins().updateuser();
    QString gender = p->gender?"Male":"Female";
    QMessageBox::information(NULL,"Personal Info","Username: "+p->id+"\nBirth:"+p->age.toString()+"\nEmail:"+p->email+"\nGender:"+gender );
}
void Mainwin::help(){

}

void Mainwin::setting(){
    auto set = new settingUi(this);
    set->exec();
    client::ins().updateuser();
}
void Mainwin::logout(){
    auto reply = QMessageBox::question(this, "Hint", "Log out?",
                                  QMessageBox::Yes|QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        client::ins().logout();
        //restart app;
        qApp->quit();
        QProcess::startDetached(qApp->applicationFilePath(),QStringList());
    }
}
void Mainwin::usrlist(){
    auto usrlist = new usrlistUi(this);
    newtab(usrlist,"User list");
}


void Mainwin::on_tabWidget_tabCloseRequested(int index)
{
    if(ui->tabWidget->count()==1)
        this->close();
    ui->tabWidget->removeTab(index);
}
void Mainwin::closeEvent(QCloseEvent *event){
}
