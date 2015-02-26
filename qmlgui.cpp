#include "qmlgui.h"
#include "profilemanager.h"

#include <QSettings>
#include <QQmlEngine>
#include <QQuickWindow>
#include <QQmlComponent>


using namespace yasem;

QmlGui::QmlGui()
{
    QSettings* settings = Core::instance()->settings();
    settings->beginGroup("DesktopQmlGui");
    settings->endGroup();
}


PLUGIN_ERROR_CODES QmlGui::initialize()
{
    DEBUG() << "initialize";
    //ProfileManager::instance()->loadProfiles();

    QQmlEngine engine;
    QQmlComponent *component = new QQmlComponent(&engine);
    component->loadUrl(QUrl("qrc:/qml/mainwindow.qml"));
    DEBUG() << component->errorString();
    for(QQmlError err: component->errors())
    {
        ERROR() << "qml error:" << err.description();
    }
    QObject *topLevel = component->create();
    QQuickWindow *window = qobject_cast<QQuickWindow *>(topLevel);

    QSurfaceFormat surfaceFormat = window->requestedFormat();
    window->setFormat(surfaceFormat);
    window->show();

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
