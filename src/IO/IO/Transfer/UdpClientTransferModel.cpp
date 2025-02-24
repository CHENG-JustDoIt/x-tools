﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "UdpClientTransferModel.h"

#include "../Communication/UdpClient.h"

namespace xTools {

UdpClientTransferModel::UdpClientTransferModel(QObject *parent)
    : SocketTransferModel(parent)
{}

UdpClientTransferModel::~UdpClientTransferModel() {}

Socket *UdpClientTransferModel::createSocket()
{
    return new UdpClient(this);
}

bool UdpClientTransferModel::isEnableRestartingColumn(int column) const
{
    if (column == 1 || column == 2 || column == 3 || column == 4) {
        return true;
    }

    return false;
}

} // namespace xTools
