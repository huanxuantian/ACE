// -*- C++ -*-
// $Id: DDS_Listen_T.cpp 97302 2013-08-29 11:15:22Z johnnyw $

#include "dds4ccm/impl/DataListenerControl_T.h"
#include "dds4ccm/impl/DataReaderListener_T.h"
#include "dds4ccm/impl/logger/Log_Macros.h"

template <typename CCM_TYPE, typename TYPED_DDS_READER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE, CIAO::DDS4CCM::DDS4CCM_LISTENER_READ_TAKE LRT>
DDS_Listen_T<CCM_TYPE, TYPED_DDS_READER, VALUE_TYPE, SEQ_VALUE_TYPE, LRT>::DDS_Listen_T (void)
{
}

template <typename CCM_TYPE, typename TYPED_DDS_READER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE, CIAO::DDS4CCM::DDS4CCM_LISTENER_READ_TAKE LRT>
DDS_Listen_T<CCM_TYPE, TYPED_DDS_READER, VALUE_TYPE, SEQ_VALUE_TYPE, LRT>::~DDS_Listen_T (void)
{
}

template <typename CCM_TYPE, typename TYPED_DDS_READER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE, CIAO::DDS4CCM::DDS4CCM_LISTENER_READ_TAKE LRT>
void
DDS_Listen_T<CCM_TYPE, TYPED_DDS_READER, VALUE_TYPE, SEQ_VALUE_TYPE, LRT>::set_component (
    ::CORBA::Object_ptr component)
{
  DDS_Subscriber_Base_T<CCM_TYPE, TYPED_DDS_READER, VALUE_TYPE, SEQ_VALUE_TYPE>::set_component (component);
  this->data_control_->_set_component (component);
}

template <typename CCM_TYPE, typename TYPED_DDS_READER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE, CIAO::DDS4CCM::DDS4CCM_LISTENER_READ_TAKE LRT>
void
DDS_Listen_T<CCM_TYPE, TYPED_DDS_READER, VALUE_TYPE, SEQ_VALUE_TYPE, LRT>::activate (
  typename CCM_TYPE::data_listener_type::_ptr_type listener,
  ::CCM_DDS::PortStatusListener_ptr status,
  ACE_Reactor* reactor)
{
  DDS4CCM_TRACE ("DDS_Listen_T::activate");

  ::DDS::StatusMask const mask =
    DataReaderListener_type::get_mask (listener, status);

  if (mask != 0)
    {
      if (::CORBA::is_nil (this->listener_.in ()))
        {
          ACE_NEW_THROW_EX (this->listener_,
                            DataReaderListener_type (
                              listener,
                              status,
                              this->data_control_,
                              reactor,
                              this->condition_manager_),
                            ::CORBA::NO_MEMORY ());
        }
      ::DDS::DataReader_var dr = this->dds_read_->get_dds_reader ();
      if (!::CORBA::is_nil (dr.in ()))
        {
          ::DDS::ReturnCode_t const retcode = dr->set_listener (
            this->listener_.in (), mask);

          if (retcode != ::DDS::RETCODE_OK)
            {
              DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                            "DDS_Listen_T::activate - "
                            "Error while setting the listener on the listen - <%C>\n",
                            ::CIAO::DDS4CCM::translate_retcode (retcode)));
              throw ::CORBA::INTERNAL ();
            }
        }
      else
        {
          DDS4CCM_ERROR (DDS4CCM_LOG_LEVEL_ERROR, (LM_ERROR, DDS4CCM_INFO
                        "DDS_Listen_T::activate - "
                        "Error while retrieving the DataReader\n"));
          throw ::CORBA::INTERNAL ();
        }
    }
}

template <typename CCM_TYPE, typename TYPED_DDS_READER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE, CIAO::DDS4CCM::DDS4CCM_LISTENER_READ_TAKE LRT>
void
DDS_Listen_T<CCM_TYPE, TYPED_DDS_READER, VALUE_TYPE, SEQ_VALUE_TYPE, LRT>::remove (
  ::DDS::Subscriber_ptr subscriber)
{
  DDS4CCM_TRACE ("DDS_Listen_T::remove");

  SubscriberBase_type::remove (subscriber);
}

template <typename CCM_TYPE, typename TYPED_DDS_READER, typename VALUE_TYPE, typename SEQ_VALUE_TYPE, CIAO::DDS4CCM::DDS4CCM_LISTENER_READ_TAKE LRT>
::CCM_DDS::CCM_DataListenerControl_ptr
DDS_Listen_T<CCM_TYPE, TYPED_DDS_READER, VALUE_TYPE, SEQ_VALUE_TYPE, LRT>::get_data_control (void)
{
  DDS4CCM_TRACE ("DDS_Listen_T::get_data_control");

  return ::CCM_DDS::CCM_DataListenerControl::_duplicate (this->data_control_);
}

