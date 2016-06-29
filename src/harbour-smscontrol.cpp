/*
  Copyright (C) 2013 Jolla Ltd.
  Contact: Thomas Perl <thomas.perl@jollamobile.com>
  All rights reserved.

  You may use this file under the terms of BSD license as follows:

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Jolla Ltd nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR
  ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>

// MY INCLUDES

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlField>
//#include <QVariant>
//#include <QDebug>

#include <QDir>
#include <QStandardPaths>
//#include <QGuiApplication>
//#include <QQuickView>

#include <QQmlEngine>
#include <QtQml/QQmlContext>
#include <QtQml/qqml.h>

/*//#include "sailfishapplication.h"
#include "org.dmnk/Connection.h"
//#include "editablesqlmodel.h"
//#include "org.dmnk/personmanager.h"
#include "org.dmnk/controllabletype.h"
#include "org.dmnk/typemanager.h"
#include "org.dmnk/devicemanager.h"
#include "org.dmnk/controllabledevice.h"
#include "org.dmnk/devicestorage.h"*/

#include "Connection.h"
#include "controllabletype.h"
#include "typemanager.h"
#include "devicemanager.h"
#include "controllabledevice.h"
#include "devicestorage.h"
#include <QResource>

//QString configFilePath()
//{
//    QDir dir (QStandardPaths::writableLocation(QStandardPaths::ConfigLocation));
//    if (!dir.mkpath(QString("%1/%2").arg("dmnk.org", "SMSControl"))) {
//        return QString();
//    }
//    if (!dir.cd("dmnk.org")) {
//        return QString();
//    }
//    if (!dir.cd("SMSControl")) {
//        return QString();
//    }

//    return dir.absoluteFilePath("config.sqlite");
//}

int main(int argc, char *argv[])
{
    // SailfishApp::main() will display "qml/template.qml", if you need more
    // control over initialization, you can use:
    //
    //   - SailfishApp::application(int, char *[]) to get the QGuiApplication *
    //   - SailfishApp::createView() to get a new QQuickView * instance
    //   - SailfishApp::pathTo(QString) to get a QUrl to a resource file
    //
    // To display the view, call "show()" (will show fullscreen on device).

    createConnection();
    //QResource::registerResource("../images.qrc"); //qml files would have to be packaged too, to gain access to packed images
   // qmlRegisterType<EditableSqlModel>("org.dmnk.SqlQueryModel", 1, 0, "SqlQueryModel");
    qmlRegisterType<TypeManager>            ("harbour.smscontrol.TypeManager", 1,0, "TypeManager");
    qmlRegisterType<ControllableType>       ("harbour.smscontrol.ControllableType", 1,0, "ControllableType");
    qmlRegisterType<DeviceManager>          ("harbour.smscontrol.DeviceManager", 1,0, "DeviceManager");
    qmlRegisterType<ControllableDevice>     ("harbour.smscontrol.ControllableDevice", 1,0, "ControllableDevice");
    qmlRegisterType<ConfiguredControllableDevice>("harbour.smscontrol.ConfiguredControllableDevice", 1,0, "ConfiguredControllableDevice");
    qmlRegisterType<DeviceStorage>          ("harbour.smscontrol.DeviceStorage", 1,0, "DeviceStorage");

    //app.data()->setApplicationName("SMSControl");
    //app.data()->setOrganizationName("dmnk.org");

    return SailfishApp::main(argc, argv);
}


