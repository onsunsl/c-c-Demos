#include "myclass.h"
#include <QDebug>

// MyClassImpl 通过在cpp文件中实现 MyClass 接口隐藏了实现细节
class MyClassImpl : public MyClass
{
public:
    MyClassImpl(QObject *parent = nullptr)
    {
        setParent(parent);
        this->age = 15;
        this->name = "GuangLin";
    }
    ~MyClassImpl()
    {
        qDebug() << "delate MyClassImpl";
    }

    void test()
    {
        QString msg = "name:%1 age:%2";
        qDebug() << "hello test: " << msg.arg(this->name).arg(this->age);
        emit sigTest(msg);
    }

    void test2()
    {
        qDebug() << "MyClassImpl::test2";
    }

private:
    // 私有成员
    int age;
    QString name;
};

// 创建一个 MyClassImpl 实例
MyClass* MyClass::instance(QObject *parent)
{
    return new MyClassImpl(parent);
}

// void MyClass::test2()
// {
//     qDebug() << "MyClass::test2";
// }



