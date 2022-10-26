#pragma once
#pragma execution_character_set("utf-8")

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

public slots:
    void on_btnMini_clicked();
    void on_btnMax_clicked();
    void on_btnClose_clicked();
    void on_btnSettings_clicked();
};
