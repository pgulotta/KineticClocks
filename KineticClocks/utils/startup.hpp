
#pragma once
#include <QObject>

namespace twentysixapps{
    class Startup : public QObject
    {
        Q_OBJECT
    public:
        explicit Startup(QObject *parent=0);

    private:
        explicit Startup(const Startup& rhs) = delete;
        Startup& operator= (const Startup& rhs) = delete;
    };
}


