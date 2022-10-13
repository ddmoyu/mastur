#pragma once

#include <QtWidgets/QWidget>
#include "ui_Mastur.h"
#include "libs/framelesswindow/framelesswindow.h"
#include <QFile>

class Mastur : public CFramelessWindow
{
    Q_OBJECT

public:
    Mastur(QWidget *parent = nullptr);
    ~Mastur();

private:
    Ui::MasturClass ui;
    bool isSystemDark();
    void initUI();
    void initQss();
    //void initConnect();
};
