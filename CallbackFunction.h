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
