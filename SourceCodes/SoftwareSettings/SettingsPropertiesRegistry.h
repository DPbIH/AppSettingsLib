#pragma once

#include "SettingProperties.h"
#include "NonCopyable.h"
#include <map>

namespace settings
{
    class SettingsPropertiesRegistry:
        aux::NonCopyable<SettingsPropertiesRegistry>
    {
    public:
        typedef std::map< ESW_Settings, SettingProperties > PropertiesMapT;

        SettingsPropertiesRegistry                ( );
        const SettingProperties& GetProperties    ( ESW_Settings setting_key ) const;
        const PropertiesMapT   & GetAllProperties ( )                          const;
    private:
        void                     InitRegistry ( );

    private:
        PropertiesMapT Properties_;

    };
}