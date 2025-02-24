/***************************************************************************************************
 * Copyright 2023-2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include "AbstractModelUi.h"

class AbstractIO;

namespace xTools {

class EmitterUi : public AbstractModelUi
{
    Q_OBJECT
public:
    explicit EmitterUi(QWidget *parent = nullptr);
    ~EmitterUi();

protected:
    QList<int> textItemColumns() const override;
};

} // namespace xTools
