
#pragma once
#include <QObject>

namespace twentysixapps{
    class ClocksLayoutViewManager : public QObject
    {
        Q_OBJECT
    public:
        explicit ClocksLayoutViewManager(QObject *parent=0);

    private:
        explicit ClocksLayoutViewManager(const ClocksLayoutViewManager& rhs) = delete;
        ClocksLayoutViewManager& operator= (const ClocksLayoutViewManager& rhs) = delete;
    };
}


