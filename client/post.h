#ifndef POST_H
#define POST_H
#include"QString"
#include"QTime"
#include"QJsonObject"
class post
{
public:
    post();
    post(QString post_id,QString page_id,QString usr_id,QString content,QTime time,long long upvotes,long long downvotes);
    post(QString post_id,QString page_id,QString usr_id,QString content);
    post(QJsonObject);
    QJsonObject tojson();

    QString post_id;
    QString page_id;
    QString usr_id;
    QString content;
    QTime time;
    long long upvotes;
    long long downvotes;
};

#endif // POST_H
