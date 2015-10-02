#include "stdafx.h"
#include "ApplicationSettings.h"
#include "GlobalDefs.h"
#include "Helpers.h"
#include "QMutex"

namespace settings
{
    ApplicationSettings::ApplicationSettings()
        : CacheMutex_( QMutex::Recursive )
    {
        CreateSettingsManager ( );
        LoadPersistentSettings( );
    }

    void ApplicationSettings::LoadPersistentSettings()
    {
        for( const auto& setting: SettingsPropsRegistry_.GetAllProperties() )
        {
            const SettingProperties& props = setting.second;

            if( props.Persistence_ == EPersistenceType::Persistent )
            {
                AddToCache( props );
            }
        }
    }

    void ApplicationSettings::AddToCache(const SettingProperties& props)
    {
        QVariant value = GetSettingValueOmitCache( props );

        QMutexLocker lock( &CacheMutex_ );

        PersistentSettingsCache_[ props.Key_ ] = value;
    }

    QVariant ApplicationSettings::GetSettingValue( ESW_Settings setting_key )
    {
        SettingProperties props = SettingsPropsRegistry_.GetProperties(setting_key);

        QVariant value;

        if( props.Persistence_ == EPersistenceType::Persistent )
        {
            QMutexLocker lock( &CacheMutex_ );

            SettingsValuesCacheT::iterator it = PersistentSettingsCache_.find( props.Key_ );

            if( it != PersistentSettingsCache_.end() )
            {
                value = it->second;
            }
        }
        else
        {
            value = GetSettingValueOmitCache(props);
        }

        return value;
    }

    QVariant ApplicationSettings::GetSettingValueOmitCache(const SettingProperties& props)
    {
        QVariant value;

        switch( props.Scope_ )
        {
        case EScope::System:
            value = SettingsManager_->GetSystemValue( props.GroupTag_, props.Tag_, props.DefaultValue_ );
            break;

        case EScope::User:
            value = SettingsManager_->GetUserValue  ( props.GroupTag_, props.Tag_, props.DefaultValue_ );
            break;

        default:
            assert(false);
            break;
        }

        return value;
    }

    void ApplicationSettings::SetSettingValue(ESW_Settings setting, const QVariant& value)
    {
        SettingProperties props = SettingsPropsRegistry_.GetProperties(setting);

        if( props.Persistence_ == EPersistenceType::Persistent )
        {
            QMutexLocker lock( &CacheMutex_ );

            PersistentSettingsCache_[setting] = value;
        }

        switch( props.Scope_ )
        {
        case EScope::System:
            SettingsManager_->SetSystemValue( props.GroupTag_, props.Tag_, value );
            break;

        case EScope::User:
            SettingsManager_->SetUserValue  ( props.GroupTag_, props.Tag_, value );
            break;

        default:
            assert(false);
            break;
        }
    }

    void ApplicationSettings::CreateSettingsManager()
    {
        SettingsManager_.reset( new GenericSettingsManager( COMPANY_NAME, PRODUCT_NAME ) );
    }

    QString ApplicationSettings::GetLogFilePath()
    {
        QVariant value = GetSettingValue( ESW_Settings::LogFilePath );
        
        return value.toString();
    }

    QString ApplicationSettings::GetWorkspacePath()
    {
        QVariant value = GetSettingValue( ESW_Settings::SavePath );

        return value.toString();
    }

    QString ApplicationSettings::GetCrashDumpDirectoryPath()
    {
        QVariant value = GetSettingValue( ESW_Settings::DumpFilePath );

        return value.toString();
    }

    QColor ApplicationSettings::GetBackgroundColor()
    {
        QVariant value = GetSettingValue( ESW_Settings::BackgroundColor );

        return aux::helpers::QVariantToQColor( value );
    }

    QColor ApplicationSettings::GetRGB_Offset()
    {
        QVariant value = GetSettingValue( ESW_Settings::RGBOffset );

        return aux::helpers::QVariantToQColor( value );
    }

    void ApplicationSettings::SetLogFilePath(const QString& path)
    {
        SetSettingValue( ESW_Settings::LogFilePath, path );
    }

    void ApplicationSettings::SetWorkspacePath(const QString& path)
    {
        SetSettingValue( ESW_Settings::SavePath, path );
    }

    void ApplicationSettings::SetCrashDumpDirectoryPath(const QString& path)
    {
        SetSettingValue( ESW_Settings::DumpFilePath, path );
    }

    void ApplicationSettings::SetBackgroundColor(const QColor& color)
    {
        SetSettingValue( ESW_Settings::BackgroundColor, aux::helpers::QColorToQVariant(color) );
    }

    void ApplicationSettings::SetRGB_Offset(const QColor& offset)
    {
        SetSettingValue( ESW_Settings::RGBOffset, aux::helpers::QColorToQVariant(offset) );
    }
}

