#include "board.h"

board::board()
{
    this->name="";
    this->manager_id="";
}

board::board(QString n,QString m){
    this->name=n;
    this->manager_id=m;
}
board::board(QJsonObject json){
    if(json.contains("name"))
        this->name = json.value("name").toString();
    if(json.contains("manager_id"))
        this->manager_id=json.value("manager_id").toString();
}
QJsonObject board:: tojson(){
    QJsonObject json;
    json.insert("name",this->name);
    json.insert("manager_id",this->manager_id);
    return json;
}
