/***************************************************************************************************
 * Copyright 2023-2025 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include <QMutex>

#include "common/xtools.h"
#include "page/common/tablemodel.h"

class EmitterModel : public TableModel
{
    Q_OBJECT
public:
    explicit EmitterModel(QObject *parent = nullptr);

    QVariantMap saveRow(const int row) override;
    void loadRow(const int row, const QVariantMap &item) override;

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    bool insertRows(int row, int count, const QModelIndex &parent) override;
    bool removeRows(int row, int count, const QModelIndex &parent) override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    void increaseElapsedTime(const int row, const int interval);
    bool isTimeout(const int row) const;
    void resetElapsedTime(const int row);

private:
    struct Item
    {
        bool enable{true};
        QString description{"Demo"};
        int interval{1000};
        TextItem textItem;

        int elapsedTime{0};
    };
    struct ItemKeys
    {
        const QString enable{"enable"};
        const QString description{"description"};
        const QString interval{"interval"};
        QString textItem{"textItem"};
    };

private:
    QList<Item> m_items;
};
