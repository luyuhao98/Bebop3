#include "server.h"
#include "QCryptographicHash"
#include "QRegExp"
#include "QTime"
#include <QCoreApplication>
#include "QFile"


server::server():QObject ()
{
    initdatabase();
    loaduserinfos();
    loadboard();
    loadposts();
    loadpagelets();
    inittcpserver();
}

server::~server(){
    replacebase();
}
void server::initdatabase(){

    this->db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbname = "database.db";
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName(dbname);
    db.setUserName("root");
    db.setPassword("19980129");
    bool dbcreate =false;
    if(!QFile::exists(dbname)){
        qDebug()<<QString("firsttime!!");
        //exit
        dbcreate = true;
    }
    bool ok = db.open();
    if (ok)
    {
        qDebug() << QString("Success to open the database!");

        //init QsqlQuery dbp;
        this->dbq = new QSqlQuery(db);

        /*
         * First time run create database and init it.
         * */

        if(dbcreate)
        {
            //create tables: users,posts,pagelets and boards;
            dbq->prepare("create table users (id varchar(20) primary key, password varchar(32), right int, email varchar(90),level int,age date, gender int)");
            if(!dbq->exec()) qDebug()<<"1:"<<dbq->lastError();
            dbq->prepare("create table posts (post_id verchar(32) primary key, page_id verchar(32),usr_id verchar(20),content varchar(2000),ttime time,upvotes long, downvotes long)");
            if(!dbq->exec()) qDebug()<<"2:"<<dbq->lastError();

            dbq->prepare("create table pagelets (pagelet_id verchar(32) primary key, board_id verchar(32),starter_id verchar(20),title varchar(64),ttime time)");
            if(!dbq->exec()) qDebug()<<"3"<<dbq->lastError();

            dbq->prepare("create table boards (name verchar(32) primary key, manager_id verchar(20))");
            if(!dbq->exec()) qDebug()<<"4"<<dbq->lastError();

            //Create root~~~~ the god of this system!!!!!!!!!!
            userinfo rootboy({"root","e10adc3949ba59abbe56e057f20f883e",3,
                              "249691892@qq.com",99,QDate::currentDate(),0});
            users.push_back(rootboy);
            //Create boards~~~~
            boards.push_back(board({"C++","Rick"}));
            boards.push_back(board({"Javascript","Eric"}));
            boards.push_back(board({"Python","Justin"}));
            boards.push_back(board({"Java","Kyle"}));
            //create pagelets;
            //pagelet(QString pagelet_id,QString board_id,QString starter_id,QString title,QTime time);
            pagelets.push_back(pagelet({"python1","Python","Snoop","Model summary in pytorch",QTime::currentTime()}));
            pagelets.push_back(pagelet({"python2","Python","Dr.Dre","Tensorflow: how to save/restore a model?",QTime::currentTime()}));

            //create posts
            //post_id , page_id ,usr_id,content
            posts.push_back(post({"wp1","python1","Snoop","Is there any way, I can print the summary of a model in PyTorch like model.summary() method does in Keras as follows?"}));
            posts.push_back(post({"wp2","python1","Rezz","While you will not get as detailed information about the model as in Keras' model.summary, simply printing the model will give you some idea about the different layers involved and their specifications."}));
            posts.push_back(post({"wp3","python1","Jay-Z","@Drake Have you seen the state_dict() method on the module?? It gives you the different parameters of the model. There is no direct summary method, but one could form one using the state_dict() method"}));

            posts.push_back(post({"wp4","python2","Dr.Dre","After you train a model in Tensorflow:\n1.How do you save the trained model?\n2.How do you later restore this saved model?"}));
            posts.push_back(post({"wp5","python2","Daft Punk","The checkpoints that are saved contain values for the Variables in your model, not the model/graph itself, which means that the graph should be the same when you restore the checkpoint."}));


        }

    }
    else
    {
        qDebug() << "Fail to open the database" ;
        exit(0);
    }
    //db.removeDatabase(dbname);
}
void server::replacebase(){
    auto uit = this->users.begin();
    dbq->exec("Delete from users;");
    while (uit!=this->users.end()) {
//        dbq->prepare("Insert INTO users (id,password,right,email,level,age,gender)"
//                     "VALUES (:id,:password,:right,:email,:level,:age,:gender);");
//        dbq->bindValue(":id",uit->id);
//        dbq->bindValue(":password",uit->password);
//        dbq->bindValue(":right",uit->right);
//        dbq->bindValue(":email",uit->email);
//        dbq->bindValue(":level",uit->level);
//        dbq->bindValue(":age",uit->age);
//        dbq->bindValue(":gender",uit->gender);

//        if(!dbq->exec()) {qDebug()<<"replace users error! :"<<dbq->lastError();}
        this<<*uit;
        uit++;
    }
    auto pit = this->posts.begin();
    dbq->exec("Delete from posts;");
    while (pit!=this->posts.end()) {
        dbq->prepare("Insert INTO posts (post_id , page_id ,usr_id,content,ttime,upvotes, downvotes)"
                     "VALUES (:post_id,:page_id,:usr_id,:content,:ttime,:upvotes,:downvotes);");

        //post_id , page_id ,usr_id,content,ttime,upvotes, downvotes
        dbq->bindValue(":post_id",pit->post_id);
        dbq->bindValue(":page_id",pit->page_id);
        dbq->bindValue(":usr_id",pit->usr_id);
        dbq->bindValue(":content",pit->content);
        dbq->bindValue(":ttime",pit->time);
        dbq->bindValue(":upvotes",pit->upvotes);
        dbq->bindValue(":downvotes",pit->downvotes);

        if(!dbq->exec()) {qDebug()<<"replace posts error! :"<<dbq->lastError();}
        pit++;
    }
    auto pgit = this->pagelets.begin();
    dbq->exec("Delete  from pagelets;");
    while (pgit!=this->pagelets.end()) {
        dbq->prepare("Insert INTO pagelets (pagelet_id , board_id,starter_id ,title ,ttime)"
                     "VALUES (:pagelet_id , :board_id,:starter_id,:title ,:ttime);");
        //pagelet_id , board_id,starter_id ,title ,ttime
        dbq->bindValue(":pagelet_id",pgit->pagelet_id);
        dbq->bindValue(":board_id",pgit->board_id);
        dbq->bindValue(":starter_id",pgit->starter_id);
        dbq->bindValue(":title",pgit->title);
        dbq->bindValue(":ttime",pgit->time);

        if(!dbq->exec()) {qDebug()<<"replace pagelets error! :"<<dbq->lastError();}
        pgit++;
    }
    auto bit = this->boards.begin();
    dbq->exec("Delete  from boards;");
    while (bit!=this->boards.end()) {
        dbq->prepare("Insert INTO boards (name , manager_id)"
                     "VALUES (:name,:manager_id);");
        dbq->bindValue(":name",bit->name);
        dbq->bindValue(":manager_id",bit->manager_id);

        if(!dbq->exec()) {qDebug()<<"replace boards error! :"<<dbq->lastError();}
        bit++;
    }
}
void server::loaduserinfos(){
    dbq->prepare("SELECT id,password,right,email,level,age,gender FROM users;");
    if(!dbq->exec()) {
        qDebug()<<dbq->lastError();
    }
    else{
        while(dbq->next()){
            /*
                    "VALUES (:id,:password,:right,:email,:level,:age,:gender);");
            */
            userinfo usr={dbq->value("id").toString(),dbq->value("password").toString(),dbq->value("right").toInt(),
                           dbq->value("email").toString(),dbq->value("level").toInt(),dbq->value("age").toDate(),dbq->value("gender").toInt()
                         };
            this->users.push_back(usr);
        }
    }
}
void server::loadposts(){

    dbq->prepare("SELECT post_id , page_id ,usr_id,content,ttime,upvotes, downvotes FROM posts ORDER BY ttime;");
    if(!dbq->exec()) {
        qDebug()<<dbq->lastError();
    }
    else{
        while(dbq->next()){
            /*
                    post_id , page_id ,usr_id,content,ttime,upvotes, downvotes
            */
            post p={dbq->value("post_id").toString(),dbq->value("page_id").toString(),dbq->value("usr_id").toString(),
       dbq->value("content").toString(),dbq->value("ttime").toTime(),dbq->value("upvotes").toLongLong(),dbq->value("downvotes").toLongLong()
                         };
            this->posts.push_back(p);
        }
    }
}
void server::loadpagelets(){

    dbq->prepare("SELECT pagelet_id , board_id,starter_id ,title ,ttime  FROM pagelets ORDER BY ttime;");
    if(!dbq->exec()) {
        qDebug()<<dbq->lastError();
    }
    else{
        while(dbq->next()){
            /*
                    pagelet_id , board_id,starter_id ,title ,ttime
            */
            pagelet p={dbq->value("pagelet_id").toString(),dbq->value("board_id").toString(),dbq->value("starter_id").toString(),
       dbq->value("title").toString(),dbq->value("ttime").toTime()
                       };
            this->pagelets.push_back(p);
        }
    }
}
void server::loadboard(){

    dbq->prepare("SELECT name , manager_id  FROM boards;");
    if(!dbq->exec()) {
        qDebug()<<dbq->lastError();
    }
    else{
        while(dbq->next()){
            /*
                    name , manager_id
            */
            board b={dbq->value("name").toString(),dbq->value("manager_id").toString()};
            this->boards.push_back(b);
        }
    }
}
userinfo * server::cookie2usr(QString cookie){
    if(!sessions.count(cookie)){
        return nullptr;//don't exsit. ->Guest.
    }

    else {
        return getuser(sessions[cookie]);
    }
}
board* server::getboard(QString bd){
   auto it = this->boards.begin();
   while(it->name.compare(bd)&&it!=this->boards.end()) it++;
   if(it!=this->boards.end()){
       return &(*it);
   }
   return nullptr;
}
userinfo * server:: getuser(QString usr){
    auto it = this->users.begin();

    while(it!=this->users.end()&&it->id.compare(usr))it++;

    if(it!=this->users.end()){
        return &(*it);
    }
    return nullptr;
}
void server::sessionadd (userinfo* usr){
    auto session = QCryptographicHash::hash ((usr->id+QTime::currentTime().toString()).toUtf8(), QCryptographicHash::Md5 ).toHex();
    //if the usr_id has already in session,replace the old session with the new
    auto it = this->sessions.begin();
    while(it!=this->sessions.end()){
        if(!it.value().compare(usr->id)){//usr_id exists
           it = this->sessions.erase(it);//erase it;
        }
        else
            it++;
    }
    this->sessions.insert(session,usr->id);
}
int server::usr_formvalid(QString usr){
    QRegExp rx;

    rx.setPatternSyntax(QRegExp::RegExp);
    //Case sensitive
    rx.setCaseSensitivity(Qt::CaseSensitive);
    //4-20 Characters,a-zA-Z0-9_
    rx.setPattern(QString("^[a-zA-Z0-9_]{6,20}$"));

    if(rx.exactMatch(usr)){
       return 1;//User Valid
    }
    else return 0;//
}
int server::pwdvalid(QString pwd){
    QRegExp rx;
    rx.setPatternSyntax(QRegExp::RegExp);
    //Case sensitive
    rx.setCaseSensitivity(Qt::CaseSensitive);
    //At least 8 characters, including at least one uppercase character, one lowercase character and one number
    rx.setPattern(QString("^(?=.*[a-z])(?=.*[A-Z])(?=.*[0-9]).{8,}$"));
    if(rx.exactMatch(pwd)){
       return 1;//Password Valid
    }
    else return 0;//
}
int server:: emailvalid(QString email)
{
    if (email.length()>90){
        return 0;
    }
    QRegExp rx;

    rx.setPatternSyntax(QRegExp::RegExp);
    //Case sensitive
    rx.setCaseSensitivity(Qt::CaseSensitive);
    //A-Za-z0-9_-. or Chinese @ domain(length between 2 to 8)
    rx.setPattern(QString("^([A-Za-z0-9_-.\u4e00-\u9fa5])+@([A-Za-z0-9_-.])+.([A-Za-z]{2,8})$"));

    if(rx.exactMatch(email)){
       return 1;//Email Valid
    }
    else return 0;//
}
bool server::setusrright(QString usr,QString cookie,int r){
    auto root = cookie2usr(cookie);
    if(!root||root->right!=3)
        return 0;
    auto temp  = getuser(usr);
    if(temp)
        temp->right=r;
    return 1;
}
int server:: signupusrcheck(QString usr)
{
    if(getuser(usr)){
        return  0;
    }
    else{
        if(usr_formvalid(usr)){
            return 1;//ok
        }
    else{
        return 2;
        }
    }

}
int server::signuppwdcheck(QString pwd){
    if(pwdvalid(pwd)){
        return 1;
    } else{
        return 0;
    }
}
int server::signupemailcheck(QString email){
    if(emailvalid(email)){
        return 1;
    } else{
        return 0;
    }
}
int server::postvalid(post p){
    auto it = this->pagelets.begin();
    while(it!=this->pagelets.end()){
        if(!it->pagelet_id.compare(p.page_id))
            break;
        it++;
    }
    if(it==this->pagelets.end()||p.content.length()>2000||p.content.length()==0)
        return 0;
//    QRegExp rx;
//    rx.setPatternSyntax(QRegExp::RegExp);
//    rx.setCaseSensitivity(Qt::CaseSensitive);
//    rx.setPattern(QString("^(.|\n){1,}$"));
//    if(rx.exactMatch(content)){
       return 1;//User Valid
//    }
//    else return 0;//
}
int server::titlevalid(QString title){
    if(title.length()>64||title.length()==0)
        return 0;
//    QRegExp rx;
//    rx.setPatternSyntax(QRegExp::RegExp);
//    rx.setCaseSensitivity(Qt::CaseSensitive);
//    rx.setPattern(QString("^(.|\n){1,}$"));
//    if(rx.exactMatch(content)){
       return 1;//User Valid
//    }
//    else return 0;//
}

/*public*/

void server::connumfresh(){
    emit connum(this->sessions.size());
}
void server::inittcpserver(){
    int port = 1998;
    this->socketId = 0;
    this->tcpserver = new QTcpServer(this);
    bool flag =this->tcpserver->listen(QHostAddress::LocalHost,port);
    if (!flag){
        emit print("Fail to listen"+QString::number(port));
        emit print(this->tcpserver->errorString());
        this->tcpserver->close();
    }
    else {
        emit print("Successfully open the service");
    }

    this->mapper = new QSignalMapper(this);
    this->disconmapper= new QSignalMapper(this);
    connect(tcpserver,SIGNAL(newConnection()),this,SLOT(newConnect()));
    connect(this->mapper,SIGNAL(mapped(int)),this,SLOT(readMsg(int)));
    connect(this->disconmapper,SIGNAL(mapped(int)),this,SLOT(disconnect(int)));
}
void server::newConnect(){
    this->sockets[++(this->socketId)]=this->tcpserver->nextPendingConnection();
    mapper->setMapping(this->sockets[this->socketId],this->socketId);
    if(connect(this->sockets[(this->socketId)],SIGNAL(readyRead()),this->mapper,SLOT(map()))&&
            connect(this->sockets[(this->socketId)],SIGNAL(disconnect()),this->disconmapper,SLOT(map())))
    {
        emit print("New Connection with socket:"+QString::number(this->socketId));
        connumfresh();
    }
}
void server::disconnect(int socketid){
    this->sockets.remove(socketid);
    emit print("New Connection with socket:"+QString::number(socketid));
    connumfresh();
}

void server::readMsg(int index){
    if(this->sockets.contains(index)){
        QByteArray byteget = this->sockets[index]->readAll();
        print("Request Json from socketId "+QString::number(index)+":");
        print(QString(byteget));

        QJsonParseError jsonError;
        QJsonDocument doucment = QJsonDocument::fromJson(byteget,&jsonError);  // 转化为 JSON 文档
        if (!doucment.isNull() && (jsonError.error == QJsonParseError::NoError)&&(doucment.isObject())){  // JSON 文档为对象
                QJsonObject object = doucment.object();  // 转化为对象

                if (object.contains("func")) {
                    QJsonValue value = object.value("func").toString();
                    if (value.isString()) {
                        QJsonObject json;
                        QString func = value.toString();
                        QJsonObject params =  object.value("params").toObject();

                        if(!func.compare("login")){
                            json = login(params);
                        }
                        else if(!func.compare("signup")){
                            json = signup(params);
                        }
                        else if(!func.compare("signupusrcheck")){
                            json = signupusrcheck(params);
                        }
                        else if(!func.compare("signuppwdcheck")){
                            json = signuppwdcheck(params);
                        }
                        else if(!func.compare("signupemailcheck")){
                            json = signupemailcheck(params);
                        }
                        else if(!func.compare("gethomepage")){
                            json = gethomepage();
                        }
                        else if(!func.compare("getdateuser")){
                            json = getdateuser(params);
                        }
                        else if(!func.compare("getposts")){
                            json = getposts(params);
                        }
                        else if(!func.compare("getboards")){
                            json = getboards();
                        }
                        else if(!func.compare("getuserlist")){
                            json = getuserlist(params);
                        }
                        else if(!func.compare("logout")){
                            json = logout(params);
                        }
                        else if(!func.compare("deleteusr")){
                            json = deleteusr(params);
                        }
                        else if(!func.compare("uploadpost")){
                            json = uploadpost(params);
                        }
                        else if(!func.compare("changevote")){
                            json = changevote(params);
                        }
                        else if(!func.compare("createpage")){
                            json = createpage(params);
                        }
                        else if(!func.compare("deletepage")){
                            json = deletepage(params);
                        }
                        else if(!func.compare("changebm")){
                            json = changebm(params);
                        }
                        else if(!func.compare("changepw")){
                            json = changepw(params);
                        }
                        else if(!func.compare("changeag")){
                            json = changeag(params);
                        }
                        else{
                            json.insert("status",0);
                        }

                        QJsonDocument document;
                        document.setObject(json);
                        QByteArray byteArray = document.toJson(QJsonDocument::Compact);

                        //console
                        print("Callback Json to socketId "+QString::number(index)+":");
                        print(QString(byteArray));
                        connumfresh();

                        //send json to server,return callback json

                        this->sockets[index]->write(byteArray);
                        this->sockets[index]->waitForBytesWritten();
                    }
                }
        }
    }
}
QString server:: login (QString usr,QString pwd){
    if(this->users.empty()){
        return "0";
    }
    auto usroj = getuser(usr);
    if(!usroj){
       return "1";//User name doesn't exist;
    }
    else {

        QString md5;
        QByteArray md5_B = QCryptographicHash::hash ( pwd.toUtf8(), QCryptographicHash::Md5 );
        md5.append(md5_B.toHex());

        if(usroj->password.compare(md5)){
            return "2";//Wrong Password
        }
    }
    sessionadd(usroj);
    return sessions.key(usr);
}
QJsonObject server::login(QJsonObject params){
    QJsonObject json;

    if(this->users.empty()){
        json.insert("status",0);//Permission Denied
        return json;
    }
    auto usr = params.value("usr").toString();
    auto usroj = getuser(usr);
    if(!usroj){
        json.insert("status",1);//User name doesn't exist;
        return json;
    }
    else {
        auto pwd = params.value("pwd").toString();
        QString md5;
        QByteArray md5_B = QCryptographicHash::hash ( pwd.toUtf8(), QCryptographicHash::Md5 );
        md5.append(md5_B.toHex());

        if(usroj->password.compare(md5)){
            json.insert("status",2);//Wrong Password
            return json;
        }
    }
    sessionadd(usroj);
    json.insert("status",3);//Succeed
    json.insert("cookie",this->sessions.key(usr));
    return json;
}
//int server:: signup (QString usr, QString pwd,QString email){

//    if((signupusrcheck(usr)==1)&&pwdvalid(pwd)&&emailvalid(email)){

//        QString md5;
//        QByteArray md5_B = QCryptographicHash::hash ( pwd.toUtf8(), QCryptographicHash::Md5 );
//        md5.append(md5_B.toHex());
//        auto usroj = new userinfo(usr,md5,email);
//        users.push_back(*usroj);
//        return 1;
//    }
//    return 0;
//}
QJsonObject server::signup(QJsonObject params){
    QJsonObject json;
    auto usr =  params.value("usr").toString();
    auto pwd = params.value("pwd").toString();
    auto email = params.value("email").toString();

    if((signupusrcheck(usr)==1)&&pwdvalid(pwd)&&emailvalid(email)){

        QString md5;
        QByteArray md5_B = QCryptographicHash::hash ( pwd.toUtf8(), QCryptographicHash::Md5 );
        md5.append(md5_B.toHex());
        auto usroj = new userinfo(usr,md5,email);
        users.push_back(*usroj);
        json.insert("status",1);
        return json;
    }
    json.insert("status",0);
    return json;
}
QJsonObject server::signupusrcheck(QJsonObject params){
    auto usr = params.value("usr").toString();
    int status;
    if(getuser(usr)){
        status= 0;
    }
    else{
        if(usr_formvalid(usr)){
            status=1;//ok
        }
    else{
        status= 2;
        }
    }
    QJsonObject json;
    json.insert("status",status);
    return json;
}
QJsonObject server::signuppwdcheck(QJsonObject params){
    auto pwd = params.value("pwd").toString();
    int status;

    if(pwdvalid(pwd)){
        status =1;
    } else{
        status= 0;
    }
    QJsonObject json;
    json.insert("status",status);
    return json;
}
QJsonObject server::signupemailcheck(QJsonObject params){
    auto email = params.value("email").toString();
    int status;

    if(emailvalid(email)){
        status =1;
    } else{
        status= 0;
    }
    QJsonObject json;
    json.insert("status",status);
    return json;
}

//userinfo server::getdateuser(QString cookie){
//    auto usr = cookie2usr(cookie);
//    if (!usr)
//        return userinfo();
//    else
//        return *usr;
//}
QJsonObject server:: getdateuser(QJsonObject params){
    QJsonObject json;
    QString cookie = params.value("cookie").toString();
    auto usr = cookie2usr(cookie);
    if(!usr){
        json.insert("status",0);//usr doesn't exist
    }
    else{
        //No password in client
        userinfo u(*usr);
        u.password="";
        json.insert("content",QJsonValue(u.tojson()));
    }
    return json;
}

QMap<QString,QVector<pagelet>> server::gethomepagemap(){
    QMap<QString,QVector<pagelet>>  hp;
    auto pgit = this->boards.begin();
    while(pgit!=this->boards.end()){
        hp[pgit->name].empty();
        pgit++;
    }

    auto it = this->pagelets.begin();
    while(it!=this->pagelets.end()){
        hp[it->board_id].push_back(*it);
        it++;
    }
    return hp;
}
QJsonObject server ::gethomepage(){
    QMap<QString,QVector<pagelet>>  hp = gethomepagemap();

    QJsonObject json;
    //json.insert("status",1);
    QJsonObject content;

    auto it1 = hp.begin();
    while(it1!=hp.end()){
        QJsonArray board;

        auto it2 = it1.value().begin();
        while(it2!=it1.value().end()){

            board.push_back(QJsonValue(it2->tojson()));
            it2++;
        }
        content.insert(it1.key(),QJsonValue(board));
        it1++;
    }
    json.insert("content",QJsonValue(content));
    return json;
}
QVector<post> server::getposts(QString pageid){
    QVector<post> pos;
    auto it = this->posts.begin();
    while (it!=this->posts.end()) {
        if(!it->page_id.compare(pageid)){
            pos.push_back(*it);
        }
        it++;
    }
    return pos;
}
QJsonObject server::getposts(QJsonObject params)
{
    /*
     * {
     *    content:[
     *        {   //post},
     *        { //post},
     *
     *    ]
     *
     * }

    */
    QJsonObject json;
    QJsonArray content;

    auto page_id = params.value("page_id").toString();
    auto it = this->posts.begin();
    while (it!=this->posts.end()) {
        if(!it->page_id.compare(page_id)){
            content.append(QJsonValue(it->tojson()));
        }
        it++;
    }
    json.insert("content",QJsonValue(content));
    return json;
}
//QVector<board> server::getboards(){
//    return this->boards;
//}
QJsonObject server::getboards(){

    /*{
       *    content:[
       *        {   //board},
       *        {   //board},
       *
       *    ]
       *
       * }
*/
    QJsonObject json;
    QJsonArray content;

    auto it = this->boards.begin();
    while (it!=this->boards.end()) {
        content.append(QJsonValue(it->tojson()));
        it++;
    }
    json.insert("content",QJsonValue(content));
    return json;
}
//QVector<userinfo> server::getuserlist(QString cookie){
//    auto root = cookie2usr(cookie);
//    if(!root||root->right!=3)
//        return *(new QVector<userinfo>);

//    return users;
//}
QJsonObject server:: getuserlist(QJsonObject params){


    /*{
     *    status :1
     *    content:[
     *        {   //user},
     *        {   //user},
     *
     *    ]
     *
     * }
     *
     * or
     *
     * {
     *   status:0
     * }
*/
    QJsonObject json;
    auto root = cookie2usr(params.value("cookie").toString());
    if(!root||root->right!=3)
        json.insert("status",0);// only root can get all user info;
    else{
        json.insert("status",1);
        QJsonArray content;

        auto it = this->users.begin();
        while (it!=this->users.end()) {
            content.append(QJsonValue(it->tojson()));
            it++;
        }
        json.insert("content",QJsonValue(content));
    }

    return json;
}
//bool server:: logout (QString cookie){
//    auto usr = cookie2usr(cookie);
//    if(!usr)
//        return 0;
//    return this->sessions.remove(this->sessions.key(usr->id));
//}
QJsonObject server::logout(QJsonObject params){
   QJsonObject json;
   auto usr = cookie2usr(params.value("cookie").toString());
   if(!usr){
       json.insert("status",0);
       return json;
   }
   json.insert("status",this->sessions.remove(this->sessions.key(usr->id)));
   return json;
}
//bool server::deleteusr(QString usr,QString cookie){
//    auto root = cookie2usr(cookie);
//    if(!root||root->right!=3)
//        return 0;
//    auto it = this->users.begin();
//    while(it->id.compare(usr)&&it!=this->users.end()) it++;
//    if(it!=this->users.end()){

//        this->users.remove(it-this->users.begin());
//        return 1;
//    }
//    return 0;
//}
QJsonObject server::deleteusr(QJsonObject params){
    QJsonObject json;
    auto root = cookie2usr(params.value("cookie").toString());
    if(!root||root->right!=3)
        json.insert("status",0);// only root can get all user info;
    else{
        auto usr = params.value("usr").toString();

        auto it = this->users.begin();
        while(it->id.compare(usr)&&it!=this->users.end()) it++;
        if(it!=this->users.end()){
            this->users.remove(it-this->users.begin());
            json.insert("status",1);
            return  json;
        }
        json.insert("status",0);
        return  json;

    }

    return json;
}

//k
int server::uploadpost(post p,QString cookie){
    auto usr = cookie2usr(cookie);
    if(!usr)
        return 0;
    p.usr_id = usr->id;
    if(!postvalid(p))
        return 1;
    p.time = QTime::currentTime();
    p.post_id.append(QCryptographicHash::hash ((p.page_id+p.time.toString()+p.usr_id).toUtf8(), QCryptographicHash::Md5 ).toHex());
    this->posts.push_back(p);
    return 2;
}
QJsonObject server::uploadpost(QJsonObject params){
    QJsonObject json;
    auto usr = cookie2usr(params.value("cookie").toString());
    if(!usr){
        json.insert("status",0);//usr doesn't exist
        return json;
    }
    post p(params.value("post").toObject());
    p.usr_id = usr->id;
    if(!postvalid(p)){
       json.insert("status",1);
       return json;
    }
    p.time = QTime::currentTime();
    p.post_id.append(QCryptographicHash::hash ((p.page_id+p.time.toString()+p.usr_id).toUtf8(), QCryptographicHash::Md5 ).toHex());
    this->posts.push_back(p);
    json.insert("status",2);
    return  json;
}

//bool server::changevote(QString post_id,QString cookie,bool up){
//    auto usr = cookie2usr(cookie);
//    if(!usr)
//        return 0;
//    for ( int i= 0; i< this->posts.length();i++){
//        if(!post_id.compare(this->posts[i].post_id)){
//            if(!usr->right)// guest.right == 0
//                return 0;//refuse to changepost
//            if(up) {
//                this->posts[i].upvotes++;
//            }
//            else{
//                this->posts[i].downvotes++;
//            }
//            return 1;
//        }
//    }
//    return 0;
//}
QJsonObject server::changevote(QJsonObject params){
    QJsonObject json;
    auto usr = cookie2usr(params.value("cookie").toString());
    if(!usr){
        json.insert("status",0);//usr doesn't exist
        return json;
    }
    QString post_id(params.value("post_id").toString());
    bool up = params.value("up").toBool();
    for ( int i= 0; i< this->posts.length();i++){
        if(!post_id.compare(this->posts[i].post_id)){
            if(!usr->right){// guest.right == 0
                json.insert("status",0);//refuse to changepost
                return json;
            }
            if(up) {
                this->posts[i].upvotes++;
            }
            else{
                this->posts[i].downvotes++;
            }
            json.insert("status",1);
            return  json;
        }
    }
    json.insert("status",0);
    return  json;
}

//int server::createpage(pagelet pgl,post p,QString cookie){
//    auto usr = cookie2usr(cookie);
//    if(!usr)
//        return 0;
//    if (!titlevalid(pgl.title)){
//        return 1;
//    }
//    if (!postvalid(p.content)){
//        return 2;
//    }
//    pgl.starter_id=usr->id;
//    pgl.time = QTime::currentTime();
//    pgl.pagelet_id=(QCryptographicHash::hash ((pgl.starter_id+pgl.time.toString()+pgl.board_id).toUtf8(), QCryptographicHash::Md5 ).toHex());
//    this->pagelets.push_back(pgl);
//    p.page_id=pgl.pagelet_id;
//    uploadpost(p,cookie);
//    return 3;
//}

QJsonObject server::createpage(QJsonObject params){
    QJsonObject json;
    QString cookie = params.value("cookie").toString();
    auto usr = cookie2usr(cookie);
    if(!usr){
        json.insert("status",0);//usr doesn't exist
        return json;
    }
    pagelet pgl(params.value("pagelet").toObject());
    if (!titlevalid(pgl.title)){
        json.insert("status",1);//invalid title
        return json;
    }
    post p(params.value("post").toObject());
    if (p.content.length()>2000||p.content.length()==0){
        json.insert("status",2);//invalid post
        return json;
    }
    pgl.starter_id=usr->id;
    pgl.time = QTime::currentTime();
    pgl.pagelet_id=(QCryptographicHash::hash ((pgl.starter_id+pgl.time.toString()+pgl.board_id).toUtf8(), QCryptographicHash::Md5 ).toHex());
    this->pagelets.push_back(pgl);
    p.page_id=pgl.pagelet_id;
    uploadpost(p,cookie);
    json.insert("status",3);
    return json;
}

//bool server::deletepage(QString pageid,QString cookie){
//    auto usr = cookie2usr(cookie);
//    if(!usr)
//        return 0;
//    auto it = this->pagelets.begin();
//    while(it!=this->pagelets.end()){
//        if(!it->pagelet_id.compare(pageid)){
//            //root , board_manger, or author
//            if(usr->right==3||!it->starter_id.compare(usr->id)||!getboard(it->board_id)->manager_id.compare(usr->id)){
//                //clear the pagelet
//                it = this->pagelets.erase(it);
//                auto it1 = this->posts.begin();
//                while(it1!=this->posts.begin()){
//                    if(!it1->page_id.compare(pageid)){
//                        it1 = this->posts.erase(it1);
//                    }
//                    it1++;
//                }
//                //clear the pagelet's posts
//                return 1;
//            }
//            else {
//                return 0;
//            }
//        }
//       it++;
//    }
//    return 0;
//}

QJsonObject server ::deletepage(QJsonObject params){
    QJsonObject json;
    QString cookie = params.value("cookie").toString();
    auto usr = cookie2usr(cookie);
    if(!usr){
        json.insert("status",0);//usr doesn't exist
        return json;
    }
    QString page_id = params.value("page_id").toString();

    auto it = this->pagelets.begin();
    while(it!=this->pagelets.end()){
        if(!it->pagelet_id.compare(page_id)){
            //root , board_manger, or author
            if(usr->right==3||!getboard(it->board_id)->manager_id.compare(usr->id)){

                //clear the pagelet's posts
                for (int i = 0;i<this->posts.length();i++){
                    if(!this->posts[i].page_id.compare(page_id)){
                        this->posts.remove(i);
                        i--;
                    }
                }
//                auto it1 = this->posts.begin();
//                while(it1!=this->posts.end()){
//                    if(!it1->page_id.compare(page_id)){

//                    }
//                    it1++;
//                }


                //clear the pagelet
                this->pagelets.erase(it);
                json.insert("status",1);
                return json;
            }
            else if(!it->starter_id.compare(usr->id)){
                    if((getposts(page_id).size()>1)){
                    //can't
                    json.insert("status",2);
                    return json;
                }
                else{
                //clear the pagelet's posts
                for (int i = 0;i<this->posts.length();i++){
                    if(!this->posts[i].page_id.compare(page_id)){
                            this->posts.remove(i);
                            i--;
                    }
                }

//                    auto it1 = this->posts.begin();
//                    while(it1!=this->posts.end()){
//                        if(!it1->page_id.compare(page_id)){
//                            it1 = this->posts.erase(it1);
//                        }
//                        it1++;
//                    }
                    //clear the pagelet's posts
                    json.insert("status",1);
                    this->pagelets.erase(it);
                    return json;
                }
            }
            else {
                json.insert("status",0);
                return json;
            }
        }
       it++;
    }
    json.insert("status",0);
    return json;
}
//int server::changebm(QString bo,QString usr,QString cookie){
//    auto root = cookie2usr(cookie);
//    if(!root)
//        return 0;

//    auto info  = getuser(usr);
//    if (info->right<1 || info->right>2)
//        return 0;
//    if (info->right ==2 ){
//        auto it = this->boards.begin();
//        while(it!= this->boards.end()){
//            if(!it->manager_id.compare(info->id)){
//                it->manager_id.clear();
//                //break;
//            }
//            it++;
//        }
//    }
//    auto it = this->boards.begin();
//    while(it!= this->boards.end()){
//        if(!it->name.compare(bo)){
//            //level down the old to normal
//            setusrright(it->manager_id,cookie,1);
//            //level up
//            it->manager_id=usr;
//            setusrright(usr,cookie,2);
//            break;
//        }
//        it++;
//    }
//    if(it==this->boards.end()){
//        QRegExp rx;
//        rx.setPatternSyntax(QRegExp::RegExp);
//        rx.setCaseSensitivity(Qt::CaseSensitive);
//        rx.setPattern(QString("^.{1,32}$"));
//        if(!rx.exactMatch(bo))
//            return 1;
//        board b;
//        b.manager_id = usr;
//        b.name = bo;
//        this->boards.push_back(b);

//        setusrright(usr,cookie,2);

//    }
//    return 2;
//}
QJsonObject server::changebm(QJsonObject params){
    QJsonObject json;
    QString cookie = params.value("cookie").toString();
    QString usr = params.value("usr").toString();
    QString bo  = params.value("board").toString();
    auto root = cookie2usr(cookie);
    if(!root){
        json.insert("status",0);//Isn't root
        return json;
    }
    auto info  = getuser(usr);

    if (info->right<1 || info->right>2){
        json.insert("status",0);//usr doesn't exist
        return json;
    }
    if (info->right ==2 ){
        auto it = this->boards.begin();
        while(it!= this->boards.end()){
            if(!it->manager_id.compare(info->id)){
                it->manager_id.clear();
            }
            it++;
        }
    }
    auto it = this->boards.begin();
    while(it!= this->boards.end()){
        if(!it->name.compare(bo)){
            //level down the old to normal
            setusrright(it->manager_id,cookie,1);
            //level up
            it->manager_id=usr;
            setusrright(usr,cookie,2);
            break;
        }
        it++;
    }
    if(it==this->boards.end()){
        QRegExp rx;
        rx.setPatternSyntax(QRegExp::RegExp);
        rx.setCaseSensitivity(Qt::CaseSensitive);
        rx.setPattern(QString("^.{1,32}$"));
        if(!rx.exactMatch(bo)){
            json.insert("status",1);
            return json;
        }
        board b;
        b.manager_id = usr;
        b.name = bo;
        this->boards.push_back(b);

        setusrright(usr,cookie,2);

    }
    json.insert("status",2);
    return  json;
}


//int server::changepw(QString oldpwd,QString newpwd,QString cookie){
//    auto usr = cookie2usr(cookie);
//    if(!usr)
//        return  0;
//    QString oldmd5= (QCryptographicHash::hash ( oldpwd.toUtf8(), QCryptographicHash::Md5 )).toHex();

//    if(oldmd5.compare(usr->password)){//incorrect oldpwd
//        return 1;
//    }
//    else if(!pwdvalid(newpwd)){//invalid newpassword
//        return 2;
//    }
//    else {
//        QString newmd5= (QCryptographicHash::hash ( newpwd.toUtf8(), QCryptographicHash::Md5 )).toHex();
//        usr->password=newmd5;
//        return 3;
//    }
//}
QJsonObject server ::changepw(QJsonObject params){

    QJsonObject json;
    QString cookie = params.value("cookie").toString();
    QString oldpwd = params.value("oldpwd").toString();
    QString newpwd = params.value("newpwd").toString();
    QString bo  = params.value("board").toString();
    auto usr = cookie2usr(cookie);
    if(!usr){
        json.insert("status",0);//usr doesn't exist
        return json;
    }

    QString oldmd5= (QCryptographicHash::hash ( oldpwd.toUtf8(), QCryptographicHash::Md5 )).toHex();

    if(oldmd5.compare(usr->password)){//incorrect oldpwd
        json.insert("status",1);//usr doesn't exist
        return json;
    }
    else if(!pwdvalid(newpwd)){//invalid newpassword
        json.insert("status",2);//usr doesn't exist
        return json;
    }
    else {
        QString newmd5= (QCryptographicHash::hash ( newpwd.toUtf8(), QCryptographicHash::Md5 )).toHex();
        usr->password=newmd5;
        json.insert("status",3);//usr doesn't exist
        return json;
    }
}
//int server::changeag(QDate date ,int gender,QString cookie)//change age and gender
//{
//    auto usr = cookie2usr(cookie);
//    if(!usr)
//        return  0;
//    usr->age=date;
//    usr->gender = gender;
//    return 1;
//}
QJsonObject server::changeag(QJsonObject params){
    QJsonObject json;
    QString cookie = params.value("cookie").toString();
    QDate date = QDate::fromString(params.value("date").toString());
    int gender = params.value("gender").toInt();
    auto usr = cookie2usr(cookie);
    if(!usr){
        json.insert("status",0);//usr doesn't exist
        return json;
    }
    usr->age=date;
    usr->gender = gender;
    json.insert("status",1);
    return json;
}

void server::dataaddusr(userinfo &u){

    dbq->prepare("Insert INTO users (id,password,right,email,level,age,gender)"
                 "VALUES (:id,:password,:right,:email,:level,:age,:gender);");
    dbq->bindValue(":id",u.id);
    dbq->bindValue(":password",u.password);
    dbq->bindValue(":right",u.right);
    dbq->bindValue(":email",u.email);
    dbq->bindValue(":level",u.level);
    dbq->bindValue(":age",u.age);
    dbq->bindValue(":gender",u.gender);

    if(!dbq->exec()) {qDebug()<<"replace users error! :"<<dbq->lastError();}
    else{qDebug()<<"Maybe I did it!";}
}

server * operator<< (server * s,userinfo & u ){
    s->dataaddusr(u);
    return s;
}

