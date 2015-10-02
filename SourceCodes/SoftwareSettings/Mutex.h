#pragma once

#include "QMutex"
#include <memory>

namespace sync
{
    class Mutex
    {
    public:
             Mutex    ( QMutex::RecursionMode mode= QMutex::Recursive );

        void Lock     ( );
        void Unlock   ( );

    private:
        std::unique_ptr<QMutex> Mutex_;

    };
}