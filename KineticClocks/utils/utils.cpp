#include "utils.hpp"
#include <QString>
#include <QDebug>

namespace twentysixapps
{
static QString DestructorMessage = QStringLiteral("The  %1 destructor called.");

void Utils::destructorMsg(const QString &value)
{
    qDebug() << DestructorMessage.arg(value);
}

void Utils::destructorMsg(const QObject* const object)
{
    destructorMsg(object->metaObject()->className());
}

int Utils::getRandomSign()
{
    return qrand() % 2 == 0 ? 1 : -1;
}

}
