#pragma once
#include <QObject>
#include <QString>
#include <memory>

namespace twentysixapps
{
class Utils
{
public:
    static void destructorMsg(const QString& value);
    static void destructorMsg(const QObject * const object);

private:
    explicit Utils(const Utils& rhs) = delete;
    Utils& operator= (const Utils& rhs) = delete;
    Utils(Utils&&) = delete;
    Utils& operator=(Utils&&) = delete;

};
}

