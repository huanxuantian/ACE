// $Id: ComponentModuleDef_i.cpp 91682 2010-09-09 07:20:23Z johnnyw $

#include "orbsvcs/IFRService/ComponentModuleDef_i.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

TAO_ComponentModuleDef_i::TAO_ComponentModuleDef_i (TAO_Repository_i *repo)
  : TAO_IRObject_i (repo),
    TAO_Container_i (repo),
    TAO_ComponentContainer_i (repo)
{
}

TAO_ComponentModuleDef_i::~TAO_ComponentModuleDef_i (void)
{
}

TAO_END_VERSIONED_NAMESPACE_DECL
