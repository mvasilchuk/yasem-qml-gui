#include "qmlgui.h"
#include "profilemanager.h"

#include <QSettings>
#include <QQmlEngine>
#include <QQuickWindow>
#include <QQmlComponent>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include <QApplication>


using namespace yasem;

QmlGui::QmlGui()
{
    QSettings* settings = Core::instance()->settings();
    settings->beginGroup("DesktopQmlGui");
    settings->endGroup();

    engine = NULL;
    mainWindow = NULL;
    rootObject = NULL;
}


PLUGIN_ERROR_CODES QmlGui::initialize()
{
    DEBUG() << "initialize";
    //ProfileManager::instance()->loadProfiles();

    engine = new QQmlApplicationEngine();
    engine->load(QUrl("qrc:/qml/mainwindow.qml"));
    rootObject = (QQuickItem*)engine->rootObjects().value(0);

    mainWindow = qobject_cast<QQuickWindow *>(rootObject);
    mainWindow->show();

    webView = rootObject->findChild<QQuickItem*>("web_view");
    connect(mainWindow, &QQuickWindow::frameSwapped, webView, &QQuickItem::update);

    DEBUG() << "QML init";

    return PLUGIN_ERROR_NO_ERROR;
}

PLUGIN_ERROR_CODES QmlGui::deinitialize()
{
    DEBUG() << "deinitialize";
    return PLUGIN_ERROR_NO_ERROR;
}

void QmlGui::register_dependencies()
{
    add_dependency(ROLE_WEB_SERVER);
    add_dependency(ROLE_BROWSER);
    add_dependency(ROLE_WEB_GUI);
    add_dependency(ROLE_DATASOURCE);
    add_dependency(ROLE_MEDIA);
}

void QmlGui::register_roles()
{
    register_role(ROLE_GUI);
    register_role(ROLE_STB_API_SYSTEM);
}

QRect QmlGui::getWindowRect()
{
    return QRect();
}

void QmlGui::setWindowRect(const QRect &rect)
{
}

void QmlGui::setFullscreen(bool fullscreen)
{
}

bool QmlGui::getFullscreen()
{
    return false;
}

void QmlGui::repaintGui()
{
}

QList<QMenu *> QmlGui::getMenuItems()
{
    return QList<QMenu*>();
}


QRect yasem::QmlGui::widgetRect()
{
    return QRect(0, 0, rootObject->width(), rootObject->height());
}
