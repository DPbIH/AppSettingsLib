#include "stdafx.h"
#include "SettingsPropertiesRegistry.h"

namespace settings
{

    SettingsPropertiesRegistry::SettingsPropertiesRegistry()
    {
        InitRegistry();
    }

    const SettingProperties& SettingsPropertiesRegistry::GetProperties(ESW_Settings setting_key) const
    {
        PropertiesMapT::const_iterator it = Properties_.find( setting_key );

        if( Properties_.end() != it )
        {
            return it->second;
        }

        throw std::exception("The setting is not defined for this application");
    }

    const SettingsPropertiesRegistry::PropertiesMapT& SettingsPropertiesRegistry::GetAllProperties() const
    {
        return Properties_;
    }

    void SettingsPropertiesRegistry::InitRegistry()
    {
        // TO-DO: Consider loading these settings from XML
        Properties_[ESW_Settings::RGBOffset      ] = SettingProperties( ESW_Settings::RGBOffset      , EPersistenceType::Persistent, EScope::System, tags::values::TagRGBOffset      , tags::groups::TagGUI     );
        Properties_[ESW_Settings::DumpFilePath   ] = SettingProperties( ESW_Settings::DumpFilePath   , EPersistenceType::Updatable,  EScope::System, tags::values::TagDumpFilePath   , tags::groups::TagDirectories );
        Properties_[ESW_Settings::LogFilePath    ] = SettingProperties( ESW_Settings::LogFilePath    , EPersistenceType::Persistent, EScope::System, tags::values::TagLogFilePath    , tags::groups::TagDirectories );
        Properties_[ESW_Settings::SavePath       ] = SettingProperties( ESW_Settings::SavePath       , EPersistenceType::Persistent, EScope::User  , tags::values::TagSavePath       , tags::groups::TagDirectories );
        Properties_[ESW_Settings::BackgroundColor] = SettingProperties( ESW_Settings::BackgroundColor, EPersistenceType::Updatable , EScope::User  , tags::values::TagBackgroundColor, tags::groups::TagGUI     );
    }

}