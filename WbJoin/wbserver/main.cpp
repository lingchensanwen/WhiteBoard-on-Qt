#include <QCoreApplication>
#include "wbserver.h" //引入驱动
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    WbServer server;
    server.listen(QHostAddress::Any, 1996);//9001不好用，换了一个端口就好用了
    return a.exec();
}
