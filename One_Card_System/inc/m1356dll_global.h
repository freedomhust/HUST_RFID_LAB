#ifndef M1356DLL_GLOBAL_H
#define M1356DLL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(M1356DLL_LIBRARY)
#  define M1356DLLSHARED_EXPORT Q_DECL_EXPORT
#else
#  define M1356DLLSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // M1356DLL_GLOBAL_H
