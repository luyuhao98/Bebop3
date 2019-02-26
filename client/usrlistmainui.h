#ifndef USRLISTMAINUI_H
#define USRLISTMAINUI_H

#include "ui_usrlistmainui.h"
#include "userinfo.h"
#include "board.h"
#include "promotebm.h"
class usrlistmainUi : public QWidget, private Ui::usrlistmainUi
{
    Q_OBJECT

public:
    explicit usrlistmainUi(QWidget *parent = nullptr);
    void refresh();
public  slots:
    void cbox_submit(QString);
private slots:
    void on_deleteuser_clicked();
    void refreshslot();
    void on_levelup_clicked();


signals:
    void submit_click();

private:
    QVector<userinfo> usr_info_list;
    QVector<board> boards;
    QString selectedusr;
    //QDialog *dlg ;
    promotebm * ptb;
};

#endif // USRLISTMAINUI_H
