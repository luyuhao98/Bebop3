#include "pagelet.h"
pagelet::pagelet()
{
    this->pagelet_id="";
    this->board_id="";
    this->starter_id="";
    this->title="";
    this->time=QTime::currentTime();
}
pagelet::pagelet(QString pid,QString bid,QString sid,QString tt,QTime ti)
{
    this->pagelet_id=pid;
    this->board_id=bid;
    this->starter_id=sid;
    this->title=tt;
    this->time=ti;
}
pagelet ::pagelet(QJsonObject json){
    if(json.contains("pagelet_id"))
        this->pagelet_id = json.value("pagelet_id").toString();
    if(json.contains("board_id"))
        this->board_id = json.value("board_id").toString();
    if(json.contains("starter_id"))
        this->starter_id = json.value("starter_id").toString();
    if(json.contains("title"))
        this->title = json.value("title").toString();
    if(json.contains("time"))
        this->time =QTime::fromString( json.value("time").toString());
}
QJsonObject  pagelet::tojson(){
    QJsonObject json;
    json.insert("pagelet_id",this->pagelet_id);
    json.insert("board_id",this->board_id);
    json.insert("start_id",this->starter_id);
    json.insert("title",this->title);
    json.insert("time",this->time.toString());
    return json;
}
