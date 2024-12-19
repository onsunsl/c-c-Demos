#include <QCoreApplication>
#include "myclass.h"
#include <QObject>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    MyClass *inc = MyClass::instance(nullptr);
    auto onTest = [](QString msg){
        qDebug() << msg;
    };

    QObject::connect(inc, &MyClass::sigTest, onTest);

    inc->test();
    // inc->test2();

    // 这里~MyClassImpl()会被调用
    // inc是MyClass类型指针，如果不声明析构函数为虚函数，会只调用MyClass的虚构，而子类MyClassImpl虚构无法调用导致内存泄漏
    delete inc;

    return a.exec();
}
