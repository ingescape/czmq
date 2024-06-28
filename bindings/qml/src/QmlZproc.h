/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/

#ifndef QML_ZPROC_H
#define QML_ZPROC_H

#include <QtQml>

#include <czmq.h>
#include "qml_czmq_plugin.h"


class QmlZproc : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isNULL READ isNULL)

public:
    zproc_t *self;

    QmlZproc() { self = NULL; }
    bool isNULL() { return self == NULL; }

    static QObject* qmlAttachedProperties(QObject* object); // defined in QmlZproc.cpp

public slots:
    //  Return command line arguments (the first item is the executable) or
    //  NULL if not set.
    QmlZlist *args ();

    //  Setup the command line arguments, the first item must be an (absolute) filename
    //  to run.
    void setArgs (QmlZlist *arguments);

    //  Setup the command line arguments, the first item must be an (absolute) filename
    //  to run. Variadic function, must be NULL terminated.
    void setArgsx (const QString &arguments);

    //  Setup the environment variables for the process.
    void setEnv (QmlZhash *arguments);

    //  Connects process stdin with a readable ('>', connect) zeromq socket. If
    //  socket argument is NULL, zproc creates own managed pair of inproc
    //  sockets.  The writable one is then accessible via zproc_stdin method.
    void setStdin (void *socket);

    //  Connects process stdout with a writable ('@', bind) zeromq socket. If
    //  socket argument is NULL, zproc creates own managed pair of inproc
    //  sockets.  The readable one is then accessible via zproc_stdout method.
    void setStdout (void *socket);

    //  Connects process stderr with a writable ('@', bind) zeromq socket. If
    //  socket argument is NULL, zproc creates own managed pair of inproc
    //  sockets.  The readable one is then accessible via zproc_stderr method.
    void setStderr (void *socket);

    //  Return subprocess stdin writable socket. NULL for
    //  not initialized or external sockets.
    void *stdin ();

    //  Return subprocess stdout readable socket. NULL for
    //  not initialized or external sockets.
    void *stdout ();

    //  Return subprocess stderr readable socket. NULL for
    //  not initialized or external sockets.
    void *stderr ();

    //  Starts the process, return just before execve/CreateProcess.
    int run ();

    //  process exit code
    int returncode ();

    //  PID of the process
    int pid ();

    //  return true if process is running, false if not yet started or finished
    bool running ();

    //  The timeout should be zero or greater, or -1 to wait indefinitely.
    //  wait or poll process status, return return code
    int wait (int timeout);

    //  send SIGTERM signal to the subprocess, wait for grace period and
    //  eventually send SIGKILL
    void shutdown (int timeout);

    //  return internal actor, useful for the polling if process died
    void *actor ();

    //  send a signal to the subprocess
    void kill (int signal);

    //  set verbose mode
    void setVerbose (bool verbose);
};

class QmlZprocAttached : public QObject
{
    Q_OBJECT
    QObject* m_attached;

public:
    QmlZprocAttached (QObject* attached) {
        Q_UNUSED (attached);
    };

public slots:
    //  Self test of this class.
    void test (bool verbose);

    //  Create a new zproc.
    //  NOTE: On Windows and with libzmq3 and libzmq2 this function
    //  returns NULL. Code needs to be ported there.
    QmlZproc *construct ();

    //  Destroy zproc, wait until process ends.
    void destruct (QmlZproc *qmlSelf);
};


QML_DECLARE_TYPEINFO(QmlZproc, QML_HAS_ATTACHED_PROPERTIES)

#endif
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Read the zproject/README.md for information about making permanent changes. #
################################################################################
*/
