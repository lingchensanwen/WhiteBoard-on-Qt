#include <QCoreApplication>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QDebug>

/*{
    type: Join,
    name: Nana

  }*/

void CreateJoinJson(){

    QJsonDocument doc;
    QJsonObject root;//根对象
    root.insert("type", QJsonValue("Join"));
    root.insert("name", QJsonValue("Nana"));
    doc.setObject(root);//设置为doc的根对象

    qDebug() << "压缩格式:";
    QByteArray data = doc.toJson(QJsonDocument::Compact);//压缩格式
    qDebug() << data.data();

    qDebug() << "默认格式:";
    QByteArray data2 = doc.toJson(QJsonDocument::Indented);//默认格式
    qDebug() << data2.data();

}

/*{ "type": "add"
    figure:{
    "creator": 800,
    "global_id": 701,
    "local_id": 2,
    "type": "line",
    "data": {
        "color": 123456,
        "fill_color": 127092,
        "line_cap": "round",
        "line_join": "round",
        "line_width": 5,
        "points":[
            50,
            80,
            300,
            200
            ]
        }
    }
}*/

QByteArray AddJson(){

    QJsonDocument doc;
    QJsonObject root;
    root.insert("type", QJsonValue("add"));
    QJsonObject figure;
    figure.insert("creator", QJsonValue(800));
    figure.insert("global_id", QJsonValue(2));
    figure.insert("local_id", QJsonValue(1));
    figure.insert("type", QJsonValue("line"));
    QJsonObject data;
    data.insert("color", QJsonValue(12334));
    data.insert("fill_color", QJsonValue(111));
    data.insert("line_width", QJsonValue(5));

    QJsonArray points;
    points.append(QJsonValue(80));
    points.append(QJsonValue(80));
    points.append(QJsonValue(180));
    points.append(QJsonValue(280));

    data.insert("points", QJsonValue(points));
    figure.insert("data", QJsonValue(data));
    root.insert("figure", QJsonValue(figure));

    doc.setObject(root);

    return doc.toJson();
}

void ParseAddJson(const QByteArray &data){
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject root = doc.object();

    qDebug() << "type :" <<root.value("type").toString();

    QJsonObject figure = root["figure"].toObject();
    qDebug() << "creator: "<< figure["creator"].toInt();

    QJsonArray ponits = figure.value("data").toObject().value("points").toArray();
    qDebug() << "points:" << ponits[0].toInt();

}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    CreateJoinJson();

    QByteArray json = AddJson();

    qDebug() << json.data();
    ParseAddJson(json);

    return a.exec();
}
