#ifndef PAGELET_H
#define PAGELET_H
#include "QString"
#include "QTime"
#include "QJsonObject"
class pagelet
{
public:
    pagelet();
    pagelet(QString pagelet_id,QString board_id,QString starter_id,QString title,QTime time);
    pagelet(QJsonObject json);
    QJsonObject tojson();
    QString pagelet_id;
    QString board_id;
    QString starter_id;
    QString title;
    QTime time;
};

#endif // PAGELET_H
