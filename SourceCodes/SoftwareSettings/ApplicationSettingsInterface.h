#pragma once
#include "QString"
#include "QColor"

namespace settings
{
    class IApplicationSettings
    {
    public:
        virtual ~IApplicationSettings(){ }

        virtual QString GetLogFilePath           ( )                       = 0;
        virtual QString GetWorkspacePath         ( )                       = 0;
        virtual QString GetCrashDumpDirectoryPath( )                       = 0;
        virtual QColor  GetBackgroundColor       ( )                       = 0;
        virtual QColor  GetRGB_Offset            ( )                       = 0;

        virtual void    SetLogFilePath           ( const QString& path   ) = 0;
        virtual void    SetWorkspacePath         ( const QString& path   ) = 0;
        virtual void    SetCrashDumpDirectoryPath( const QString& path   ) = 0;
        virtual void    SetBackgroundColor       ( const QColor&  color  ) = 0;
        virtual void    SetRGB_Offset            ( const QColor&  offset ) = 0;

    };
}