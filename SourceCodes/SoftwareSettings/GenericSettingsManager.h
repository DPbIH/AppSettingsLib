#pragma once

#include <QSettings>
#include <memory>

namespace settings
{
    class GenericSettingsManager
    {
        enum class ESettingsType { User, System };

    public:
        GenericSettingsManager( QString company_name, QString application_name );

        void       SetUserValue      ( const QString& group, const QString& key, const QVariant& value );
        void       SetSystemValue    ( const QString& group, const QString& key, const QVariant& value );

        QVariant   GetUserValue      ( const QString& group, const QString& key, const QVariant& default_value );
        QVariant   GetSystemValue    ( const QString& group, const QString& key, const QVariant& default_value );

        QString    UserSettingsPath  ( );
        QString    SystemSettingsPath( );

    private:
        void       SetValue          ( ESettingsType   type
                                     , const QString&  group
                                     , const QString&  key
                                     , const QVariant& value );
        QVariant   GetValue          ( ESettingsType   type
                                     , const QString&  group
                                     , const QString&  key
                                     , const QVariant& default_value );
        void       CreateSettings    ( );

        QSettings* GetSettingsByType ( ESettingsType   type );

    private:
        std::unique_ptr<QSettings> UserSettings_   ;
        std::unique_ptr<QSettings> SystemSettings_ ;

        QString                    CompanyName_    ;
        QString                    ApplicationName_;

    };
}