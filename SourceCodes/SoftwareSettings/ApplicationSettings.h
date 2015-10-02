#pragma once

#include "ApplicationSettingsInterface.h"
#include "Singleton.h"
#include "GenericSettingsManager.h"
#include "SettingsPropertiesRegistry.h"
#include "QMutex"

namespace settings
{
    class ApplicationSettings: public IApplicationSettings
                             , public aux::Singleton<ApplicationSettings>
    {
    public:
         ApplicationSettings( );

        virtual QString GetLogFilePath           ( )                      override;
        virtual QString GetWorkspacePath         ( )                      override;
        virtual QString GetCrashDumpDirectoryPath( )                      override;
        virtual QColor  GetBackgroundColor       ( )                      override;
        virtual QColor  GetRGB_Offset            ( )                      override;

        virtual void    SetLogFilePath           ( const QString& path  ) override;
        virtual void    SetWorkspacePath         ( const QString& path  ) override;
        virtual void    SetCrashDumpDirectoryPath( const QString& path  ) override;
        virtual void    SetBackgroundColor       ( const QColor&  color ) override;
        virtual void    SetRGB_Offset            ( const QColor&  offset) override;

    private:
        void     CreateSettingsManager           ( );
        void     LoadPersistentSettings          ( );
        void     AddToCache                      ( const SettingProperties& props );

        QVariant GetSettingValue                 ( ESW_Settings setting_key       );
        QVariant GetSettingValueOmitCache        ( const SettingProperties& props );
        void     SetSettingValue                 ( ESW_Settings setting_key, const QVariant& value );

    private:
        typedef std::map<ESW_Settings, QVariant> SettingsValuesCacheT;

        SettingsValuesCacheT                    PersistentSettingsCache_;
        QMutex                                  CacheMutex_             ;
        std::unique_ptr<GenericSettingsManager> SettingsManager_        ;
        SettingsPropertiesRegistry              SettingsPropsRegistry_  ;
    };
}