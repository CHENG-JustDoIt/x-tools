﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include <atomic>

#include <QMutex>
#include <QThread>
#include <QVariantMap>

namespace xTools {

class AbstractIO : public QThread
{
    Q_OBJECT
    Q_PROPERTY(bool isWorking READ isWorking NOTIFY isWorkingChanged)
    Q_PROPERTY(bool isEnable READ isEnable WRITE setIsEnable NOTIFY isEnableChanged)
public:
    explicit AbstractIO(QObject *parent = Q_NULLPTR);
    virtual ~AbstractIO();
    virtual Q_INVOKABLE void inputBytes(const QByteArray &bytes);
    Q_INVOKABLE virtual QVariantMap save() const;
    Q_INVOKABLE virtual void load(const QVariantMap &data);

    bool isWorking();
    bool isEnable();
    void setIsEnable(bool enable);

signals:
    void outputBytes(const QByteArray &bytes);
    void warningOccurred(const QString &warningString);
    void errorOccurred(const QString &errorString);

    void isWorkingChanged();
    void isEnableChanged();

protected:
    std::atomic_bool m_isWorking{false};
    std::atomic_bool m_enable{true};

private:
    QVariantMap m_parameters;
    mutable QMutex m_parametersMutex;
};

} // namespace xTools
