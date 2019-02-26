#ifndef LOGINUI_H
#define LOGINUI_H

#include <QDialog>
#include <QCloseEvent>
namespace Ui {
class loginUi;
}

class loginUi : public QDialog
{
    Q_OBJECT

public:
    explicit loginUi(QWidget *parent = nullptr);
    ~loginUi();

private slots:
    void on_signin_clicked();

    void on_tosignup_clicked();
    void closeEvent(QCloseEvent *event);
private:
    Ui::loginUi *ui;

};

#endif // LOGINUI_H
