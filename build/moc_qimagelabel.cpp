/****************************************************************************
** Meta object code from reading C++ file 'qimagelabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../imageLabel/qimagelabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qimagelabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QImageLabel_t {
    QByteArrayData data[6];
    char stringdata0[45];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QImageLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QImageLabel_t qt_meta_stringdata_QImageLabel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "QImageLabel"
QT_MOC_LITERAL(1, 12, 14), // "sendMousePoint"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "MouseType"
QT_MOC_LITERAL(4, 38, 4), // "type"
QT_MOC_LITERAL(5, 43, 1) // "p"

    },
    "QImageLabel\0sendMousePoint\0\0MouseType\0"
    "type\0p"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QImageLabel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QPoint,    4,    5,

       0        // eod
};

void QImageLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        QImageLabel *_t = static_cast<QImageLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendMousePoint((*reinterpret_cast< MouseType(*)>(_a[1])),(*reinterpret_cast< QPoint(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (QImageLabel::*_t)(MouseType , QPoint );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&QImageLabel::sendMousePoint)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject QImageLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_QImageLabel.data,
      qt_meta_data_QImageLabel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *QImageLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QImageLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_QImageLabel.stringdata0))
        return static_cast<void*>(const_cast< QImageLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int QImageLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QImageLabel::sendMousePoint(MouseType _t1, QPoint _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
