#pragma once

#include "SettingsDefs.h"
#include <QString>
#include "QVariant"

namespace settings
{
    typedef QString SettingTag;
    typedef QString GroupTag;

    struct SettingProperties
    {
        SettingProperties( ) : Key_        ( ESW_Settings    ::Undefined )
                             , Persistence_( EPersistenceType::Undefined )
                             , Scope_      ( EScope          ::Undefined )
        {

        }

        SettingProperties( ESW_Settings     key
                         , EPersistenceType persistence
                         , EScope           scope
                         , SettingTag       tag
                         , GroupTag         group_tag   = QString()
                         , QVariant         default_val = QVariant() )
                         : Key_         ( key         )
                         , Persistence_ ( persistence )
                         , Scope_       ( scope       )
                         , Tag_         ( tag         )
                         , GroupTag_    ( group_tag   )
                         , DefaultValue_( default_val )
        {

        }

        ESW_Settings     Key_;
        EPersistenceType Persistence_;
        EScope           Scope_;
        SettingTag       Tag_;
        GroupTag         GroupTag_;
        QVariant         DefaultValue_;

    };
}