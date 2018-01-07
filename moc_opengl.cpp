/****************************************************************************
** Meta object code from reading C++ file 'opengl.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "opengl.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'opengl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Opengl[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      10,    8,    7,    7, 0x0a,
      30,    8,    7,    7, 0x0a,
      50,    8,    7,    7, 0x0a,
      70,    8,    7,    7, 0x0a,
      90,    8,    7,    7, 0x0a,
     110,    8,    7,    7, 0x0a,
     130,    7,    7,    7, 0x0a,
     140,    7,    7,    7, 0x0a,
     154,    7,    7,    7, 0x0a,
     168,    7,    7,    7, 0x0a,
     182,    7,    7,    7, 0x0a,
     196,    7,    7,    7, 0x0a,
     207,    7,    7,    7, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Opengl[] = {
    "Opengl\0\0n\0changerXmin(double)\0"
    "changerXmax(double)\0changerYmin(double)\0"
    "changerYmax(double)\0changerZmax(double)\0"
    "changerGran(double)\0refresh()\0"
    "enregistrer()\0mandelbrot1()\0juliafatou1()\0"
    "juliafatou2()\0zoomFunc()\0dezoomFunc()\0"
};

void Opengl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Opengl *_t = static_cast<Opengl *>(_o);
        switch (_id) {
        case 0: _t->changerXmin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->changerXmax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->changerYmin((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->changerYmax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->changerZmax((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->changerGran((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->refresh(); break;
        case 7: _t->enregistrer(); break;
        case 8: _t->mandelbrot1(); break;
        case 9: _t->juliafatou1(); break;
        case 10: _t->juliafatou2(); break;
        case 11: _t->zoomFunc(); break;
        case 12: _t->dezoomFunc(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Opengl::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Opengl::staticMetaObject = {
    { &GLWidget::staticMetaObject, qt_meta_stringdata_Opengl,
      qt_meta_data_Opengl, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Opengl::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Opengl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Opengl::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Opengl))
        return static_cast<void*>(const_cast< Opengl*>(this));
    if (!strcmp(_clname, "Dessin"))
        return static_cast< Dessin*>(const_cast< Opengl*>(this));
    return GLWidget::qt_metacast(_clname);
}

int Opengl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = GLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
