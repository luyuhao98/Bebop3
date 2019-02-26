#ifndef USERINFO_H
#define USERINFO_H
#include "QString"
#include "QDate"
#include "QJsonObject"
class userinfo
{
public:
    userinfo();
    userinfo(QString id,QString password,QString email);//signup
    userinfo(QString id,QString password,int right,QString email,int level,QDate age,int gender);//loaddata
    userinfo(QJsonObject json);
    QJsonObject tojson();
    QString id;
    QString password;
    int right; //(visitor(default 0),normal(1),boardmanager(2),admin(3))
    QString email;
    int level;
    QDate age;
    int gender;//((0 female),(1 male))
};

#endif // USERINFO_H
