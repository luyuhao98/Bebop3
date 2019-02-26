

#include "server.h"
#include "QEventLoop"
#include <QCoreApplication>
#include "fakedialog.h"
//int main(int argc, char *argv[])
//{
//    loginUi  dlg;
//    auto flag = dlg.exec();
//    if (flag == QDialog::Accepted)
//        {
//           Mainwin bbs;
//           bbs.show();
//           return a.exec();
//        }
//    else return 0;
//}

int main(int argc, char *argv[])
{
 //   QCoreApplication a(argc,argv);
    QApplication a(argc, argv);

//    QEventLoop loop;

    fakedialog dlg;

    dlg.exec();
    return 0;
}
