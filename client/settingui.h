#ifndef SETTINGUI_H
#define SETTINGUI_H

#include "ui_settingui.h"
#include "userinfo.h"
class settingUi : public QDialog, private Ui::settingUi
{
    Q_OBJECT
public:
    explicit settingUi(QWidget *parent = nullptr);

private slots:
    void on_pushButton_clicked();
    void closeEvent(QCloseEvent *event);
};

#endif // SETTINGUI_H
