#include "Mastur.h"
#include "assets/qss/lightstyle.h"
#include "assets/qss/darkstyle.h"

Mastur::Mastur(QWidget *parent): CFramelessWindow(parent)
{
    ui.setupUi(this);
    initUI();
}

Mastur::~Mastur()
{}

void Mastur::initUI()
{
    setTitleBar(ui.header);
	//ui.viewWidget->tabBar()->hide();
    initQss();
}

bool Mastur::isSystemDark()
{
	bool dark = false;
#ifdef Q_OS_WIN
	typedef LONG(WINAPI* tRegGetValueW)(HKEY, LPCWSTR, LPCWSTR, DWORD, LPDWORD, PVOID, LPDWORD);
	tRegGetValueW pRegGetValueW = tRegGetValueW(QLibrary::resolve("advapi32", "RegGetValueW"));

	if (pRegGetValueW) {
		DWORD value;
		DWORD size = sizeof(value);
		if (pRegGetValueW(HKEY_CURRENT_USER, L"Software\\Microsoft\\Windows\\CurrentVersion\\Themes\\Personalize",
			L"AppsUseLightTheme", RRF_RT_DWORD, nullptr, &value, &size) == ERROR_SUCCESS)
			dark = (value == 0);
	}
#endif
#ifdef Q_OS_LINUX
	GtkSettings* settings = gtk_settings_get_default();
	gchar* theme_name;
	g_object_get(settings, "gtk-theme-name", &theme_name, nullptr);
	dark = QString(theme_name).endsWith("Dark", Qt::CaseInsensitive);
#endif
#ifdef Q_OS_MAC
	dark = QString(macOSNative::themeName()).endsWith("Dark", Qt::CaseInsensitive);
#endif
	return dark;
}

void Mastur::initQss()
{
	bool m_dark = isSystemDark();
	if (m_dark) {
		darkTheme();
		ui.btnSettings->setIcon(QIcon(":/assets/img/setting.png"));
		ui.btnMini->setIcon(QIcon(":/assets/img/mini.png"));
		ui.btnMax->setIcon(QIcon(":/assets/img/max.png"));
		ui.btnClose->setIcon(QIcon(":/assets/img/close.png"));
	}
	else {
		lightTheme();
		ui.btnSettings->setIcon(QIcon(":/assets/img/setting_dark.png"));
		ui.btnMini->setIcon(QIcon(":/assets/img/mini_dark.png"));
		ui.btnMax->setIcon(QIcon(":/assets/img/max_dark.png"));
		ui.btnClose->setIcon(QIcon(":/assets/img/close_dark.png"));
	}
}