#include "client.h"
client::client()
{
    this->tcp = new QTcpSocket();
    this->tcp->abort();
    this->tcp->connectToHost("127.0.0.1",1998);
    bool flag = this->tcp->waitForConnected();
    if(flag){
        qDebug()<<"Connected~";
    }
    else {
        qDebug()<<"Fail to connect server";
    }
}
userinfo * client::getinfo(){
    return  &this->usr;
}
QMap<QString,QVector<pagelet>> * client::gethomepage(){
    return  &this->homepage;
}

QJsonObject client::callback(QJsonObject json){

    QJsonDocument document;
    document.setObject(json);
    QByteArray byteArray = document.toJson(QJsonDocument::Compact);
    QString strJson(byteArray);
    qDebug() << strJson;

    //send json to server,return callback json
    this->tcp->write(byteArray);
    this->tcp->waitForBytesWritten();

    this->tcp->waitForReadyRead();
    auto byteback = this->tcp->readAll();

    QJsonParseError jsonError;
    QJsonDocument doucment = QJsonDocument::fromJson(byteback,&jsonError);    // 转化为 JSON 文档
    //if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)&&(doucment.isObject()))   // JSON 文档为对象
    return doucment.object();  // 转化为对象
}
int client::login(QString id,QString pwd){
    QJsonObject params;
    params.insert("usr",id);
    params.insert("pwd",pwd);
    QJsonObject json;
    json.insert("func","login");
    json.insert("params",QJsonValue(params));
    auto callbackjson = callback(json);

    int status = callbackjson.value("status").toInt();
    if(status==3&&callbackjson.contains("cookie")){
        this->cookie = callbackjson.value("cookie").toString();
        updateuser();
    }
    return status;
}
int client:: signup (QString usr, QString pwd,QString email){
    QJsonObject params;
    params.insert("usr",usr);
    params.insert("pwd",pwd);
    params.insert("email",email);
    QJsonObject json;
    json.insert("func","signup");
    json.insert("params",QJsonValue(params));
    auto callbackjson = callback(json);
    int status = callbackjson.value("status").toInt();
    return status;
}
int client::signupusrcheck(QString usr){
    QJsonObject params;
    params.insert("usr",usr);
    QJsonObject json;
    json.insert("func","signupusrcheck");
    json.insert("params",QJsonValue(params));
    auto callbackjson = callback(json);
    int status = callbackjson.value("status").toInt();
    return status;
}
int client::signuppwdcheck(QString pwd){
    QJsonObject params;
    params.insert("pwd",pwd);
    QJsonObject json;
    json.insert("func","signuppwdcheck");
    json.insert("params",QJsonValue(params));
    auto callbackjson = callback(json);
    int status = callbackjson.value("status").toInt();
    return status;
}
int client::signupemailcheck(QString email){
    QJsonObject params;
    params.insert("email",email);
    QJsonObject json;
    json.insert("func","signupemailcheck");
    json.insert("params",QJsonValue(params));
    auto callbackjson = callback(json);
    int status = callbackjson.value("status").toInt();
    return status;
}

bool client::guestin(){
    this->usr.id="GUEST";
    updatehomepage();
    return true;
}

void client::updatehomepage(){
    /*
    {
        status:
        content:{
            board:[
                 {
                    id:
                    name:
                    balab:
                 },
                {
                id:
                name:


                 },

            ]
            board2{

            }..
            board3:
        }
    }
    */
    QJsonObject json;
    json.insert("func","gethomepage");
    auto callbackjson =callback(json);
    this->homepage.clear();
    if(callbackjson.contains("content")){
        auto content = callbackjson.value("content").toObject();
        auto it = content.begin();
        while(it!=content.end()){
            this->homepage[it.key()].clear();
            auto postsarray = it.value().toArray();
            int arraysize = postsarray.size();
            for(int i = 0;i<arraysize;i++){
                pagelet p(postsarray.at(i).toObject());
                this->homepage[it.key()].push_back(p);
            }
            it++;
        }
    }

    //  //////////////////
    //this->homepage=server::ins().gethomepage();
}

bool client::updateuser(){
    QJsonObject params;
    params.insert("cookie",this->cookie);
    QJsonObject json;
    json.insert("func","getdateuser");
    json.insert("params",QJsonValue(params));

    auto callbackjson = callback(json);
    if(callbackjson.contains("content")){

        userinfo info(callbackjson.value("content").toObject());
        this->usr = info;
    }
    return 0;
    //this->usr = server::ins().updateuser(this->cookie);
}
QVector<post> client::getposts(QString page_id){
    QJsonObject params;
    params.insert("page_id",page_id);
    QJsonObject json;
    json.insert("func","getposts");
    json.insert("params",QJsonValue(params));
    auto callbackjson = callback(json);
    QVector<post> posts;
    if(callbackjson.contains("content")){
        auto content = callbackjson.value("content").toArray();
        auto contentsize = content.size();
        for(int i = 0;i<contentsize;i++){
            post p(content.at(i).toObject());
            posts.push_back(p);
        }
    }
    return posts;
}
QVector<board> client::getboards(){

    QJsonObject json;
    json.insert("func","getboards");
    auto callbackjson = callback(json);
    QVector<board> boards;
    boards.clear();
    if(callbackjson.contains("content")){
        auto content = callbackjson.value("content").toArray();
        auto contentsize = content.size();
        for(int i = 0;i<contentsize;i++){
            board b(content.at(i).toObject());
            boards.push_back(b);
        }
    }
    return boards;
}

QVector<userinfo>  client::getuserlist(){

    QJsonObject params;
    params.insert("cookie",this->cookie);
    QJsonObject json;
    json.insert("func","getuserlist");
    json.insert("params",QJsonValue(params));
    auto callbackjson = callback(json);
    QVector<userinfo> users;
    if(callbackjson.contains("content")){
        auto content = callbackjson.value("content").toArray();
        auto contentsize = content.size();
        for(int i = 0;i<contentsize;i++){
            userinfo b(content.at(i).toObject());
            users.push_back(b);
        }
    }
    return users;
}
int client:: logout (){
    //if a guest
    if(!this->usr.right){
        return 1;
    }
    QJsonObject params;
    params.insert("cookie",this->cookie);
    QJsonObject json;
    json.insert("func","logout");
    json.insert("params",QJsonValue(params));
    auto callbackjson = callback(json);
    if(callbackjson.contains("status")){
        return callbackjson.value("status").toInt();
    }
    return 0;
}

bool client:: deleteusr(QString usr){
    QJsonObject params;
    params.insert("cookie",this->cookie);
    params.insert("usr",usr);
    QJsonObject json;
    json.insert("func","deleteusr");
    json.insert("params",QJsonValue(params));
    auto callbackjson = callback(json);
    if(callbackjson.contains("status")){
        return callbackjson.value("status").toInt();
    }
    return 0;
}
int client:: uploadpost(post p){
    QJsonObject params;
    params.insert("cookie",this->cookie);
    params.insert("post",QJsonValue(p.tojson()));
    QJsonObject json;
    json.insert("func","uploadpost");
    json.insert("params",QJsonValue(params));

    auto callbackjson = callback(json);
    if(callbackjson.contains("status")){
        return callbackjson.value("status").toInt();
    }
    return 0;
}

bool client::changevote(QString post_id,bool up){
    QJsonObject params;
    params.insert("cookie",this->cookie);
    params.insert("post_id",post_id);
    params.insert("up",up);
    QJsonObject json;
    json.insert("func","changevote");
    json.insert("params",QJsonValue(params));

    auto callbackjson = callback(json);
    if(callbackjson.contains("status")){
        return callbackjson.value("status").toInt();
    }
    return 0;
}

int client::createpage(pagelet pgl,post p){
    QJsonObject params;
    params.insert("cookie",this->cookie);
    params.insert("pagelet",QJsonValue(pgl.tojson()));
    params.insert("post",QJsonValue(p.tojson()));
    QJsonObject json;
    json.insert("func","createpage");
    json.insert("params",QJsonValue(params));

    auto callbackjson = callback(json);
    if(callbackjson.contains("status")){
        return callbackjson.value("status").toInt();
    }
    return 0;
}
int client::deletepage(QString pgid){
    QJsonObject params;
    params.insert("cookie",this->cookie);
    params.insert("page_id",pgid);
    QJsonObject json;
    json.insert("func","deletepage");
    json.insert("params",QJsonValue(params));

    auto callbackjson = callback(json);
    if(callbackjson.contains("status")){
        return callbackjson.value("status").toInt();
    }
    return 0;
}


int client::changebm(QString bo,QString usr){
    QJsonObject params;
    params.insert("cookie",this->cookie);
    params.insert("board",bo);
    params.insert("usr",usr);
    QJsonObject json;
    json.insert("func","changebm");
    json.insert("params",QJsonValue(params));

    auto callbackjson = callback(json);
    if(callbackjson.contains("status")){
        return callbackjson.value("status").toInt();
    }
    return 0;
}
int client::changepw(QString oldpwd,QString newpwd){
    QJsonObject params;
    params.insert("cookie",this->cookie);
    params.insert("oldpwd",oldpwd);
    params.insert("newpwd",newpwd);
    QJsonObject json;
    json.insert("func","changepw");
    json.insert("params",QJsonValue(params));

    auto callbackjson = callback(json);
    if(callbackjson.contains("status")){
        return callbackjson.value("status").toInt();
    }
    return 0;
}


int client::changeag(QDate age,int gender){
    QJsonObject params;
    params.insert("cookie",this->cookie);
    params.insert("age",age.toString());
    params.insert("gender",gender);
    QJsonObject json;
    json.insert("func","changeag");
    json.insert("params",QJsonValue(params));

    auto callbackjson = callback(json);
    if(callbackjson.contains("status")){
        return callbackjson.value("status").toInt();
    }
    return 0;
}


client::~client(){
    //logout();
    this->tcp->disconnect();
}
