#include "stdafx.h"
#include "GenericSettingsManager.h"
#include <assert.h>

namespace settings
{

    GenericSettingsManager::GenericSettingsManager( QString company_name, QString application_name)
        : CompanyName_    ( company_name     )
        , ApplicationName_( application_name )
    {
        CreateSettings();
    }

    void GenericSettingsManager::SetUserValue(const QString& group, const QString& key, const QVariant& value)
    {
        SetValue( ESettingsType::User, group, key, value );
    }

    void GenericSettingsManager::SetSystemValue(const QString& group, const QString& key, const QVariant& value)
    {
        SetValue( ESettingsType::System, group, key, value );
    }

    void GenericSettingsManager::SetValue(ESettingsType type , const QString& group , const QString& key , const QVariant& value)
    {
        QSettings* settings = GetSettingsByType( type );

        settings->beginGroup( group      );
        settings->setValue  ( key, value );
        settings->endGroup  (            );
    }

    QVariant GenericSettingsManager::GetUserValue(const QString& group, const QString& key, const QVariant& default_value)
    {
        return GetValue( ESettingsType::User, group, key, default_value );
    }

    QVariant GenericSettingsManager::GetSystemValue(const QString& group, const QString& key, const QVariant& default_value)
    {
        return GetValue( ESettingsType::System, group, key, default_value );
    }

    QVariant GenericSettingsManager::GetValue(ESettingsType type , const QString& group , const QString& key , const QVariant& default_value)
    {
        QVariant value;

        QSettings* settings = GetSettingsByType( type );

        settings->beginGroup   ( group              );
        value = settings->value( key, default_value );
        settings->endGroup     (                    );

        return value;
    }

    QString GenericSettingsManager::UserSettingsPath()
    {
        return UserSettings_->fileName();
    }

    QString GenericSettingsManager::SystemSettingsPath()
    {
        return SystemSettings_->fileName();
    }

    void GenericSettingsManager::CreateSettings()
    {
        SystemSettings_.reset( new QSettings(QSettings::IniFormat, QSettings::SystemScope, CompanyName_, ApplicationName_) );
        UserSettings_.  reset( new QSettings(QSettings::IniFormat, QSettings::UserScope,   CompanyName_, ApplicationName_) );
    }

    QSettings* GenericSettingsManager::GetSettingsByType( ESettingsType type )
    {
        QSettings* settings = nullptr;

        switch( type )
        {
        case ESettingsType::User:
            settings = UserSettings_.get();
            break;

        case ESettingsType::System:
            settings = SystemSettings_.get();
            break;

        default:
            assert(false);
            break;
        }

        return settings;
    }

}