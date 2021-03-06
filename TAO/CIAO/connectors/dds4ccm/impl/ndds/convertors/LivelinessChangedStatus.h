/**
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 * @author Johnny Willemsen (jwillemsen@remedy.nl)
 *
 * $Id: LivelinessChangedStatus.h 95809 2012-06-03 17:56:00Z johnnyw $
 *
 * Wrapper facade for NDDS.
 */

#ifndef DDS4CCM_LIVELINESSCHANGEDSTATUS_H
#define DDS4CCM_LIVELINESSCHANGEDSTATUS_H

#include "InstanceHandle_t.h"
#include "dds4ccm/impl/dds4ccm_conf.h"

inline void
operator<<= (::DDS::LivelinessChangedStatus &ddsstatus, const ::DDS_LivelinessChangedStatus & status)
{
  ddsstatus.alive_count = status.alive_count;
  ddsstatus.not_alive_count = status.not_alive_count;
  ddsstatus.alive_count_change = status.alive_count_change;
  ddsstatus.not_alive_count_change = status.not_alive_count_change;
  ddsstatus.last_publication_handle <<= status.last_publication_handle;
}

inline void
operator<<= (::DDS_LivelinessChangedStatus &ddsstatus, const ::DDS::LivelinessChangedStatus & status)
{
  ddsstatus.alive_count = status.alive_count;
  ddsstatus.not_alive_count = status.not_alive_count;
  ddsstatus.alive_count_change = status.alive_count_change;
  ddsstatus.not_alive_count_change = status.not_alive_count_change;
  ddsstatus.last_publication_handle <<= status.last_publication_handle;
}

#endif /* DDS4CCM_LIVELINESSCHANGEDSTATUS_H */
