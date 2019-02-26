#ifndef PROMOTEBM_H
#define PROMOTEBM_H

#include "ui_promotebm.h"
class promotebm : public QDialog, private Ui::promotebm
{
    Q_OBJECT

public:
    explicit promotebm(QString selectedusr,QWidget *parent = nullptr);
    QComboBox * getcombo();
    void refresh();
signals:
    void submit(QString);
private slots:
    void on_submit_clicked();

    void on_combo_currentTextChanged(const QString &arg1);

private:
    Ui::promotebm *ui;
    bool newboard;
    //QComboBox * combo;
};

#endif // PROMOTEBM_H
