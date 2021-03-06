// $Id: Convert_Plan_Impl.h 91982 2010-09-23 20:43:54Z wotte $

/**
 * @file Convert_Plan_Impl.h
 *
 * @author William R. Otte <wotte@dre.vanderbilt.edu>
 */

#ifndef DANCE_CONVERT_PLAN_H
#define DANCE_CONVERT_PLAN_H

#include "Convert_Plan/DAnCE_Convert_Plan_export.h"
#include "dance/Deployment/Deployment_DeploymentPlanC.h"

namespace DAnCE
{
  class DAnCE_Convert_Plan_Export Convert_Plan
  {
  public:
    static Deployment::DeploymentPlan * read_xml_plan (const ACE_TCHAR *filename);
    static Deployment::DeploymentPlan * read_cdr_plan (const ACE_TCHAR *filename);
    static bool write_cdr_plan (const ACE_TCHAR *filename, Deployment::DeploymentPlan &plan);
  };
}

#endif
