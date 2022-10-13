/*
The MIT License (MIT)

Copyright © 2022 Antonio Dias

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#ifndef COMMON_H
#define COMMON_H

#include <QtCore>
#include <QtGui>
#include <QtWidgets>
#include <QFont>

inline void fontTheme()
{
    QFont defaultFont = qApp->font();
    defaultFont.setPointSize(defaultFont.pointSize() + 2);
    defaultFont.setFamily("Microsoft YaHei");
    qApp->setFont(defaultFont);
}

inline void setThemeStyleSheet(bool dark)
{
    QFile file(dark ? ":/assets/qss/darkstyle.qss" : ":/assets/qss/lightstyle.qss");
    if (!file.open(QFile::ReadOnly))
        return;
    const QString style_sheet = QLatin1String(file.readAll());
    file.close();
    qApp->setStyleSheet(style_sheet);
}

#endif // COMMON_H
