﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of eTools project.
 *
 * eTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "WebSocketServerUi.h"

namespace xTools {

WebSocketServerUi::WebSocketServerUi(QWidget *parent)
    : SocketServerUi(xIO::CommunicationType::WebSocketServer, parent)
{
    setClientWidgetsVisible(false);
    setAuthenticationWidgetsVisible(false);
    setMulticastWidgetsVisible(false);
}

WebSocketServerUi::~WebSocketServerUi() {}

void WebSocketServerUi::setUiEnabled(bool enabled)
{
    setServerWidgetsEnabled(enabled);
}

} // namespace xTools
