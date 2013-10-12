/*
 * Copyright (C) 2008-2013 The Communi Project
 *
 * This example is free, and not covered by the LGPL license. There is no
 * restriction applied to their modification, redistribution, using and so on.
 * You can study them, modify them, use them in your own program - either
 * completely or partially.
 */

#include <QtCore>
#include <IrcConnection>
#include <IrcCommand>
#include <Irc>

int main(int argc, char* argv[])
{
    QCoreApplication app(argc, argv);
    qsrand(QTime::currentTime().msec());

//! [minimal]
    IrcConnection connection("irc.freenode.net");
    connection.setUserName("communi");
    connection.setNickName(QString("Minimal%1").arg(qrand()));
    connection.setRealName(QString("Communi %1 minimal example").arg(Irc::version()));
    connection.sendCommand(IrcCommand::createJoin("#communi"));
    connection.sendCommand(IrcCommand::createMessage("#communi", "Hi, kthxbye!"));
    connection.sendCommand(IrcCommand::createQuit());
    connection.open();
//! [minimal]

    QObject::connect(&connection, SIGNAL(disconnected()), &app, SLOT(quit()));
    return app.exec();
}