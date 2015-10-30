/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
#ifndef Q_ZFRAME_H
#define Q_ZFRAME_H

#include "qczmq.h"

class QT_CZMQ_EXPORT QZframe : public QObject
{
    Q_OBJECT
public:

    //  Copy-construct to return the proper wrapped c types
    QZframe (zframe_t *self, QObject *qObjParent = 0);

    //  Create a new frame. If size is not null, allocates the frame data
    //  to the specified size. If additionally, data is not null, copies 
    //  size octets from the specified data into the frame body.         
    explicit QZframe (const void *data, size_t size, QObject *qObjParent = 0);

    //  Destroy a frame
    ~QZframe ();

    //  Create an empty (zero-sized) frame
    static QZframe * newEmpty ();

    //  Create a frame with a specified string content.
    static QZframe * from (const QString &string);

    //  Receive frame from socket, returns zframe_t object or NULL if the recv  
    //  was interrupted. Does a blocking recv, if you want to not block then use
    //  zpoller or zloop.                                                       
    static QZframe * recv (void *source);

    //  Send a frame to a socket, destroy frame after sending.
    //  Return -1 on error, 0 on success.                     
    int send (void *dest, int flags);

    //  Return number of bytes in frame data
    size_t size ();

    //  Return address of frame data
    byte * data ();

    //  Create a new frame that duplicates an existing frame. If frame is null,
    //  or memory was exhausted, returns null.                                 
    QZframe * dup ();

    //  Return frame data encoded as printable hex string, useful for 0MQ UUIDs.
    //  Caller must free string when finished with it.                          
    QString strhex ();

    //  Return frame data copied into freshly allocated string
    //  Caller must free string when finished with it.        
    QString strdup ();

    //  Return TRUE if frame body is equal to string, excluding terminator
    bool streqNoConflict (const QString &string);

    //  Return frame MORE indicator (1 or 0), set when reading frame from socket
    //  or by the zframe_set_more() method                                      
    int more ();

    //  Set frame MORE indicator (1 or 0). Note this is NOT used when sending
    //  frame to socket, you have to specify flag explicitly.                
    void setMore (int more);

    //  Return frame routing ID, if the frame came from a ZMQ_SERVER socket.
    //  Else returns zero.                                                  
    quint32 routingId ();

    //  Set routing ID on frame. This is used if/when the frame is sent to a
    //  ZMQ_SERVER socket.                                                  
    void setRoutingId (quint32 routingId);

    //  Return TRUE if two frames have identical size and data
    //  If either frame is NULL, equality is always false.    
    bool eq (QZframe *other);

    //  Set new contents for frame
    void reset (const void *data, size_t size);

    //  Send message to zsys log sink (may be stdout, or system facility as       
    //  configured by zsys_set_logstream). Prefix shows before frame, if not null.
    void print (const QString &prefix);

    //  Probe the supplied object, and report if it looks like a zframe_t.
    static bool is (void *self);

    //  Self test of this class
    static void test (bool verbose);

    zframe_t *self;
};
#endif //  Q_ZFRAME_H
/*
################################################################################
#  THIS FILE IS 100% GENERATED BY ZPROJECT; DO NOT EDIT EXCEPT EXPERIMENTALLY  #
#  Please refer to the README for information about making permanent changes.  #
################################################################################
*/
