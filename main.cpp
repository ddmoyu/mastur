#include "Mastur.h"
#include <QtWidgets/QApplication>
#include "assets/qss/common.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    fontTheme();
    Mastur w;
    w.show();
    return a.exec();
}
