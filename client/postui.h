#ifndef POSTUI_H
#define POSTUI_H
#include "post.h"
#include "ui_postui.h"

class postUi : public QWidget, private Ui::postUi
{
    Q_OBJECT

public:
    explicit postUi(post* p, QWidget *parent = nullptr);
private:
    post*p;

private slots:

    void on_upvotebut_clicked();

    void on_downvotebut_clicked();

    void on_commentbut_clicked();

signals:
    void upvote(post *);
    void downvote(post*);
    void comment(post*);
};

#endif // POSTUI_H
