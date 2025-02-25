﻿/***************************************************************************************************
 * Copyright 2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include "SocketTransfer.h"

namespace xTools {

class TcpServerTransferModel;
class TcpServerTransfer : public SocketTransfer
{
    Q_OBJECT
public:
    TcpServerTransfer(QObject *parent = nullptr);
    virtual ~TcpServerTransfer();

    QVariant tableModel() const override;

protected:
    TcpServerTransferModel *m_model;
};

} // namespace xTools
