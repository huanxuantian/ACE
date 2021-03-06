
// -*- C++ -*-
// $Id: DllOrb_Export.h 75791 2006-12-04 18:07:53Z iliyan $
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl DllOrb
// ------------------------------
#ifndef DLLORB_EXPORT_H
#define DLLORB_EXPORT_H

#include "ace/config-all.h"

#if defined (ACE_AS_STATIC_LIBS) && !defined (DLLORB_HAS_DLL)
#  define DLLORB_HAS_DLL 0
#endif /* ACE_AS_STATIC_LIBS && DLLORB_HAS_DLL */

#if !defined (DLLORB_HAS_DLL)
#  define DLLORB_HAS_DLL 1
#endif /* ! DLLORB_HAS_DLL */

#if defined (DLLORB_HAS_DLL) && (DLLORB_HAS_DLL == 1)
#  if defined (DLLORB_BUILD_DLL)
#    define DllOrb_Export ACE_Proper_Export_Flag
#    define DLLORB_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define DLLORB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* DLLORB_BUILD_DLL */
#    define DllOrb_Export ACE_Proper_Import_Flag
#    define DLLORB_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define DLLORB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* DLLORB_BUILD_DLL */
#else /* DLLORB_HAS_DLL == 1 */
#  define DllOrb_Export
#  define DLLORB_SINGLETON_DECLARATION(T)
#  define DLLORB_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* DLLORB_HAS_DLL == 1 */

// Set DLLORB_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (DLLORB_NTRACE)
#  if (ACE_NTRACE == 1)
#    define DLLORB_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define DLLORB_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !DLLORB_NTRACE */

#if (DLLORB_NTRACE == 1)
#  define DLLORB_TRACE(X)
#else /* (DLLORB_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define DLLORB_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (DLLORB_NTRACE == 1) */

#endif /* DLLORB_EXPORT_H */

// End of auto generated file.
