#pragma once
#pragma execution_character_set("utf-8")

#include <QtWidgets/QWidget>
#include "ui_TabView.h"
#include <QStandardItemModel> 

class TabView : public QWidget
{
	Q_OBJECT

public:
	TabView(QWidget *parent = nullptr);
	~TabView();

private:
	Ui::TabViewClass ui;

	QStandardItemModel* viewTree;

	void initUI();
};
