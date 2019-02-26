#ifndef HOMEPAGEUI_H
#define HOMEPAGEUI_H
#include "tabui.h"
#include "hpmainui.h"

class homepageUi : public tabUi
{
public:
    explicit homepageUi(QWidget *parent = nullptr);
    ~homepageUi();
    hpmainUi *hpmain ;
};

#endif // HOMEPAGEUI_H
