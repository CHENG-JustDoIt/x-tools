/***************************************************************************************************
 * Copyright 2018-2025 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include <QThread>

class FileCheckAssistant;
class HashCalculator : public QThread
{
    Q_OBJECT
public:
    HashCalculator(FileCheckAssistant* controller, QObject* parent = Q_NULLPTR);

signals:
    void outputMessage(QString msg, bool isErrMsg);
    void updateResult(QByteArray result);
    void progressBarMaxValueChanged(qint64 value);
    void updateProgressBar(qint64 currentValue);
    void remainTimeChanged(QString remainTime);

private:
    FileCheckAssistant* m_cryptographicHashController;
    QList<qint64> m_consumeTimeList;

private:
    void run() final;
};
