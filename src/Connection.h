#ifndef CONNECTION_H
#define CONNECTION_H
#include "QtSql/QSqlDatabase"
#include "QtSql/QSqlError"
#include "QtSql/QSqlQuery"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

/*
This file defines a helper function to open a connection to an
in-memory SQLITE database and to create a test table.
If you want to use another database, simply modify the code
below. All the examples in this directory use this function to
connect to a database.
*/

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        /*QMessageBox::critical(0, qApp->tr("Cannot open database"),
        qApp->tr("Unable to establish a database connection.\n"
        "This example needs SQLite support. Please read "
        "the Qt SQL driver documentation for information how "
        "to build it.\n\n"
        "Click Cancel to exit."), QMessageBox::Cancel);*/
        return false;
    }
    QSqlQuery query;

// TAB_TYPE
    query.exec("CREATE TABLE tab_type ( "
               "t_id   INTEGER PRIMARY KEY AUTOINCREMENT"
               "               NOT NULL,"
               "t_name TEXT    NOT NULL "
               ")");

// TAB_ACTIONS
    query.exec("CREATE TABLE tab_actions ( "
               "    a_id   INTEGER PRIMARY KEY AUTOINCREMENT"
               "                   NOT NULL,"
               "    a_name TEXT    NOT NULL "
               ")");

// TAB_CONFIGUREDDEVICES
    //not implemented, JSON storage used

// TAB_DEVICES
    query.exec("CREATE TABLE tab_devices ( "
               "d_id     INTEGER        PRIMARY KEY AUTOINCREMENT"
               "                        NOT NULL,"
               "d_name   TEXT( 0, 30 )  NOT NULL"
               "                        UNIQUE,"
               "d_typeID INTEGER        REFERENCES tab_type ( t_id ) ON DELETE RESTRICT,"
               "d_producer TEXT( 0, 30 ) "
               ")");


// TAB_DEVICESACTIONS
    query.exec("CREATE TABLE tab_devicesactions ( "
               "da_id       INTEGER PRIMARY KEY AUTOINCREMENT"
               "                    NOT NULL,"
               "da_deviceID INTEGER NOT NULL"
               "                    REFERENCES tab_devices ( d_id ) ON DELETE RESTRICT,"
               "da_actionID INTEGER NOT NULL"
               "                    REFERENCES tab_actions ( a_id ) ON DELETE RESTRICT,"
               "da_command  TEXT    NOT NULL "
               ")");

    // DATA for tabs

    //types
    {
    query.exec("INSERT INTO tab_type (t_id, t_name) VALUES (1, 'Home Security')");
    query.exec("INSERT INTO tab_type (t_id, t_name) VALUES (2, 'Power Socket')");
    query.exec("INSERT INTO tab_type (t_id, t_name) VALUES (3, 'Heating')");
    query.exec("INSERT INTO tab_type (t_id, t_name) VALUES (4, 'GPS')");
    query.exec("INSERT INTO tab_type (t_id, t_name) VALUES (5, 'Video Surveillance')");
    }

    //actions
    {
        { //old
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (1, 'Status')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (2, 'Arm-Away')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (3, 'Arm-Stay')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (4, 'Disarm')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (5, 'On')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (6, 'Off')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (7, 'Toggle')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (8, 'Locate')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (9, 'Arm')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (10, 'Time-Arm')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (11, 'Time-Disarm')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (12, 'IR-Enable')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (13, 'IR-Disable')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (14, 'Capture')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (15, 'Capture-Mail')");
//    query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (16, 'Status')");
}
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (9, 'Arm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (14, 'Capture')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (15, 'Capture-Mail')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (20, 'Disarm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (13, 'IR-Disable')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (12, 'IR-Enable')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (19, 'Status')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (10, 'Time-Arm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (11, 'Time-Disarm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (8, 'Locate')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (6, 'Off')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (5, 'On')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (16, 'Status')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (7, 'Toggle')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (2, 'Arm-Away')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (3, 'Arm-Stay')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (4, 'Disarm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (36, 'Set Disarm Password')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (23, 'Get Alerted-Numbers')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (32, 'Get Alert Level and Length')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (26, 'Get Alert-Sound-Length')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (25, 'Get Alert-Sound-Level')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (24, 'Get Entry-Delay')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (27, 'Get Commands')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (37, 'Get Commands (2)')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (38, 'Get Commands (3)')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (30, 'Set Language English')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (29, 'Set Language French')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (28, 'Set Language German')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (22, 'Microphone-Callback')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (21, 'Quit-Alarm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (35, 'Get RFID-Notification List')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (33, 'Get RFID-SMS Number')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (34, 'Get Speeddial')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (1, 'Status')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (31, '2 Way Audio-Callback')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (18, 'Off')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (17, 'On')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (39, 'Arm-Away (instant)')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (40, 'Arm-Stay (instant)')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (41, 'Disarm (instant)')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (42, 'Arm-Away (Latch-Key)')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (43, 'Arm-Away (Latch-Key instant)')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (44, 'Set House-ID')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (45, 'Enable timing')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (46, 'Disable timing')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (47, 'Set Time-Frames')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (48, 'Enable temperature control')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (49, 'Disable temperature control')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (50, 'Set temperature parameters')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (51, 'Enable over-temperature alarm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (52, 'Disable over-temperature alarm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (53, 'Set over-temperature limit')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (54, 'Enable rapid-temp. change alarm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (55, 'Disable rapid-temp. Change alarm')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (56, 'Set temp. increase within timeframe')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (57, 'Enable socket-output SMS-notification')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (58, 'Disable socket-output SMS-notification')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (59, 'Enable power supply SMS-notification')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (60, 'Disable power supply SMS-notification')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (61, 'Enable warning tone')");
        query.exec("INSERT INTO tab_actions (a_id, a_name) VALUES (62, 'Disable warning tone')");

    }

    //devices
    {
        //old
        {
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (1, 'LHD-8003', 1, 'LongHorn-CSST')");
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (2, 'DRH-301 (Master)', 2, 'GSM-One')");
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (3, 'DRH-301 (Family)', 2, 'GSM-One')");
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (4, 'AP801G', 2, 'OR')");
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (5, 'AMGOVIS GSM+', 1, 'AMG')");
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (6, 'ST-IVB', 1, 'iAlarm')");
//           // query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (7, 'FC-400', 1, 'iAlarm')");//!!/*
//           // query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (8, 'ST-IIIB', 1, 'iAlarm')");//!!
//           // query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (9, 'ST-VB', 1, 'iAlarm')");//!!*/
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (10, 'Switchbox-GSM', 2, 'antrax')");
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (11, 'Key-Display', 3, 'Rika')");
//        //    query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (12, 'Touch-Display', 4, 'Rika')");
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (13, 'B2-Master', 5, 'TUTA')");
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (14, 'B2-Family', 5, 'TUTA')");
//            query.exec("INSERT INTO [tab_devices] ([d_id], [d_name], [d_typeID], [d_producer]) VALUES (15, 'G5', 1, 'Chuango')");

        }
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (1, 'LHD-8003', 1, 'LongHorn-CSST')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (2, 'DRH-301 (Master)', 2, 'GSM-One')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (3, 'DRH-301 (Family)', 2, 'GSM-One')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (4, 'AP801G', 2, 'OR')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (5, 'AMGOVIS GSM+', 1, 'AMG')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (6, 'ST-IVB', 1, 'iAlarm')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (7, 'FC-400', 1, 'iAlarm')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (8, 'GLS STIII-B', 1, 'FR')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (9, 'ST-VB', 1, 'iAlarm')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (10, 'Switchbox-GSM', 2, 'antrax')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (11, 'Touch-Less', 3, 'Rika')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (12, 'Touch', 3, 'Rika')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (13, 'B2 (Master)', 5, 'Tuta')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (14, 'B2 (Family)', 5, 'Tuta')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (15, 'G5', 1, 'Chuango')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, 'GS-M2C', 1, 'GlobalSafe')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, 'GS-M2BX', 1, 'GlobalSafe')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, '707', 2, 'iSocket')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, '706 Light', 2, 'iSocket')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, 'ENER022', 2, 'Energenie')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, 'AlarmBox-GSM', 2, 'antrax')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (18, 'S-30 (V2) (Master)', 2, 'Tuta')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, 'Touch-Less + Sensor', 3, 'Rika')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, 'B2 (Guest)', 5, 'Tuta')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, 'ME Control', 3, 'Mitsubishi')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (16, 'XMD-3200.pro', 1, 'VisorTech')");
    //    query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (, 'GSM Alarm System', 1, 'Euro1Supply')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (17, 'Powermaster-10', 1, 'Visonic')");
        query.exec("INSERT INTO tab_devices (d_id, d_name, d_typeID, d_producer) VALUES (19, 'S-30 (V2) (Family)', 2, 'Tuta')");

    }

    //devices_actions
    {
        //old
        {
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (1, 1, 1, 'Password__Status')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (2, 1, 2, 'Password__Armaway')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (3, 1, 3, 'Password__Armstay')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (4, 1, 4, 'Password__Disarm')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (5, 2, 16, '#000#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (6, 2, 5, '#01#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (7, 2, 6, '#02#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (8, 3, 16, '#000#__#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (9, 3, 5, '#01#__#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (10, 3, 6, '#02#__#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (11, 4, 7, 'SN__CHANGE')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (12, 4, 16, 'SN__CHECK')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (13, 4, 5, 'SN__ON')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (14, 4, 6, 'SN__OFF')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (15, 5, 1, '__check')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (16, 5, 2, '__arm')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (17, 5, 3, '__parm')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (18, 5, 4, '__disarm')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (19, 10, 5, 'On!__')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (20, 10, 6, 'Off!__')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (21, 10, 16, 'Status?__')");
//    query.exec("INSERT INTO tab_devicesactions ([da_id], [da_deviceID], [da_actionID], [da_command]) VALUES (22, 10, 7, 'Reset!__')");
//    //query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (11, x, '__ TEL')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (11, 5, '__ ON')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (11, 6, '__ OFF')");

//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (13, 1, '#07#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (13, 14, '#03#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (13, 9, '#01#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (13, 4, '#02#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (13, 10, '#128#1#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (13, 11, '#128#0#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (13, 12, '#118#1#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (13, 13, '#118#0#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (13, 15, '#03#1#1#')");

//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (14, 1, '#07#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (14, 14, '#03#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (14, 9, '#01#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (14, 4, '#02#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (14, 10, '#128#1#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (14, 11, '#128#0#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (14, 12, '#118#1#')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (14, 13, '#118#0#')");

//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (15, 1, '00')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (15, 2, '1')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (15, 3, '2')");
//    query.exec("INSERT INTO tab_devicesactions ([da_deviceID], [da_actionID], [da_command]) VALUES (15, 4, '0')");
        }

        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (1, 2, 'Password__Armaway')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (1, 3, 'Password__Armstay')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (1, 4, 'Password__Disarm')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (1, 1, 'Password__Status')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (4, 7, 'SN__CHANGE')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (4, 16, 'SN__CHECK')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (4, 5, 'SN__ON')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (4, 6, 'SN__OFF')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (5, 1, '__check')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (5, 2, '__arm')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (5, 3, '__parm')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (5, 4, '__disarm')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (10, 5, 'On!__')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (10, 6, 'Off!__')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (10, 16, 'Status?__')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (10, 7, 'Reset!__')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (11, 17, '__ ON')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (11, 18, '__ OFF')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (13, 19, '#07#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (13, 14, '#03#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (13, 9, '#01#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (13, 20, '#02#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (13, 10, '#128#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (13, 11, '#128#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (13, 12, '#118#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (13, 13, '#118#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (13, 15, '#03#1#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (14, 19, '#07#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (14, 14, '#03#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (14, 9, '#01#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (14, 20, '#02#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (14, 10, '#128#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (14, 11, '#128#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (14, 12, '#118#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (14, 13, '#118#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 2, '1')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 3, '2')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 4, '0')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 31, '3')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 24, '11')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 32, '12')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 1, '00')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 27, '?')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 37, '??')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 38, '???')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 33, '7')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 34, '8')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 35, '10')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (15, 36, '13')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (6, 1, 'password:__\n system status')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (6, 2, 'password:__\n system arm')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (6, 3, 'password:__\n system home')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (6, 4, 'password:__\n system disarm')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (6, 21, 'password:__\n alarm cancel')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 2, '1')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 4, '0')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 22, '2')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 23, '3')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 24, '5')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 26, '62')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 25, '61')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 27, '?')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 30, '0001')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 28, '0049')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (16, 29, '0033')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (17, 2, 'AW __')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (17, 4, 'DA __')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (17, 3, 'HM __')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (17, 1, 'ST __')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (17, 42, 'LK __')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (17, 43, 'LKI __')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (17, 39, 'AWI __')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (17, 40, 'HMI __')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (17, 44, 'HN __ {replace with new ID}')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 16, '#07#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 5, '#01#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 6, '#02#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 45, '#128#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 46, '#128#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 47, '#129#WorkDay#StartTime#EndTime#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 48, '#159#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 49, '#159#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 50, '#159#Mode#LowTemp#HighTemp#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 51, '#170#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 52, '#170#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 53, '#170#MinTemp#MaxTemp#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 54, '#160#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 55, '#160#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 56, '#160#Temp#Time#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 57, '#11#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 58, '#11#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 59, '#12#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 60, '#12#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 61, '#19#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (18, 62, '#19#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 16, '#07#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 5, '#01#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 6, '#02#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 45, '#128#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 46, '#128#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 47, '#129#WorkDay#StartTime#EndTime#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 48, '#159#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 49, '#159#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 50, '#159#Mode#LowTemp#HighTemp#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 51, '#170#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 52, '#170#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 53, '#170#MinTemp#MaxTemp#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 54, '#160#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 55, '#160#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 56, '#160#Temp#Time#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 57, '#11#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 58, '#11#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 59, '#12#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 60, '#12#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 61, '#19#1#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (2, 62, '#19#0#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (3, 16, '#000#__#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (3, 5, '#01#__#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (3, 6, '#02#__#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (19, 16, '#000#__#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (19, 5, '#01#__#')");
        query.exec("INSERT INTO tab_devicesactions (da_deviceID, da_actionID, da_command) VALUES (19, 6, '#02#__#')");

    }

// INDEX
    query.exec("CREATE UNIQUE INDEX PK ON tab_devicesactions ( "
               "da_id ASC "
               ")");

    return true;
}

#endif
