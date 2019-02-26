#ifndef SERVER_H
#define SERVER_H
#include "board.h"
#include "pagelet.h"
#include "post.h"
#include "userinfo.h"
#include "QMap"
#include "QVector"
#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include "QTcpServer"
#include "QTcpSocket"
#include "QObject"
#include "QSignalMapper"
#include "QJsonDocument"
#include "QJsonObject"
#include "QJsonParseError"
#include "QJsonArray"

class server:public QObject
{
    Q_OBJECT
private:
    QVector<board> boards;
    QVector<pagelet> pagelets;
    QVector<post> posts;
    QVector<userinfo> users;
    QMap<QString,QString> sessions;
    QSqlDatabase db;
    QSqlQuery * dbq;

    QSignalMapper* mapper;
    QSignalMapper* disconmapper;
    QTcpServer* tcpserver;
    QMap<int,QTcpSocket*> sockets;
    int socketId;

    //Singleton
    server();
    server(server const&);// Don't Implement
    void operator=(server const&);    // Don't Implement
    ~server();//shutdown and upgrade

    void loaduserinfos();
    void loadposts();
    void loadpagelets();
    void loadboard();
    void initdatabase();
    void replacebase();


    int  usr_formvalid(QString usr);
    int  pwdvalid(QString pwd);
    int  emailvalid(QString email);
    int  postvalid(post);
    int  titlevalid(QString title);
    int signupusrcheck(QString usr);
    int signuppwdcheck(QString pwd);
    int signupemailcheck(QString email);
    bool setusrright(QString usr,QString,int);
    int uploadpost(post p,QString);

    userinfo * getuser(QString usrid);
    board* getboard(QString bd);
    void sessionadd (userinfo*);
    userinfo * cookie2usr(QString cookie);

    QMap<QString,QVector<pagelet>> gethomepagemap();
    QVector<post> getposts(QString);


    void connumfresh();
    void inittcpserver();
private slots:
    void newConnect();
    void disconnect(int);
    void readMsg(int);
signals:
    void print(QString);
    void connum(int);

public:
    void dataaddusr(userinfo &u);

    static server& ins(){
        static server instance;
        return instance;
    }
    //needn't to check right;
    QString  login (QString usr,QString pwd);
    QJsonObject login(QJsonObject);
    //int  signup (QString usr, QString, QString);
    QJsonObject signup(QJsonObject);

    QJsonObject signupusrcheck(QJsonObject);
    QJsonObject signuppwdcheck(QJsonObject);
    QJsonObject signupemailcheck(QJsonObject);

    //userinfo updateuser(QString);
    QJsonObject getdateuser(QJsonObject params);
    QJsonObject gethomepage();
    QJsonObject getposts(QJsonObject);

    //QVector<board> getboards();
    QJsonObject getboards();
    //QVector<userinfo> getuserlist(QString);
    QJsonObject getuserlist(QJsonObject);

    /*need cookie to check right;*/

    //bool  logout (QString);
    QJsonObject logout(QJsonObject params);
    //bool deleteusr(QString usr,QString);
    QJsonObject deleteusr(QJsonObject params);
    QJsonObject uploadpost(QJsonObject params);

    //bool changevote(QString post_id,QString cookie,bool up);
    QJsonObject changevote(QJsonObject params);

    //int createpage(pagelet pgl,post p,QString);
    QJsonObject createpage(QJsonObject params);

   // bool deletepage(QString pageid,QString);
    QJsonObject deletepage(QJsonObject params);

    //int changebm(QString board,QString usr,QString);
    QJsonObject changebm(QJsonObject params);

    //int changepw(QString oldpwd,QString newpwd,QString cookie);
    QJsonObject changepw(QJsonObject params);

    //int changeag(QDate,int,QString cookie);//change age and gender
    QJsonObject changeag(QJsonObject params);
};

server * operator<< (server * s,userinfo & u );
//QSqlDatabase *operator <<(QSqlDatabase *db,userinfo);
//QSqlQuery * dbq;
#endif // SERVER_H
