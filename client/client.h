#ifndef CLIENT_H
#define CLIENT_H
#include "userinfo.h"
#include "post.h"
#include "pagelet.h"
#include "board.h"
#include "QVector"
#include "QMap"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonParseError"
#include "QJsonArray"
#include "QTcpSocket"
class client
{

private :
    client();
    client(client const&);// Don't Implement
    void operator=(client const&);    // Don't Implement

    userinfo usr;
    QMap<QString,QVector<pagelet>> homepage;
    QString cookie;
    QTcpSocket *tcp;
public:
    ~client();
    static client& ins(){
        static client instance;
        return instance;
    }


    userinfo * getinfo();
    QMap<QString,QVector<pagelet>> * gethomepage();

    bool guestin();
    int login(QString,QString);
    int  signup (QString usr, QString, QString);
    int signupusrcheck(QString);
    int signupemailcheck(QString email);
    int signuppwdcheck(QString pwd);
    void updatehomepage();
    bool updateuser();
    QVector<post> getposts(QString);
    QVector<board> getboards();
    QVector<userinfo> getuserlist();
    int  logout ();
    bool deleteusr(QString);
    int uploadpost(post p);
    bool changevote(QString post_id,bool up);
    int createpage(pagelet,post);
    int deletepage(QString);
    int changebm(QString board,QString usr);
    int changepw(QString oldpwd,QString newpwd);
    int changeag(QDate,int);//change age and gender
    QJsonObject callback(QJsonObject json);
};

#endif // CLIENT_H
