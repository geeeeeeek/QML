# QML使用C++回调函数


1. QML中JS调用的回调函数，需要将其添加到使用一个继承QObject的类中。
````C++
#ifndef CALLBACKFUNCTION_H
#define CALLBACKFUNCTION_H

#include <QObject>

class CallbackFunction : public QObject
{
    Q_OBJECT
public:
    explicit CallbackFunction(QObject *parent = nullptr);

    Q_INVOKABLE void test();
};

#endif // CALLBACKFUNCTION_H
````
note: 必须使用Q_INVOKABLE宏修饰回调函数

2. 使用QMetaObject::invokeMethod调用QML中函数，将包含有回调函数的类作为参数，传入QML函数。
````C++
auto rootObject = engine.rootObjects().at(0);
QMetaObject::invokeMethod(rootObject, "testCallback", 
    Q_ARG(QVariant, QVariant::fromValue(new CallbackFunction)));
````

3. 完成以上两步，就可以直接在QML的函数中使用回调函数了。
````JavaScript
function testCallback(callback) {
    callback.test();
}
````
