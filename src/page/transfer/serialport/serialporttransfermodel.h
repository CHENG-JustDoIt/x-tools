﻿/***************************************************************************************************
 * Copyright 2024-2025 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include "page/transfer/common/transfermodel.h"

class SerialPortTransferModel : public TransferModel
{
    Q_OBJECT
public:
    SerialPortTransferModel(QObject *parent = nullptr);
    ~SerialPortTransferModel() override;

    virtual QVariantMap saveRow(const int row) override;
    virtual void loadRow(const int row, const QVariantMap &item) override;

    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

protected:
    Device *createTransfer() override;
    bool isEnableRestartColumn(int column) const override;
};
