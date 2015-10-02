#include "stdafx.h"
#include "Mutex.h"

namespace sync
{
    Mutex::Mutex(QMutex::RecursionMode mode/*= QMutex::Recursive */)
        : Mutex_( new QMutex(mode) )
    {

    }

    void Mutex::Lock()
    {
        Mutex_->lock();
    }

    void Mutex::Unlock()
    {
        Mutex_->unlock();
    }
}
