#ifndef TABUI_H
#define TABUI_H

#include <QWidget>

namespace Ui {
class tabUi;
}

class tabUi : public QWidget
{
    Q_OBJECT

public:
    explicit tabUi(QWidget *parent = nullptr);
    void initmenu();
    ~tabUi();
    Ui::tabUi *ui;

private slots:
    void on_logo_clicked();
    void on_pushButton_clicked();

signals:
    void gohomepage();
    void profile();
    void help();
    void setting();
    void logout();
    void usrlist();
    void refreshsignal();
};

#endif // TABUI_H
