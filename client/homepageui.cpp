#include "homepageui.h"
#include "ui_tabui.h"
homepageUi::homepageUi(QWidget *parent) :tabUi(parent)
{
    this->hpmain = new hpmainUi(parent);
    this->ui->tablayout->addWidget(hpmain);
    connect(this,SIGNAL(refreshsignal()),this->hpmain,SLOT(refreshslot()));
}
homepageUi::~homepageUi()
{
}


