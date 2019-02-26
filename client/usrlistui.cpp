#include "usrlistui.h"

#include "ui_tabui.h"
usrlistUi::usrlistUi(QWidget *parent) :tabUi(parent)
{
    this->ulmain = new usrlistmainUi(parent);
    this->ui->tablayout->addWidget(ulmain);
    connect(this,SIGNAL(refreshsignal()),this->ulmain,SLOT(refreshslot()));
}
