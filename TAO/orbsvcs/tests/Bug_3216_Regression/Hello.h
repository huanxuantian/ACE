//
// $Id: Hello.h 95052 2011-11-17 10:11:20Z mcorino $
//

#ifndef HELLO_H
#define HELLO_H
#include /**/ "ace/pre.h"

#include "TestS.h"

#if defined (_MSC_VER)
# pragma warning(push)
# pragma warning (disable:4250)
#endif /* _MSC_VER */

/// Implement the Test::Hello interface
class Hello
  : public virtual POA_Test::Hello
{
public:
  /// Constructor
  Hello (CORBA::ORB_ptr orb);

  // = The skeleton methods
  virtual void shutdown ();

  virtual void check_normal_context ();

  virtual void check_extended_context ();

  static CORBA::Boolean normal_context_ok_;

  static CORBA::Boolean extended_context_ok_;

private:
  /// Use an ORB reference to convert strings to objects and shutdown
  /// the application.
  CORBA::ORB_var orb_;
};

#if defined(_MSC_VER)
# pragma warning(pop)
#endif /* _MSC_VER */

#include /**/ "ace/post.h"
#endif /* HELLO_H */
