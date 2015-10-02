#pragma once

#include <mutex>
#include "NonCopyable.h"

namespace sync
{
    template <class SyncObjT>
    class ClassLevelLockable
    {
    public:
        class        Lock;
        friend class Lock;

        class Lock: aux::NonCopyable<Lock>
        {
        public:
            Lock()
            {
                std::call_once(OnceFlag_, InitSyncObj);
                SyncObj_->Lock();
            }

            explicit Lock(const ClassLevelLockable&)
            {
                std::call_once(OnceFlag_, InitSyncObj);
                SyncObj_->Unlock();
            }

            ~Lock()
            {
                SyncObj_->Unlock();
            }

        private:
            Lock(const Lock&);
            Lock& operator=(const Lock&);
        };

    private:
        static void InitSyncObj()
        {
            SyncObj_ = new SyncObjT();
            atexit(DoneSyncObj);
        }

        static void DoneSyncObj()
        {
            delete SyncObj_;
        }

        static SyncObjT*      SyncObj_;
        static std::once_flag OnceFlag_;

    };

    template <class SyncObjT> typename SyncObjT* ClassLevelLockable<SyncObjT>::SyncObj_ = nullptr;
    template <class SyncObjT> std::once_flag ClassLevelLockable<SyncObjT>    ::OnceFlag_;
}



