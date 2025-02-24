/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "SerialPortTransferUi.h"

#include <QHeaderView>

#include "SerialPortStyledItemDelegate.h"

namespace xTools {

SerialPortTransferUi::SerialPortTransferUi(QWidget *parent)
    : AbstractTransferUi{parent}
{
    auto *tv = tableView();
    auto hHeader = tv->horizontalHeader();
    hHeader->setStretchLastSection(true);
}

SerialPortTransferUi::~SerialPortTransferUi() {}

QStyledItemDelegate *SerialPortTransferUi::createItemDelegate() const
{
    return new SerialPortStyledItemDelegate();
}

} // namespace xTools
