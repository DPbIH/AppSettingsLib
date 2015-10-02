#pragma once

namespace aux
{
    template <class DerivedT>
    class NonCopyable
    {
    protected:
         NonCopyable () {}
        ~NonCopyable () {}

    private: 
        NonCopyable              (const NonCopyable &);
        NonCopyable & operator = (const NonCopyable &);

    };
}