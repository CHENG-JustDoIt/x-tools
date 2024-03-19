/***************************************************************************************************
 * Copyright 2023 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#pragma once

#include <QLoggingCategory>
#include <QMenu>
#include <QTextDocument>

namespace Ui {
class xToolsToolBoxUiCommunicationMenu;
}

class xToolsToolBox;
class SAKHighlighter;
class xToolsToolBoxUiCommunicationMenu : public QMenu
{
    Q_OBJECT
public:
    xToolsToolBoxUiCommunicationMenu(QWidget *parent = nullptr);
    ~xToolsToolBoxUiCommunicationMenu();

    void initialize(xToolsToolBox *toolBox, const QString &settingsGroup);

private:
    const QLoggingCategory mLoggingCategory{"SAK.CustomBoxUiParameters"};

private:
    Ui::xToolsToolBoxUiCommunicationMenu *ui;
};