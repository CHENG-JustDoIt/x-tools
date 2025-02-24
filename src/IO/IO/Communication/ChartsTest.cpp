﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of eTools project.
 *
 * eTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "ChartsTest.h"

#include <QPointF>
#include <QTimer>

#include "IO/xIO.h"

namespace xTools {

ChartsTest::ChartsTest(QObject *parent)
    : Communication(parent)
    , m_binaryTail(QByteArray::fromHex("0000807f"))
{

}

ChartsTest::~ChartsTest() {}

void ChartsTest::inputBytes(const QByteArray &bytes)
{
    Q_UNUSED(bytes);
}

void ChartsTest::run()
{
    QTimer *timer = new QTimer();
    m_testAngle = 0;

    const QString flag = tr("ChartsTest");
    QVariantMap parameters = save();
    ChartsTestDataKeys keys;
    int dataFormat = parameters.value(keys.dataFormat).toInt();
    int channels = parameters.value(keys.channels).toInt();
    connect(timer, &QTimer::timeout, timer, [this, timer, dataFormat, flag, channels]() {
        if (dataFormat == static_cast<int>(xIO::ChartsDataFormat::BinaryY)) {
            emit bytesRead(generateBinaryY(channels), flag);
        } else if (dataFormat == static_cast<int>(xIO::ChartsDataFormat::TextY)) {
            emit bytesRead(generateTextY(channels), flag);
        } else if (dataFormat == static_cast<int>(xIO::ChartsDataFormat::BinaryXY)) {
            emit bytesRead(generateBinaryXY(channels), flag);
        } else if (dataFormat == static_cast<int>(xIO::ChartsDataFormat::TextXY)) {
            emit bytesRead(generateTextXY(channels), flag);
        } else {
            qWarning() << "Invalid data format(test data)!";
            emit outputBytes(QByteArray("Invalid data format(test data)!"));
        }
    });

    timer->start(50);
    emit opened();
    exec();
    emit closed();
}

QByteArray ChartsTest::generateBinaryY(int channels)
{
    QByteArray bytes;
    for (int i = 0; i < channels; ++i) {
        float y = 10 * (i + 1) * qSin(m_testAngle * 3.1415926 / 180.0);
        bytes.append(reinterpret_cast<const char *>(&y), sizeof(y));
    };

    bytes.append(m_binaryTail);
    m_testAngle += 1;
    return bytes;
}

QByteArray ChartsTest::generateTextY(int channels)
{
    QString str;
    for (int i = 0; i < channels; ++i) {
        qreal y = 10 * (i + 1) * qSin(m_testAngle * 3.1415926 / 180.0);
        str.append(QString::number(y, 'f', 3) + (i == channels - 1 ? "" : ","));
    };

    str = str.trimmed();
    str.append("\n");
    m_testAngle += 1;
    return str.toUtf8();
}

QByteArray ChartsTest::generateBinaryXY(int channels)
{
    QByteArray bytes;
    for (int i = 0; i < channels; ++i) {
        float y = 10 * (i + 1) * qSin(m_testAngle * 3.1415926 / 180.0);
        bytes.append(reinterpret_cast<const char *>(&y), sizeof(y));
    };

    bytes.append(m_binaryTail);
    m_testAngle += 1;
    return bytes;
}

QByteArray ChartsTest::generateTextXY(int channels)
{
    QByteArray bytes;
    for (int i = 0; i < channels; ++i) {
        qreal y = 10 * (i + 1) * qSin(m_testAngle * 3.1415926 / 180.0);
        bytes.append(reinterpret_cast<const char *>(&y), sizeof(y));
    };

    bytes.append(m_binaryTail);
    m_testAngle += 1;
    return bytes;
}

} // namespace xTools
