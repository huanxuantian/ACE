// $Id: CIAO_Handler_Common.cpp 96013 2012-08-07 12:47:56Z johnnyw $
#include "CIAO_Handler_Common.h"

#include "dance/Deployment/Deployment_PlanErrorC.h"
#include "ciao/Logger/Log_Macros.h"
#include "ciao/Valuetype_Factories/ConfigValue.h"

namespace CIAO
{
  const char *
  Deployment_Common::get_implementation (const char *name,
                                         const ::Deployment::DeploymentPlan &plan)
  {
    if (name == 0)
      {
        throw ::Deployment::PlanError (name,
                                      "No such artifact");
      }

    for (CORBA::ULong i = 0;
         i < plan.artifact.length ();
         ++i)
      {
        if (ACE_OS::strcmp (plan.artifact[i].name.in (),
                            name) == 0)
          {
            if (plan.artifact[i].location.length () >= 1 &&
                plan.artifact[i].location[0] != 0)
              {
                return plan.artifact[i].location[0].in ();
              }
            else
              {
                CIAO_ERROR (1, (LM_ERROR, CLINFO
                                "Deployment_Common::get_implementation - "
                                "No valid location for artifact <%C>\n",
                                name));
                throw ::Deployment::PlanError (name,
                                               "No valid location field\n");
              }
          }
      }

    CIAO_ERROR (1, (LM_ERROR, CLINFO
                    "Deployment_Common::get_implementation - "
                    "Unable to locate artifact <%C>\n",
                    name));

    throw ::Deployment::PlanError (name,
                                   "Nonexistent artifact");
  }

  void
  Deployment_Common::create_attribute_configuration (const ::Deployment::Properties &props,
                                                     ::Components::ConfigValues & values)
  {
    values.length (props.length ());

    for (CORBA::ULong i = 0;
         i < props.length ();
         ++i)
      {
        values[i] = new CIAO::ConfigValue_impl (props[i].name.in (),
                                                props[i].value);
      }
  }
}
