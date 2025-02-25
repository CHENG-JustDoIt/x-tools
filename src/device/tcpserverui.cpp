﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of eTools project.
 *
 * eTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "TcpServerUi.h"

namespace xTools {

TcpServerUi::TcpServerUi(QWidget *parent)
    : SocketServerUi(xIO::CommunicationType::TcpServer, parent)
{
    setClientWidgetsVisible(false);
    setChannelWidgetsVisible(false);
    setMulticastWidgetsVisible(false);
    setAuthenticationWidgetsVisible(false);
}

TcpServerUi::~TcpServerUi() {}

void TcpServerUi::setUiEnabled(bool enabled)
{
    setServerWidgetsEnabled(enabled);
}

} // namespace xTools
