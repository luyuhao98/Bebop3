#include "postui.h"
postUi::postUi(post *p,QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->p=p;
    this->usr->setText(p->usr_id);
    this->usr->setWordWrap(true);
    this->usr->setStyleSheet("font: 75 oblique 16pt \"Waree\";background-color: rgb(255, 255, 255);");


    this->content->setText(p->content);
    this->content->setAlignment(Qt::AlignTop);
    this->content->setWordWrap(true);
    this->content->setStyleSheet("font: 57 16pt \"Ubuntu\";background-color: rgb(255, 255, 255);");

    this->upvotebut->setText(QString::number(p->upvotes));
    this->downvotebut->setText(QString::number(p->downvotes));
    this->status->setText(p->time.toString());

}


void postUi::on_upvotebut_clicked()
{
    this->upvotebut->setText(QString::number(++this->p->upvotes));
    emit upvote(this->p);
}

void postUi::on_downvotebut_clicked()
{
    this->downvotebut->setText(QString::number(++this->p->downvotes));
    emit downvote(this->p);
}

void postUi::on_commentbut_clicked()
{
    emit comment(this->p);
}
