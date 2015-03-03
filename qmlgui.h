#ifndef QMLGUI_H
#define QMLGUI_H

#include "yasem-qml-gui_global.h"
#include "plugin.h"
#include "guiplugin.h"

#include <QRect>
#include <QQuickItem>
#include <QQuickWindow>
#include <QQmlApplicationEngine>

namespace yasem {

class YASEMQMLGUISHARED_EXPORT QmlGui: public QObject, public GuiPlugin, public Plugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.mvas.yasem.DesktopQmlGuiPlugin/1.0" FILE "metadata.json")
    Q_INTERFACES(yasem::Plugin yasem::GuiPlugin )

    Q_CLASSINFO("author", "Maxim Vasilchuk")
    Q_CLASSINFO("description", "Desktop QML GUI for YASEM")
public:
    explicit QmlGui();

    // Plugin interface
public:
    PLUGIN_ERROR_CODES initialize();
    PLUGIN_ERROR_CODES deinitialize();
    void register_dependencies();
    void register_roles();

    // GuiPlugin interface
public:
    QRect getWindowRect();
    void setWindowRect(const QRect &rect);
    void setFullscreen(bool fullscreen);
    bool getFullscreen();
    void repaintGui();
    QList<QMenu *> getMenuItems();

private:
    QQmlApplicationEngine* engine;
    QQuickWindow* mainWindow;
    QQuickItem* rootObject;
    QQuickItem* webView;

    // GuiPlugin interface
public:
    QRect widgetRect();
};
}

#endif // QMLGUI_H
