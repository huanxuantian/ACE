/* -*- C++ -*- */
//=============================================================================
/**
 *  @file   Supplier.h
 *
 *  $Id: Supplier.h 93658 2011-03-28 11:22:55Z johnnyw $
 *
 *  @author Carlos O'Ryan (coryan@cs.wustl.edu)
 */
//=============================================================================


#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "orbsvcs/CosEventCommS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

/**
 * @class Supplier
 *
 * @brief Simple supplier object
 *
 * This class is a supplier of events.
 */
class Supplier : public POA_CosEventComm::PushSupplier
{
public:
  /// Constructor
  Supplier (void);

  /// Run the test
  int run (int argc, ACE_TCHAR* argv[]);

  // = The CosEventComm::PushSupplier methods

  /// The skeleton methods.
  virtual void disconnect_push_supplier (void);

private:
};

#endif /* SUPPLIER_H */