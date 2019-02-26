#ifndef SIGNUPUI_H
#define SIGNUPUI_H

#include <QDialog>

namespace Ui {
class signupUi;
}

class signupUi : public QDialog
{
    Q_OBJECT

public:
    explicit signupUi(QWidget *parent = nullptr);
    ~signupUi();
private slots:
    void on_up_usrlineEdit_editingFinished();


    void on_up_email_lineEdit_editingFinished();

    void on_tosignin_clicked();

    void on_up_pwdlineEdit_editingFinished();

    void on_up_rpt_pwdlineEdit_editingFinished();

    void on_signup_clicked();
    void closeEvent(QCloseEvent *event);

private:
    Ui::signupUi *ui;
};

#endif // SIGNUPUI_H
