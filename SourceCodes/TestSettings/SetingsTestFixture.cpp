#include "SetingsTestFixture.h"
#include "ApplicationSettings.h"

void SettingsTestFixture::TestModifyValues()
{
    static const char* log_path_new_val    = "/log/path/new/val";
    static const char* save_path_new_val   = "/save/path/new/val";
    static const char* dump_path_new_val   = "/dump/path/new/val";
    static const QColor bkg_color_new_val  = QColor("#332211");
    static const QColor rgb_offset_new_val = QColor("#221133");

    settings::ApplicationSettings& settings = settings::ApplicationSettings::GetInstance();

    settings.SetLogFilePath           (log_path_new_val  );
    settings.SetWorkspacePath         (save_path_new_val );
    settings.SetCrashDumpDirectoryPath(dump_path_new_val );
    settings.SetBackgroundColor       (bkg_color_new_val );
    settings.SetRGB_Offset            (rgb_offset_new_val);

    QString log_path    = settings.GetLogFilePath();
    QString save_path   = settings.GetWorkspacePath();
    QString dump_path   = settings.GetCrashDumpDirectoryPath();
    QColor  bkg_color   = settings.GetBackgroundColor();
    QColor  rgb_offset  = settings.GetRGB_Offset();

    QVERIFY( log_path   == log_path_new_val   );
    QVERIFY( save_path  == save_path_new_val  );
    QVERIFY( dump_path  == dump_path_new_val  );
    QVERIFY( bkg_color  == bkg_color_new_val  );
    QVERIFY( rgb_offset == rgb_offset_new_val );
}
