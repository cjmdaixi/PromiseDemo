#ifndef ASYNCACTIONS_H
#define ASYNCACTIONS_H

#include <QObject>
#include <QFuture>

class AsyncActions : public QObject
{
    Q_OBJECT
public:
    explicit AsyncActions(QObject *parent = nullptr);

signals:

public slots:
    QFuture<QString> captureLeftCamera();
    QFuture<QString> captureRightCamera();
    QFuture<QString> construct(QString param);
    QFuture<QString> save(QString param);
};

#endif // ASYNCACTIONS_H
