#ifndef MAINWIN_H
#define MAINWIN_H

#include <QWidget>
#include "homepageui.h"
#include <QCloseEvent>
namespace Ui {
class Mainwin;
}

class Mainwin : public QWidget
{
    Q_OBJECT

public:
    explicit Mainwin(QWidget *parent = nullptr);
    ~Mainwin();
    void newtab(tabUi*tab,QString title);
private slots:
    void on_tabWidget_tabCloseRequested(int index);
    void homepage();
    void postpage(pagelet,QString);

    void profile();
    void help();
    void setting();
    void logout();
    void usrlist();

private:
    void closeEvent(QCloseEvent *event);
    Ui::Mainwin *ui;
};

#endif // MAINWIN_H
