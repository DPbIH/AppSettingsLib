#pragma once

namespace settings
{
    enum class EPersistenceType { Persistent
                                , Updatable
                                , Undefined };

    enum class EScope           { User
                                , System
                                , Undefined };

    enum class ESW_Settings     { RGBOffset
                                , DumpFilePath
                                , LogFilePath
                                , SavePath
                                , BackgroundColor
                                , Undefined };

    namespace tags
    {
        namespace values
        {
            static const char* TagRGBOffset       = "RGBOffset";
            static const char* TagDumpFilePath    = "DumpFilePath";
            static const char* TagLogFilePath     = "LogFilePath";
            static const char* TagSavePath        = "SavePath";
            static const char* TagBackgroundColor = "BackgroundColor";
        }

        namespace groups
        {
            static const char* TagDirectories     = "Directories";
            static const char* TagGUI             = "GUI";
        }
    }
}