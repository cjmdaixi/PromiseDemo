#include "asyncactions.h"
#include <QtConcurrent>
#include <QThread>
#include <QtDebug>

AsyncActions::AsyncActions(QObject *parent) : QObject(parent)
{

}

QFuture<QString> AsyncActions::captureLeftCamera()
{
    auto future = QtConcurrent::run([&]()->QString{
        qDebug()<<"begin left capturing...";
        QThread::msleep(2000);
        qDebug()<<"finish left capturing!";
        return "capture left";
    });
    return future;
}

QFuture<QString> AsyncActions::captureRightCamera()
{
    auto future = QtConcurrent::run([&]()->QString{
        qDebug()<<"begin right capturing...";
        QThread::msleep(3000);
        qDebug()<<"finish right capturing!";
        return "capture right";
    });
    return future;
}

QFuture<QString> AsyncActions::construct(QString param)
{
    auto future = QtConcurrent::run([&](QString param)->QString{
        qDebug()<<"begin constructing"<<param<<"...";
        QThread::msleep(3000);
        qDebug()<<"finish constructing"<<param<<"!";
        return param + " constructed";
    }, param);
    return future;
}

QFuture<QString> AsyncActions::save(QString param)
{
    auto future = QtConcurrent::run([&](QString param)->QString{
        qDebug()<<"begin saving"<<param<<"...";
        QThread::msleep(4000);
        qDebug()<<"finish saving"<<param<<"!";
        return param + " saved!";
    }, param);
    return future;
}
