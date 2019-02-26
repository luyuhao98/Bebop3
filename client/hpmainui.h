#ifndef HPMAINUI_H
#define HPMAINUI_H

#include "ui_hpmainui.h"
#include "QCheckBox"
#include "commentpostui.h"
#include "QLineEdit"
#include"pagelet.h"
class hpmainUi : public QWidget, private Ui::hpmainUi
{
    Q_OBJECT

public:
    explicit hpmainUi(QWidget *parent = nullptr);
    void refreshleft();
    void refreshright();
private:
    QString currentboard;
    QVector<QCheckBox*> boxes;
    bool mode; // 0 checkbox mode, 1 click mode

    void refreshrightview();
    void refreshrightselect();
    void initpostbox();
    QDialog * postbox;
    commentpostUi * postsec;
    QLineEdit * postline;
    QLabel * posttitle;
    QLabel * postwarning;

private slots:

    void on_left_list_itemClicked(QListWidgetItem *item);

    void on_right_list_itemClicked(QListWidgetItem *item);

    void on_selectpost_clicked();

    void on_deletepost_clicked();
    void on_postbut_clicked();

    void refreshslot();
    void addpost(QString title);


signals:
    void postpage(pagelet p,QString title);
};

#endif // HPMAINUI_H
