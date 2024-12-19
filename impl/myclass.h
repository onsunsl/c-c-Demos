#ifndef MYCLASS_H
#define MYCLASS_H
#include <QObject>
#include <QString>

// MyClass 对外接口
class MyClass: public QObject
{
    Q_OBJECT
public:
    // 有虚函数的析构函数 需要声明为虚函数，否则会导致内存泄漏
    virtual ~MyClass() = default;

    // 创建一个 MyClass 实例
    static MyClass* instance(QObject* parent);

    // 暴露接口
    virtual void test() = 0;

signals:
    // Qt信号
    void sigTest(QString);
};

#endif // MYCLASS_H
