// $Id: common.h 82878 2008-09-29 18:02:01Z johnnyw $

#ifndef common_h
#define common_h

#include "tao/ORB.h"

CORBA::ORB_ptr initialize_orb_and_poa(int & argc, ACE_TCHAR * argv[]);
void report_exception();

#endif // common_h

