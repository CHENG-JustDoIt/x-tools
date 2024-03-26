﻿/***************************************************************************************************
 * Copyright 2023-2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "xToolsSettings.h"

#include <QCoreApplication>
#include <QDesktopServices>
#include <QStandardPaths>

#include "xToolsDataStructure.h"

static const QString fileName()
{
    QStandardPaths::StandardLocation type = QStandardPaths::AppConfigLocation;
    QString path = QStandardPaths::writableLocation(type);
    auto ret = QString("%1/%2.ini").arg(path, QCoreApplication::applicationName());
    return ret;
}

xToolsSettings::xToolsSettings(QObject* parent)
    : QSettings{::fileName(), QSettings::IniFormat, parent}
{
    qInfo() << "The path of settings file is:" << qPrintable(fileName());
}

xToolsSettings* xToolsSettings::instance()
{
    static xToolsSettings* settings = Q_NULLPTR;
    if (!settings) {
        settings = new xToolsSettings(qApp);
    }
    return settings;
}

void xToolsSettings::openSettingsFileDir()
{
    QDesktopServices::openUrl(settingsPath());
}

QString xToolsSettings::settingsPath()
{
    QString settingsFile(fileName());
    QString path = settingsFile.left(settingsFile.lastIndexOf("/"));
    return path;
}

int xToolsSettings::hdpiPolicy()
{
    int ret = value(mSettingsKey.hdpiPolicy).toInt();
#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
    if ((ret < 1) || (ret > 5)) {
        if (ret != xToolsDataStructure::HdpiPolicySystem) {
            ret = int(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
        }
    }
#endif
    return ret;
}

void xToolsSettings::setHdpiPolicy(int policy)
{
#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
    if ((policy < 1) || (policy > 5)) {
        if (policy != xToolsDataStructure::HdpiPolicySystem) {
            policy = int(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
        }
    }
#endif

    setValue(mSettingsKey.hdpiPolicy, policy);
    emit hdpiPolicyChanged();
}

QString xToolsSettings::appStyle()
{
#ifdef X_TOOLS_DEFAULT_APP_STYLE
    return value(mSettingsKey.appStyle, X_TOOLS_DEFAULT_APP_STYLE).toString();
#else
    return QString("Funcsion");
#endif
}

void xToolsSettings::setAppStyle(const QString& style)
{
    setValue(mSettingsKey.appStyle, style);
}

QString xToolsSettings::language()
{
    return value(mSettingsKey.language).toString();
}

void xToolsSettings::setLanguage(const QString& lan)
{
    setValue(mSettingsKey.language, lan);
}

bool xToolsSettings::clearSettings()
{
    return value(mSettingsKey.clearSettings).toBool();
}

void xToolsSettings::setClearSettings(bool clear)
{
    setValue(mSettingsKey.clearSettings, clear);
    emit clearSettingsChanged();
}

QString xToolsSettings::palette()
{
    return value(mSettingsKey.palette).toString();
}

void xToolsSettings::setPalette(const QString& fileName)
{
    setValue(mSettingsKey.palette, fileName);
    emit paletteChanged();
}

QVariant xToolsSettings::value(const QString& key, const QVariant& defaultValue) const
{
    return QSettings::value(key, defaultValue);
}

void xToolsSettings::setValue(const QString& key, const QVariant& value)
{
    QSettings::setValue(key, value);
}