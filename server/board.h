#ifndef BOARD_H
#define BOARD_H
#include "QString"
#include "QJsonObject"
class board
{
public:
    board();
    board(QString,QString);
    board(QJsonObject);
    QJsonObject tojson();
    QString name;
    QString manager_id;
};

#endif // BOARD_H
