#include "post.h"
post::post()
{
    this->post_id="";
    this->page_id="";
    this->usr_id="";
    this->content="";
    this->time = QTime::currentTime();
    this->upvotes=0;
    this->downvotes=0;
}
post::post(QString post_id,QString page_id,QString usr_id,QString content){
    this->post_id=post_id;
    this->page_id=page_id;
    this->usr_id=usr_id;
    this->content=content;
    this->time = QTime::currentTime();
    this->upvotes=0;
    this->downvotes=0;
}
post::post(QString ptid,QString pgid ,QString uid,QString c,QTime t,long long u,long long d){
    this->post_id=ptid;
    this->page_id=pgid;
    this->usr_id=uid;
    this->content=c;
    this->time =t;
    this->upvotes=u;
    this->downvotes=d;
}
post::post(QJsonObject json){
    if(json.contains("post_id"))
        this->post_id = json.value("post_id").toString();
    if(json.contains("page_id"))
        this->page_id=json.value("page_id").toString();
    if(json.contains("usr_id"))
        this->usr_id=json.value("usr_id").toString();
    if(json.contains("content"))
        this->content=json.value("content").toString();
    if(json.contains("time"))
        this->time=QTime::fromString(json.value("time").toString());
    if(json.contains("upvotes"))
        this->upvotes= json.value("upvotes").toString().toLongLong();
    if(json.contains("downvotes"))
        this->downvotes=json.value("downvotes").toString().toLongLong();
}
QJsonObject post:: tojson(){
    QJsonObject json;
    this->post_id;
    this->page_id;
    json.insert("post_id",this->post_id);
    json.insert("page_id",this->page_id);
    json.insert("usr_id", this->usr_id);
    json.insert("content",this->content);
    json.insert("time",this->time.toString());
    json.insert("upvotes",QString::number( this->upvotes));
    json.insert("downvotes",QString::number( this->downvotes));
    return json;
}

