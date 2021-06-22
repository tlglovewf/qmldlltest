//#include <QGuiApplication>
#include <QtWidgets/QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include <QQuickItem>
#include "ColorMarker.h"
#include <QtWidgets/QWidget>
static void prepareApp()
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
	QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
	QGuiApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
#    if (QT_VERSION >= QT_VERSION_CHECK(5, 14, 0))
	QGuiApplication::setHighDpiScaleFactorRoundingPolicy(Qt::HighDpiScaleFactorRoundingPolicy::PassThrough);
#    endif
#endif
	QCoreApplication::setOrganizationName("JaredTao");
	QCoreApplication::setOrganizationDomain("https://JaredTao.gitee.io");
	QCoreApplication::setApplicationName("TaoQuickShow");
}


int main(int argc, char *argv[])
{
	prepareApp();

    QApplication app(argc, argv);

	QQuickView viewer;

	//viewer.setMinimumSize({ 800, 600 });
	//viewer.resize(1440, 960);

	viewer.engine()->addImportPath("../assembly");
	//将c++类注册进QML中
	qmlRegisterType<ColorMarker>("qt.ColorMaker", 1, 0, "ColorMaker");
	viewer.setResizeMode(QQuickView::SizeRootObjectToView);
	viewer.setSource(QUrl(QStringLiteral("qrc:/main.qml")));

	//QQuickItem *root = viewer.rootObject();
	//QObject *btn = temp->findChild<QObject*>("btnGetTime");
	//if (btn != nullptr)
	//{
	//	QObject::connect(btn, SIGNAL(clicked()), &app, SLOT(quit()));
	//}

/* 导入一个c++对象 */
	QWidget *widget = new QWidget(nullptr);
	widget->setGeometry(QRect(0,0, 320, 240));
	widget->move(800, 600);

	viewer.engine()->rootContext()->setContextProperty("secWin", widget);

	return app.exec();
}
