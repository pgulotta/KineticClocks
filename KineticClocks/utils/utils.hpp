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

    template<typename T, typename... Args>
    static std::unique_ptr<T> make_unique(Args&&... args)
    {
        return std::unique_ptr<T> (new T(std::forward<Args>(args)...));
    }


private:
    explicit Utils(const Utils& rhs) = delete;
    Utils& operator= (const Utils& rhs) = delete;
    Utils(Utils&&) = delete;
    Utils& operator=(Utils&&) = delete;

};
}


