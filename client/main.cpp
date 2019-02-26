#include "mainwin.h"
#include <QApplication>
#include "loginui.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginUi  dlg;
    auto flag = dlg.exec();
    if (flag == QDialog::Accepted)
        {
           Mainwin bbs;
           bbs.show();
           return a.exec();
        }
    else return 0;
}
