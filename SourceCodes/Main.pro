TEMPLATE = subdirs

CONFIG              += ordered
SUBDIRS             += SoftwareSettings TestSettings
TestSettings.depends = SoftwareSettings

SoftwareSettings.subdir         = $${_PRO_FILE_PWD_}/SoftwareSettings
TestSettings.subdir             = $${_PRO_FILE_PWD_}/TestSettings
