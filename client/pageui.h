#ifndef PAGEUI_H
#define PAGEUI_H
#include "tabui.h"
#include "QVector"
#include "post.h"
#include "commentpostui.h"
#include "QListWidget"
#include "QString"
#include "pagelet.h"
class pageUi : public tabUi
{
    Q_OBJECT
public:

    explicit pageUi(pagelet pg,QWidget *parent = nullptr);
    ~pageUi();
private:
    pagelet pg;
    QVector<post> posts;
    QListWidget * main;
    void refresh();
    commentpostUi * editor;
private slots:
    void addupvote(post * p);
    void adddownvote(post *p);
    void comment(post*p);
    void submit(QString content);
    void refreshslot();
};
#endif // PAGEUI_H
