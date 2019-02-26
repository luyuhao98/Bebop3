#ifndef COMMENTPOSTUI_H
#define COMMENTPOSTUI_H

#include "ui_commentpostui.h"

class commentpostUi : public QWidget, private Ui::commentpostUi
{
    Q_OBJECT

public:
    explicit commentpostUi(QWidget *parent = nullptr);
    QTextEdit * geteditor();
    void setwarning();
private slots:


    void on_clear_clicked();

    void on_post_clicked();

signals:
    void submit(QString);
};

#endif // COMMENTPOSTUI_H
