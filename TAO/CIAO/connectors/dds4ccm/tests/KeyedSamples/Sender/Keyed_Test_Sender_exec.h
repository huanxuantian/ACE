// -*- C++ -*-
// $Id: Keyed_Test_Sender_exec.h 97302 2013-08-29 11:15:22Z johnnyw $

#ifndef CIAO_KEYED_TEST_SENDER_EXEC_LVAFIH_H_
#define CIAO_KEYED_TEST_SENDER_EXEC_LVAFIH_H_

#include /**/ "ace/pre.h"

#include "Keyed_Test_SenderEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include /**/ "Sender_exec_export.h"
#include "tao/LocalObject.h"

#include <map>

namespace CIAO_Keyed_Test_Sender_Impl
{
  typedef ACE_Atomic_Op <TAO_SYNCH_MUTEX, CORBA::Boolean > Atomic_Boolean;
  class Sender_exec_i;

  /**
   * ConnectorStatusListener_exec_i
   */
  class SENDER_EXEC_Export ConnectorStatusListener_exec_i
    : public virtual ::CCM_DDS::CCM_ConnectorStatusListener,
      public virtual ::CORBA::LocalObject
  {
  public:
    ConnectorStatusListener_exec_i (Sender_exec_i &callback);
    virtual ~ConnectorStatusListener_exec_i (void);

    virtual
    void on_inconsistent_topic (::DDS::Topic_ptr the_topic,
                                const DDS::InconsistentTopicStatus & status);
    virtual
    void on_requested_incompatible_qos (::DDS::DataReader_ptr the_reader,
                                        const DDS::RequestedIncompatibleQosStatus & status);
    virtual
    void on_sample_rejected (::DDS::DataReader_ptr the_reader,
                             const DDS::SampleRejectedStatus & status);
    virtual
      void on_offered_deadline_missed (::DDS::DataWriter_ptr the_writer,
                                       const DDS::OfferedDeadlineMissedStatus & status);
    virtual
    void on_offered_incompatible_qos (::DDS::DataWriter_ptr the_writer,
                                      const DDS::OfferedIncompatibleQosStatus & status);
    virtual
      void on_unexpected_status (::DDS::Entity_ptr the_entity,
                                 ::DDS::StatusKind status_kind);
  private:
    Sender_exec_i &callback_;
  };

  /**
   * Write generator
   */

  class pulse_Generator :
    public ACE_Event_Handler
  {
  public:
    pulse_Generator (Sender_exec_i &callback);
    virtual int handle_timeout (const ACE_Time_Value &tv,
                                const void *arg);
  private:
    Sender_exec_i &pulse_callback_;
  };


  /**
   * Component Executor Implementation Class: Sender_exec_i
   */

  class Sender_exec_i
    : public virtual Sender_Exec,
      public virtual ::CORBA::LocalObject
  {
  public:
    Sender_exec_i (void);
    virtual ~Sender_exec_i (void);

    //@{
    /** Supported operations and attributes. */

    //@}

    //@{
    /** Component attributes and port operations. */
    virtual ::CCM_DDS::CCM_ConnectorStatusListener_ptr
    get_connector_status (void);

    virtual ::CORBA::ULong rate (void);

    virtual void rate (::CORBA::ULong rate);

    virtual ::CORBA::UShort keys (void);

    virtual void keys (::CORBA::UShort keys);

    virtual ::CORBA::UShort iterations (void);

    virtual void iterations (::CORBA::UShort iterations);
    //@}

    //@{
    /** Operations from Components::SessionComponent. */
    virtual void set_session_context (::Components::SessionContext_ptr ctx);
    virtual void configuration_complete (void);
    virtual void ccm_activate (void);
    virtual void ccm_passivate (void);
    virtual void ccm_remove (void);
    //@}

    //@{
    /** User defined public operations. */
    void get_started (void);
    void tick (void);

    //@}

  private:
    ::Keyed_Test::CCM_Sender_Context_var ciao_context_;

    //@{
    /** Component attributes. */

    ::CORBA::ULong rate_;

    ::CORBA::UShort keys_;

    ::CORBA::UShort iterations_;
    //@}

    //@{
    /** User defined members. */
    void start (void);
    void stop (void);

    pulse_Generator * ticker_;

    TAO_SYNCH_MUTEX mutex_;
    typedef std::map<ACE_CString, KeyedTest_var> Keyed_Test_Table;

    Keyed_Test_Table ktests_;
    Keyed_Test_Table::iterator last_key_;
    Atomic_Boolean ready_to_start_;
    //@}

    //@{
    /** User defined private operations. */

    //@}

    /// Get the ACE_Reactor
    ACE_Reactor* reactor (void);
  };

  extern "C" SENDER_EXEC_Export ::Components::EnterpriseComponent_ptr
  create_Keyed_Test_Sender_Impl (void);
}

#include /**/ "ace/post.h"

#endif /* ifndef */
