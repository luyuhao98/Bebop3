#ifndef USRLISTUI_H
#define USRLISTUI_H
#include"tabui.h"
#include"usrlistmainui.h"
class usrlistUi : public tabUi
{
public:

    explicit usrlistUi(QWidget *parent = nullptr);
    usrlistmainUi * ulmain;
};

#endif // USRLISTUI_H
