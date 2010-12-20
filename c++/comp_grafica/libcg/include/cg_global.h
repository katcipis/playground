#ifndef CG_GLOBAL_H
#define CG_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(CG_LIBRARY)
#  define CGSHARED_EXPORT Q_DECL_EXPORT
#else
#  define CGSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // CG_GLOBAL_H
