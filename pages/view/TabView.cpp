#include "TabView.h"

TabView::TabView(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	initUI();
}

TabView::~TabView()
{}


void TabView::initUI()
{
	viewTree = new QStandardItemModel(ui.treeView);
	ui.treeView->setModel(viewTree);
	QStringList header;
	header << "名称" << "类型";
	viewTree->setHorizontalHeaderLabels(header);

	QStandardItem* item1 = new QStandardItem("1024");
	QStandardItem* item2 = new QStandardItem("2048");
	viewTree->setItem(0, 0, item1);
	viewTree->setItem(0, 1, item2);
}