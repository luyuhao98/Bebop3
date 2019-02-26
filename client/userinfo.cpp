#include "userinfo.h"

userinfo::userinfo()
{
    this->id="";
    this->password="";
    this->right=0; //(visitor(default 0),normal(1),boardmanager(2),admin(3))
    this->email="";
    this->level=0;
    this->age=QDate::currentDate();
    this->gender=0;//((0 female),(1 male))
}
userinfo::userinfo(QString id,QString password,QString email)//signup
{
    this->id = id;
    this->password = password;
    this->email =email;
    this->right=1; //(visitor(default 0),normal(1),boardmanager(2),admin(3))
    this->level=0;
    this->age=QDate::currentDate();
    this->gender=0;//((0 female),(1 male))
}
userinfo::userinfo(QString id,QString password,int right,QString email,int level,QDate age,int gender)//loaddata
{
    this->id=id;
    this->password=password;
    this->right=right; //(visitor(default 0),normal(1),boardmanager(2),admin(3))
    this->email=email;
    this->level=level;
    this->age=age;
    this->gender=gender;//((0 female),(1 male))
}
userinfo::userinfo(QJsonObject json){
    if(json.contains("id"))
        this->id = json.value("id").toString();
    if(json.contains("password"))
        this->password = json.value("password").toString();
    if(json.contains("right"))
        this->right = json.value("right").toInt();
    if(json.contains("email"))
        this->email = json.value("email").toString();
    if(json.contains("level"))
        this->level = json.value("level").toInt();
    if(json.contains("age"))
        this->age =QDate::fromString(json.value("age").toString());
    if(json.contains("gender"))
        this->gender = json.value("gender").toInt();

}
QJsonObject userinfo:: tojson(){
    QJsonObject json;
    json.insert("id",this->id);
    json.insert("password",this->password);
    json.insert("right",this->right);
    json.insert("email",this->email);
    json.insert("age",this->age.toString());
    json.insert("gender",this->gender);
    return json;
}
