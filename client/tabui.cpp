#include "tabui.h"
#include "ui_tabui.h"
#include "client.h"
#include "QMenu"
tabUi::tabUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::tabUi)
{
    ui->setupUi(this);
    ui->tablayout->setAlignment(Qt::AlignTop);
    initmenu();
}
void tabUi::initmenu(){


    ui->usrbut->setText("Hi,"+client::ins().getinfo()->id+"!");

    /*button menu*/


    auto  mymenu =new QMenu(this);
    auto profile = new QAction(mymenu);
    auto setting = new QAction(mymenu);
    auto logout = new QAction(mymenu);
    auto usrlist = new QAction(mymenu);

    profile->setText("Your profile");
    setting->setText("Setting");
    logout->setText("Log out");
    usrlist->setText("User list");


    if(client::ins().getinfo()->right){
        mymenu->addAction(profile);
        mymenu->addAction(setting);
    }
    if(client::ins().getinfo()->right==3)
        mymenu->addAction(usrlist);
    mymenu->addAction(logout);

    //mymenu->setMouseTracking(false);
    mymenu->setStyleSheet("font: 75 12pt \"URW Bookman L\";selection-background-color: rgb(32, 74, 135);");
    connect(profile, &QAction::triggered, this, &tabUi::profile);
    connect(setting, &QAction::triggered, this, &tabUi::setting);
    connect(logout, &QAction::triggered, this, &tabUi::logout);
    connect(usrlist, &QAction::triggered, this, &tabUi::usrlist);
    ui->usrbut->setMenu(mymenu);
    //ui->topbar_usrbut->setStyleSheet("QPushButton::menu-indicator{image:none;}");

}
tabUi::~tabUi()
{
    delete ui;
}

void tabUi::on_logo_clicked()
{
    emit gohomepage();
}

void tabUi::on_pushButton_clicked()
{
    emit refreshsignal();
}
