#pragma once

#include "Lockable.h"
#include "Mutex.h"

namespace aux
{
#if defined(DEBUG) || defined(_DEBUG)
#define CHECK_DEADREFERENCE_CALL
#endif

    template
    <
          class                  DerivedT
        , class                  SyncObj        = sync::Mutex
        , template <class> class ThreadingModel = sync::ClassLevelLockable
    >
    class  Singleton : ThreadingModel  < SyncObj >
                     , aux::NonCopyable< Singleton<DerivedT, SyncObj, ThreadingModel> >
    {
    public:
        static DerivedT& GetInstance()
        {
            bool IsDeadReferenceRebirth = false;
            if ( ! Instance_ )
            {
                Lock lock;

                if ( ! Instance_ )
                {
#ifdef CHECK_DEADREFERENCE_CALL
                    IsDeadReferenceRebirth = Destroyed_;
#endif

                    Instance_               = new DerivedT();

#ifdef CHECK_DEADREFERENCE_CALL
                    Destroyed_              = false;
#endif

                    atexit( Destruct );
                }
            }

#ifdef CHECK_DEADREFERENCE_CALL
            if (IsDeadReferenceRebirth)
            {
                OnDeadReference();
            }
#endif
            return *Instance_;
        }

        static void Destruct()
        {
            if ( Instance_ )
            {
                Lock lock;

                if ( Instance_ )
                {
                    delete Instance_;
                    Instance_  = nullptr;
#ifdef CHECK_DEADREFERENCE_CALL
                    Destroyed_ = true;
#endif
                }
            }
        }

    protected:
        Singleton()
        {

        }

        ~Singleton()
        {

        }

    private:
#ifdef CHECK_DEADREFERENCE_CALL
        static void OnDeadReference()
        {
            // for example, log this case...
        }
#endif

    private:
#ifdef CHECK_DEADREFERENCE_CALL
        static bool      Destroyed_;
#endif
        static DerivedT* Instance_;

    };

    template< class DerivedT, class SyncObj, template <class> class ThreadingModel>
    typename DerivedT* Singleton<DerivedT, SyncObj, ThreadingModel>::Instance_  = nullptr;

#ifdef CHECK_DEADREFERENCE_CALL
    template< class DerivedT, class SyncObj, template <class> class ThreadingModel>
    bool  Singleton<DerivedT, SyncObj, ThreadingModel>::             Destroyed_ = false;
#endif

}