﻿/***************************************************************************************************
 * Copyright 2020-2024 x-tools-author(x-tools@outlook.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part of xTools project.
 *
 * xTools is licensed according to the terms in the file LICENCE(GPL V3) in the root of the source
 * code directory.
 **************************************************************************************************/
#include "StringAssistant.h"
#include "ui_StringAssistant.h"

#include "IO/xIO.h"

StringAssistant::StringAssistant(QWidget* parent)
    : QWidget(parent)
    , ui(new Ui::StringAssistant)
{
    ui->setupUi(this);
    connect(ui->textEdit, &QTextEdit::textChanged, this, &StringAssistant::updateOutputString);
    connect(ui->inputFormatComboBox,
            static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this,
            &StringAssistant::updateOutputString);
    connect(ui->createPushButton, &QPushButton::clicked, this, &StringAssistant::updateOutputString);
    connect(ui->outputFormatComboBox,
            &QComboBox::currentTextChanged,
            this,
            &StringAssistant::updateOutputString);

    xTools::xIO::setupTextFormat(ui->outputFormatComboBox);
    xTools::xIO::setupTextFormat(ui->inputFormatComboBox);
}

StringAssistant::~StringAssistant()
{
    delete ui;
}

void StringAssistant::updateOutputString()
{
    QString inputString = ui->textEdit->toPlainText();
    auto inputFormat = ui->inputFormatComboBox->currentData().toInt();
    QByteArray inputArray = xTools::xIO::string2bytes(inputString, inputFormat);
    auto outputFormat = ui->outputFormatComboBox->currentData().toInt();
    auto outputString = xTools::xIO::bytes2string(inputArray, outputFormat);
    ui->textBrowser->setText(outputString);
}
