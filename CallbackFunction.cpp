#include <QDebug>
#include "CallbackFunction.h"

CallbackFunction::CallbackFunction(QObject *parent) : QObject(parent)
{

}

void CallbackFunction::test()
{
    qDebug() << "test";
}
