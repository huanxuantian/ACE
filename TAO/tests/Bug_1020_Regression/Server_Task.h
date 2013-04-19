//
// $Id: Server_Task.h 51175 2003-07-21 23:51:40Z dhinton $
//

#ifndef Server_Task__h_
#define Server_Task__h_
#include /**/ "ace/pre.h"

#include "TestC.h"
#include "ace/Task.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class Server_Task : public ACE_Task_Base
{
public:
  /// Constructor
  Server_Task (Test::Echo_ptr echo);

  /// Thread entry point
  int svc (void);

private:
  /// Reference to the test interface
  Test::Echo_var echo_;
};

#include /**/ "ace/post.h"
#endif /* Server_Task__h_ */