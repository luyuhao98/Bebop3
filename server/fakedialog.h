#ifndef FAKEDIALOG_H
#define FAKEDIALOG_H

#include "ui_fakedialog.h"

class fakedialog : public QDialog, private Ui::fakedialog
{
    Q_OBJECT
public:
    explicit fakedialog(QWidget *parent = nullptr);
private slots:
    void on_buttonBox_accepted();
    void print(QString);
    void connum(int);
};

#endif // FAKEDIALOG_H
