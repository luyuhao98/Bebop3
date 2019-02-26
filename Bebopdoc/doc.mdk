Title         : C++学习论坛系统最终版本
Author        : 卢昱昊
Logo          : True
Package : [UTF8]ctex

[TITLE]
[TOC]

# Feature
1. 采用C++面向对象编程,并充分发扬了面向对象编程的诸多优势,见[#oop]
2. 实现了用户登录,匿名登录,注册,注销,查看个人信息,修改个人信息,刷新界面,浏览帖子,访问帖子,删帖,跟帖,版主权限修改,用户管理等诸多功能
3. 采用MVC设计模式,实现了客户端/服务器(C/S)处理模型
4. server为服务程序,client为客户端程序,在本地模拟,通过`tcpsocket`进行端口通信.**支持多用户并发执行所有２中提到的功能**
5. 引入cookie/session机制,极大地提高了请求的安全性,提高了系统的可用性
6. **仿浏览器式GUI,操作便捷,交互友好**
7. 同时**采用磁盘数据库**与**内存数据库**,同时保证数据存储的安全性与访问的高效性

# 开发环境
* Ubuntu18.04
* QT 5.9

# 功能实现 {# funcs}

## 基本单位定义

### 用户(uesrinfo)

一个操作个体,具有用户id,密码,权限,email等个人信息,是请求的基本单位.

每次用户登录,服务器都将在*在线用户队列*中给用户生成分配session,并返回cookie到本地作为访问服务器的凭证,确保数据访问的安全性

### 帖子(post)

专指一个**楼层**,包括帖子id,贴页id(见[#pagelet]),正文,发帖者,赞数,踩数等信息

### 贴页(pagelet) {#pagelet}

一个**贴页**里有许多许多帖子,**贴页**相当于一个问题,一个贴页包括贴页id,标题,发起者,所属版块等信息.

一个**贴页在创建时必须要同时发布第一条帖子**,发帖者即为我们常说的楼主,第一条帖子内容为*贴页标题的补充解释内容*.

### 版块(board)

一个版块内有许多的**贴页**,版块包括版块名,版主id.关于版主,有以下两点限制:
1. 一个版块只有一个版主
2. 一个用户只能为至多一个版块的版主

### 客户端

客户端是与服务端建立tcpsocket连接的基本单位.客户端类`client`采用单例模式,保证一次客户端软件打开只创建一个客户端类,只创建一次连接.

一台机器上可以运行多个客户端

客户端类`client`主要负责:
        * 创建链接: 连接服务端
        * 中间层: 所有前端涉及数据请求操作,统一交由客户端接口与服务端进行交互
        * 解析/编码请求: 利用json作为数据与服务端交互,对收到的二进制串进行json解析,对发送的数据编码为json. 
        * 存储本地数据:如cookie,用户信息等


> 注:注销时重启客户端

### 服务端
服务端只需要运行一个,服务端类`server`采用单例模式创建,保证一次运行只需要创建一个服务端类,只需要一次初始化.节约了时间空间,避免反复验证数据库与反复创建实例开销.

服务端每与一个客户端相连,就将其`tcpsocket`放入连接容器,分配一个socketid并与消息事件绑定.当不同的客户端发送请求,根据qt自带的信号槽队列,轮询执行操作(*中间操作*).**保证服务端无冲突正确处理批量操作**,socketid作为*中间操作*的参数传入,中间操作根据*统一格式的请求信息*调用具体操作,增强了通用性,与易扩展性,**实现多客户端执行所有通用操作**

服务端类`server`主要负责:
        * 数据的存储: 所有数据存储在服务端,本地只存储部分数据
        * 权限鉴别: 使用session/cookie机制,**所有涉及权限的请求必须先核对权限,再执行操作,操作合法则修改服务端数据,反馈客户端执行结果**.在一定程度上,防御了伪造请求越权操作.
        * 数据逻辑: 判断请求合法性,增添删除修改数据等实体功能
        * 解析/编码请求: 利用json作为数据与客户端交互,对收到的二进制串进行json解析,对发送的数据编码为json. 

## 基本功能 

### 用户权限
系统面向四类用户:游客,普通用户,版主,管理员,主要区别如下
        * 游客：只有浏览权限，任何提交操作无效
        * 普通用户: 正常登录浏览注销,正常发帖,删除自己帖子,跟帖回复,修改个人信息等
        * 版主:在普通用户基础上,有权限任意删除自家版块的帖子
        * 管理员:在普通用户基础上,有权删除任何帖子,有权限删除用户,更新用户权限,即任命版主,创建新版块等

### 注册
输入用户名,密码,重复密码,email即可注册.详细请见[#regcheck]


### 登录

非游客用户可以使用用户名密码登录.登录验证请求发送请求到服务端,返回验证结果:
        * 若登录失败,返回错误类型,解析显示.如用户名不存在,密码错误等
        * 若登录成功,返回cookie,登录首页,下载用户信息.下载的用户信息中不存在用户的密码

### 游客登录
游客状态登录系统,菜单栏只有注销操作.在注册或登录窗口,点击退出会提示"是否选择以游客身份登入",若选择yes则游客登录.

### 页
主页,帖子页和用户列表页的父类.分为*顶栏*和*正文区*两个部分,详见特色功能[#fatherpage]

> 注: 以下各子类页(主页,帖子页,用户列表页),默认讨论正文区

### 主页
论坛主页左侧显示版块,可以选中.右侧显示选中板块下的所有帖页.每次打开主页时,只下载版块列表与版块下的贴页列表.不下载具体每个帖子的内容

### 注销操作
任意用户退出当前登录状态,重新登录

### 查看个人信息
非游客可查看个人信息,如出生日期,性别,email等

### 修改个人信息
非游客可以修改出生日期,性别,密码等信息.信息有格式限制.若格式非法,则返回错误代码

### 论坛版块
论坛由多个版块组成,每个版块有唯一的版主,板块下有对应帖页的标题．

### 浏览帖子
点击主页右侧帖页，弹出新的一页显示整个帖子楼层，称该页为***帖子页***.这一过程中,下载点击贴页中所有的帖子.

### 发送帖子

点击主页右侧post键,点击输入新帖子的标题,以及一楼内容,点击确定提交.服务器鉴定权限与格式判断:
        * 若无此用户或者内容为空,则会返回状态0,解析状态显示错误.
        * 若判断成功,返回状态0,提示成功post

### 删除帖子
点击主页右侧delete键,进入多选模式,选中删除.删除条件为以下:
1. 游客无权限删帖子
2. 普通用户可以删除自己发布的且还没有评论的帖子
3. 版主可以删除自家版块的帖子
4. 管理员可以删除所有帖子

### 浏览帖子

点击主页帖子,添加**帖子页**并自动跳转.帖子分为三个部分:
1. 标题:显示在最顶端
2. 帖子以及跟帖: 显示在中间大部分
3. 评论框: 显示在最底端

### 帖子

帖子由以下几部分组成:

1. 发帖者用户名
2. 帖子正文: 靠上对齐
3. 帖子状态栏:显示发帖时间
4. 赞同(upvotes)与反对(downvotes)按钮:显示赞同数与反对数
5. 评论(comment)按钮: 点击后,**评论框正文后添加`@<发帖者用户名>`**

### 评论

评论由以下部分组成:

1. 文本框:点击文本框编辑评论,字数限制1~2000
2. 清除按钮(clear):点击清空评论
3. 发帖按钮(post):发送帖子,若反馈符合规定(字数限制等),显示成功并刷新页面,否则在提示区提示错误
4. 提示区:默认隐藏,若出现问题,则显示错误所在

### 查看用户列表
root(管理员)有权限查看用户列表.点击`user list`,打开用户列表页.列表显示:

        * 用户名
        * 用户权限 :Normal,Board manager,Root
        * 备注: 若为某版版主,则显示版块名

管理员可以选中任一用户,选则执行以下功能:
        
        * 删除用户: 不能删除自己(root唯一)
        * 升级权限(任命版主): 详见特色功能[#levelup]



## 特色功能

### 注册检查 {#regcheck}

注册时有以下限制条件:
1. 用户名由大小写字母,阿拉伯数字及下划线构成,长度为6-20位,且未注册过
2. 密码最短8位,至少有一个大写字母,一个小写字母和一个数字
3. 正确重复密码
4. email需满足类似`xxx@abc.com`的格式

提交表单时,若以上出现问题,则会在输入框附近,对用户进行提示


### 游客登录方式{#guestin}
登录或注册窗口点击右上角退出,显示下图:

选择No则直接退出程序,选择Yes则以游客方式登录,Cancel为取消

### 页 {#fatherpage}

前端类为一个父类,整体由两个部分组成:

1. 顶栏
2. 正文区

顶栏由三个部分组成:

1. Bebop: logo,点击新建并跳转到主页
2. 刷新按钮: 点击刷新整页.刷新函数refreshpage()为一个虚函数,各子类实现多态
3. 用户按钮: 默认显示 "Hi,\<用户名\>".点击展开用户功能列表:
        * 游客:只有注销
        * 普通用户与版主: 可以查看个人资料,修改个人资料,注销
        * 管理员:在普通用户基础上,添加"进入用户列表页"功能

### 仿浏览器前端
模仿浏览器,包括界面风格,交互方式,乃至请求方式,内存管理.符合当今人的使用操作习惯
        
        * 界面风格:
                - 登录注册界面仿照*Github*,**附加友好的提示信息**引导用户注册登录.
                - 主界面UI**简洁而不简单**,便于信息的传播.
        * 交互方式:
                - 采用的**tab页式前端**方便人们在不同种类的页面间切换
                - 采用顶栏设计,左侧logo首页链接,右侧用户下拉菜单按钮,配合页面刷新按键.功能强大,清晰而友好
        * 请求方式:
                - 前端只负责数据的采集,显示返回,逻辑层全部交给`client`来与`server`交互,充分解耦
        * 内存管理:
                - 每次请求只请求当前页面所需信息,节约内存,提高效率.
                - 便于与服务器端同步与更新

### 创建版块
更新版主时可以选择`<New Board>`创建新的版块并成为新版块版主,详见[#levelup]

### 升级权限 {#levelup}

可以提升普通用户或版主的权限:
        * 一个版块最多只有一个版主(可以没有版主),一个用户只能为一个版块的版主
        * 普通用户可以成为某版块版主.若有原版主,原版主变为普通用户
        * 版主可以切换为另一版块版主,原版块失去版主,另一版块原版主成为普通用户
        * 可以新建新版块而不选择已有版块.则发送创建版块请求:
                - 若新建版块名称为已有版块,则已有版块版主为选择用户,若存在原版主替换规则同上
                - 判断新版块名称是否满足要求:包括长度1-32,有效字符等(可选).不成功则返回错误代码

### 刷新界面

1. 刷新函数为tab(页)类的虚函数,由不同子类页进行泛化.
2. 位于顶栏,点击即可刷新本页面,用户主动与服务端同步.(非主动如发帖后,第一次打开页面时自动与服务端同步).
3. 每次刷新只获取当前页面的数据,节约开销.

### 多用户
1. 采用**C/S架构**,实现多用户模式.
2. 采用**session/cookie机制**,保证访问的安全性,提高了可用性
3. 利用qt**信号map映射**与**信号槽内部队列**,实现了请求队列,避免了访存冲突.
4. 对于目前规模的网站(平均在线不到1000人),并发的可能性极低,并且即使并发,以目前的数据规模,单线程队列完全可以胜任.结合目前的需求与数据库设计,为了降低工程维护的复杂性,不采用多线程机制.


# 设计模式优点及其体现

## 面向对象特征体现 {#oop}

### 封装性
封装性很重要，它可以避免外部对象修改对象内部的状态，从而引起对象本身的稳定性，因此在代码编写过程中，要尽量考虑到对象的每个属性，不需要暴露的，尽量不要暴露。

### 继承
继承性，使不同的类，有相同的方法，这样可以最大程度地重用代码。


### 多态
多态使得我们可以使用相同的方法处理不同对象的行为：我们可以使用相同的代码处理不同的类型的对象，只要它们继承和实现了相同的类型。


## C/S架构

### 通信实现

* 借助`QTcpserver`实现服务端端口监听
* 借助`QTcpsocket`实现端与端间通信
* 通信信息:`Json object`转成的`bit`串

### 通信格式{#answer}

客户端请求格式
```
{
        'func': '<函数名称>'
        'params':{
                <参数表>
        }
}
```

服务端应答格式 
```
{
        'status': '整型状态号'
        'content':{
                <内容>
        }
}
```

### 多用户实现

1. 服务端监听某端口,客户端向该端口发送请求
2. 服务端存在一个`QTcpsocket`容器,每`listen`到一个`QTcpsocket`的新连接,将其放入容器中.
3. 每将一个`QTcpsocket`放入容器中时,对其指定一个`socketId`,并通过QT信号槽map机制,将`QTcpsocket`的*请求信号*与*断开链接信号*各自对应于以`socketId`为参数的*请求信号处理槽*与*断开链接处理槽*,保证一一对应关系
4. 访问的互斥性通过*QT信号队列机制*实现.即使高并发,高访问量,也不会出现访问的冲突.保证了多用户模式的可用性
5. 对于用户个体,采用session/cookie机制,实现了权限校验,提高了访问的安全性,处理了用户登录的唯一性(用户登录状态未退出,二次登录,前一次cookiee过期)

## 单例模式
确保系统中某个对象的唯一性,提高了系统的灵活性,节约内存开销.

### 单例模式的实现模型:

```cpp
class singleton{

private:
        singleton(); //构造函数
        singleton(singleton const&);//拷贝函数不实现,也不许继承实现
        void operator=(singleton const&);//等号重载不实现,也不许继承
public :
        //类函数ins(),返回静态对象instance
        //每次只能通过singleton::ins()来调用singleton唯一的实例.
        static singleton& ins(){
                static singleton instance;
                return instance;
        }
};
```


采用单例模式的类如下:

client 客户端控制类
        ~ 无论有多少个前端对象,涉及到请求与应答,都来调用唯一的client
server 服务端控制类
        ~ 无论多少个用户在线,都是由server来执行操作.用户只是将请求提交给server,server来执行实际的操作.

## session/cookie机制

### 使用理由:

业务逻辑层与数据我们都存放在服务端,称之为后端,用户通过利用Tcpsocket从前端向后端发送**请求**来支配数据.

但是**请求**不一定是合法的.比如普通用户发送超过本身权限的请求(如删除他人帖子),更为严重的是根据网络模型,Tcpserver请求是可以**伪造**并发送的..

采用及时生成的cookie,极大地降低了请求的可伪造性,提高了安全性

### 实现机制与优点

1. 每次一个用户成功login,则根据`<用户id><密码><当前时间>`md5-hash为一个32位的字符串str.
2. 将`(str,<用户id>)`存入session表中(Map),并将str作为返回content项中(详见[#answer])的cookie项,返回给客户端`client`
3. `clien`类成员cookie保存返回cookie.每次调用到需要鉴别权限的方法时,都要将cookie放入params发送json.
4. 服务端收到cookie后,去session表中查询用户id.若存在则得到,若不存在则反馈status=0,客户端表现为"Permission Denied"
5.若用户存在,则鉴别权限.如果权限不够,返回status=0,客户端"Permission Denied" .用户的权限与信息,不能作为请求的参数,只能由后端来确认.
6. 每次存入session时,先要查找是否用户名已经存在(该用户已经登录),若已经存在,则原session过期,生成新的session存入.这样保证了用户登录的唯一性.

## 磁盘数据库/内存数据库模型 {#database}
现代网站架构中,缓存数据库如Redis与磁盘数据库如mysql等往往同时存在,本论坛设计中,也采用如此架构.其优势在于**尽量减少IO次数,提高处理请求的速度**

采用了*容器*与*SQLite*分别作为内存数据库与磁盘数据库.
>  虽然SQLite有内存与磁盘两种模式,对于QT,其对SQLite的操作依然是基于文件系统的.

调用数据库流程如下:

1. 服务器开启时,将`SQlite`中数据读入*容器*中
2. 用户日常请求,只修改*容器*数据
3. 服务器定期将*容器*数据同步到`SQlite`上

数据库存储如下四表(对应四种基本数据结构):
1. 用户信息表`users`:`id,password,right,email,level,age,gender`
2. 帖子表`posts`:`post_id , page_id ,usr_id,content,ttime,upvotes, downvotes`,读取时按`ttime`排序
3. 贴页表`pagelets`:`pagelet_id , board_id,starter_id ,title ,ttime`,同读取时按`ttime`排序
4. 版块表`boards`:`name , manager_id`

# 具体实现
以下为代码具体实现的部分

## 数据结构{#datastruct}

以下类均为实体类,成员方法均为public:

1. userinfo 用户信息类
2. post 帖子类
3. pagelet 贴页类
4. board 版块类

**无论是客户端还是服务端，都用以上四个类**

### 相关文件
```
pagelet.h
board.h
post.h
userinfo.h
pagelet.cpp
board.cpp
post.cpp
userinfo.cpp
```


### userinfo 用户信息类


userinfo();
        ~ 构造函数
userinfo(QString id,QString password,QString email);
        ~ 构造函数重载,登录时使用
userinfo(QString id,QString password,int right,QString email,int level,QDate age,int gender);
        ~ 构造函数重载,载入数据库时使用
userinfo(QJsonObject json);
        ~ 构造函数重载,jsonobject->userinfo
QJsonObject tojson();
        ~ userinfo转jsonobject
    
QString id;
        ~ 用户名,唯一
QString password
        ~ 用户密码,存md5加密后的32位数字
int right; 
        ~ 用户权限 游客(default): 0 ,普通用户:1,版主:2,管理员:3 
QString email;
        ~ 用户邮箱地址
QDate age;
        ~ 用户生日
int gender;
        ~ 用户性别
int level;
        ~ 用户等级


### post 帖子类
post();
        ~ 构造函数
post(QString post_id,QString page_id,QString usr_id,QString content,QTime time,long long upvotes,long long downvotes;
        ~ 构造函数重载
post(QString post_id,QString page_id,QString usr_id,QString content);
        ~ 构造函数重载
post(QJsonObject);
        ~ 构造函数重载,json->post
QJsonObject tojson();
        ~ post->json

QString post_id;
        ~ 帖子id,在服务器端通过发帖人,发帖时间,所属贴页id组成字符串经过 md5 hash 生成编码32位
QString page_id;
        ~ 所属贴页id，同为md5 hash 编码32位
QString usr_id;
        ~ 发帖者id
QString content;
        ~ 发帖内容
QTime time;
        ~ 发帖时间
long long upvotes;
        ~ 赞同数
long long downvotes;
        ~ 反对数

### pagelet 贴页类

贴页定义及作用详见[#pagelet]

pagelet();
        ~ 构造函数
pagelet(QString pagelet_id,QString board_id,QString starter_id,QString title,QTime time);
        ~ 构造函数重载
pagelet(QJsonObject json);
        ~ 构造函数重载  json->pagelet
QJsonObject tojson();
        ~ pagelet->json

QString pagelet_id;
        ~ 贴页id,在服务器端通过贴页发起者,发帖时间,所属版块id组成字符串经过 md5 hash 生成编码32位
QString board_id;
        ~ 版块id
QString starter_id;
        ~ 贴页发起者
QString title;
        ~ 贴页标题
QTime time;
        ~ 发帖时间

### board
board();
        ~ 构造函数
board(QString,QString);
        ~ 构造函数重载
board(QJsonObject);
        ~ 构造函数重载,json->board
QJsonObject tojson();
        ~ board->json

QString name;
        ~ 版块id,即版块id
QString manager_id;
        ~ 版主id



## 客户端
客户端由三部分组成
        * 数据结构，见[#datastruct]
        * 前端类,负责信息的显示与收集
        * 控制类`client`,负责与服务端进行交互


### 前端
前端涉及各类如下:

loginUi
        ~登录Ui类
signupUi
        ~注册Ui类
mainwin
        ~主窗口Ui类
tabUi
        ~页Ui类
homepageUi
        ~主页Ui类
hpmainUi
        ~主页正文Ui类
pageUi
        ~帖页Ui类
postUi
        ~贴字Ui类
commentpostUi
        ~评论框Ui类
userlistUi
        ~用户列表页Ui类
usrlsitmainUi
        ~用户列表正文去Ui类
promotebmUi
        ~更改权限Ui类
settingUi
        ~更改用户信息Ui类

### 前端的继承与多态{#front}

在使用Qt的过程中,前端的各种类间的调用往往比后端的逻辑更为复杂与繁琐.于是,将面向对象的方法运用与前端,极大地提高了开发前端的效率,提高了程序的可扩展性.

在诸多的前端类中,**tabUi类**格外的重要.`tabUi`类为所有页类的父类.`mainwin`类对`tabUi`类的添加与管理,实现了浏览器式的前端效果

`tabUi`的成员,从宏观上讲实现了顶部黑色条的状态栏及其功能,并规划好底部的正文区.其他子类页,只需要**继承**tabUi,为其正文区添加内容即可.

`tabUi`留了一个虚函数`refresh`实现多态:各个子类各自实现各自的刷新页面功能.

### 前端类用户友好体现

1. 浏览器式界面
2. 所有的输入框均有后端验证,并给予用户以提示
3. 支持刷新功能,可以不用重新关闭打开即可刷新数据.
4. 支持批量功能,可以批量删除选中.支持Yes to All,No to all
5. 评论区支持快速`@`某用户功能
6. 风格模仿Github,界面清晰流畅,功能便捷齐全.

### client控制类实现

private:

userinfo usr;
        ~用户信息, 本地不保存密码
QMap\<QString,QVector\<pagelet>> homepage;
        ~主页信息
QString cookie;
        ~存储cookie
QTcpSocket *tcp;
        ~链接

public:

userinfo * getinfo();
        ~ 获取用户信息
QMap\<QString,QVector\<pagelet>> *gethomepage();
        ~ 获取主页
bool guestin();
        ~ 游客登录
int login(QString,QString);
        ~ 登录
int  signup (QString usr, QString, QString;
        ~ 注册
int signupusrcheck(QString);
        ~ 注册时用户名验证
int signupemailcheck(QString email);
        ~ 注册时邮箱验证
int signuppwdcheck(QString pwd);
        ~ 注册时密码验证
void updatehomepage();
        ~ 从服务端更新首页
bool updateuser();
        ~ 从服务端更新用户信息
QVector\<post> getposts(QString);
        ~ 下载帖子
QVector\<board> getboards();
        ~ 下载版块信息
QVector\<userinfo> getuserlist();
        ~ 下载用户列表
int  logout ();
        ~ 注销
bool deleteusr(QString);
        ~ 删除用户
int uploadpost(post p);
        ~ 登录
bool changevote(QString post_id,bool up);
        ~ 改变帖子票数
int createpage(pagelet,post);
        ~ 创建新的帖页
int deletepage(QString);
        ~ 删除贴页
int changebm(QString board,QString usr);
        ~ 改换版主
int changepw(QString oldpwd,QString newpwd;
        ~ 改换密码
int changeag(QDate,int);//change age andgender
        ~ 改换年龄,性别
QJsonObject callback(QJsonObject json);
        ~ 发送请求,接受响应

## 服务端

### 数据库
服务端负责与数据库交互.数据库采用内存数据库*容器*+磁盘数据库*SQlite*两种.其机制与优势详见[#database].相关函数如下:

void initdatabase();
        ~初始化数据库.由于单例模式,只需要一次登入数据库.若第一次运行服务端,数据库不存在,则自动生成默认数据库,写入root权限
void loaduserinfos();
        ~读取sqlite中users表到users容器
void loadposts();
        ~按时间排序,读取sqlite中posts表到posts容器
void loadpagelets();
        ~按时间排序,读取sqlite中pagelets表到users容器
void loadboard();
        ~读取sqlite中boards表到boards容器
void replacebase();
        ~更新sqlite数据库
server << user/post/pagelet/board
        ~实现运算符<<重载,极大地方便了对于数据库的读取操作.

### 服务端窗口

fakedialog类负责显示当前服务端Console.具备以下功能:

1. 显示当前用户人数
2. 显示新建链接与断开链接的socketid
3. 显示某socketid与其发送的请求json字符串
4. 显示应答json字符串
5. (可拓展选项),将以上显示信息存为log日志文件
6. 选择关闭服务器

server类signals:
    
void print(QString);
        ~console打印信号
void connum(int);
        ~更新在线人数信号


### cookie/session
void sessionadd (userinfo*);
        ~ 将用户信息存入session,若用户存在则更新session
userinfo * cookie2usr(QString cookie)
        ~ 通过cookie得到用户信息


### 服务器接收应答请求

**private slots:**

void newConnect();
        ~接收新连接信号槽,tcpsocket绑定
void disconnect(int);
        ~断开链接信号槽,通过map与tcpsocket绑定
void readMsg(int);
        ~读取信息信号槽,通过map与tcpsocket绑定

**private:**

void inittcpserver();
        ~初始化tcpserver,初始化tcpsocket容器,开始监听端口
void connumfresh();
        ~ 更新人数

**public:**

QJsonObject login(QJsonObject);
        ~ 处理登录请求
QJsonObject signup(QJsonObject);
        ~ 处理注册请求
QJsonObject signupusrcheck(QJsonObject);
        ~ 处理注册用户名检测请求
QJsonObject signuppwdcheck(QJsonObject);
        ~ 处理注册密码检测请求
QJsonObject signupemailcheck(QJsonObject);
        ~ 处理注册邮件格式检测请求
QJsonObject gethomepage();
        ~ 处理获取主页请求
QJsonObject getposts(QJsonObject);
        ~ 处理获取帖子请求
QJsonObject getboards();
        ~ 处理获取版块列表请求
(*need cookie to check right:*)
QJsonObject getdateuser(QJsonObject params);
        ~ 处理获取用户信息请求,只能获取本用户
QJsonObject getuserlist(QJsonObject);
        ~ 处理获取用户列表请求,只有管理员可以
QJsonObject logout(QJsonObject params);
        ~ 处理注销请求,只注销本用户
QJsonObject deleteusr(QJsonObject params);
        ~ 处理删除用户请求,只有管理员可以
QJsonObject uploadpost(QJsonObject params);
        ~ 处理发帖请求,需要个人id.根据发帖人与发帖时间贴页id,生成帖子id.将帖子信息存入数据库
QJsonObject changevote(QJsonObject params);
        ~ 处理赞同/反对请求,需要id
QJsonObject createpage(QJsonObject params);
        ~ 处理创建贴页请求.需要个人id.根据发帖人发帖时间与版块名,生成贴页id,存储贴页
QJsonObject deletepage(QJsonObject params);
        ~ 处理删除贴页请求.需要鉴定权限.
QJsonObject changebm(QJsonObject params);
        ~ 处理改变版主,需要管理员权限
QJsonObject changepw(QJsonObject params);
        ~ 处理改换密码请求,需要个人验证
QJsonObject changeag(QJsonObject params);
        ~ 处理设置生日,性别请求,需要个人验证

# 产品迭代

## 第一代

登录,注册,浏览主页,发帖,删帖,评论,查看更改个人信息,任命版主,删除用户,注销,图形化等所有要求.并拓展了cookie/session等机制.充分利用继承,泛化等c++特性.

## 第二代

在第一版的基础上,软件内部分离client与server类,并添加SQLite数据库存储信息.对于sqlite的读取运算符重载.增添了创建新版面,选中批量删帖功能.美化了UI

## 最终版

在第二版基础上,分离成C端与S端,利用tcp通信,以Json格式传输数据,实现多用户注册,登录,浏览主页,发帖,删帖等所有基本功能.同时,利用cookie/session机制,创新实现了用户登录管理等功能.

# 感悟

本次大作业历时3个月,经历3个大版本更新.收获颇丰,感受到老师用心良苦.过程中有很多个第一次:

1. 第一次使用Qt,第一次接触信号槽
2. 第一次采用单例模式写C++
3. 第一次用C++实现C/S架构,第一次使用tcpsocket
4. 第一采用面向对象写如此完整的工程.

实验的结果:超额实现了所有提出的需求.并在系统的安全性与拓展性上做出了充分的优化.经历过重重验收的考验,与验收学长的深入讨论交流,可以说,本系统在已有的架构上,具备充分的合理性与自恰性.

但是,前路慢慢其修远兮.随着对面向对象的理解愈加深入,对于架构方面的知识逐渐拓宽,一步步的经验的不断扩充,必须承认,如果想做一个成熟的,强大的,更利于维护,结构更为健康的论坛,还有很长的路要走.如果时间还够,可以有机会验收第4版,我将在以下几方面做出优化:

1. 服务端类更加细化,对于各个实体,如`user,post,pagelet`等,创建\*.entity类和\*.service类分别充当实体类与控制类.更加模块化.另外单独交由*通信类*来作tcpserver处理链接和转发回应请求,单独分出*数据类*与数据库进行交互
2. 服务端采用多线程的方式,提高性能
3. 服务端内存数据库改为`Redis`等流行的内存数据库,并将增删减改等操作交由数据库完成
4. 添加系统消息与好友功能,完善帖子排名系统,与用户等级系统.
5. 优化前端界面,尽可能用*页*来代替Dialog,使之更加趋近于流行的网站视图
6. 提高安全性,采用https进行通信.

时光荏苒,转眼已经是2019.愿这些宝贵的经验能助我前行.同时,感谢老师与助教的辛勤付出,愿大家都有一个美好的2019.


