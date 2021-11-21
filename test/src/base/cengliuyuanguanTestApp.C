//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "cengliuyuanguanTestApp.h"
#include "cengliuyuanguanApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
cengliuyuanguanTestApp::validParams()
{
  InputParameters params = cengliuyuanguanApp::validParams();
  return params;
}

cengliuyuanguanTestApp::cengliuyuanguanTestApp(InputParameters parameters) : MooseApp(parameters)
{
  cengliuyuanguanTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

cengliuyuanguanTestApp::~cengliuyuanguanTestApp() {}

void
cengliuyuanguanTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  cengliuyuanguanApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"cengliuyuanguanTestApp"});
    Registry::registerActionsTo(af, {"cengliuyuanguanTestApp"});
  }
}

void
cengliuyuanguanTestApp::registerApps()
{
  registerApp(cengliuyuanguanApp);
  registerApp(cengliuyuanguanTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
cengliuyuanguanTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  cengliuyuanguanTestApp::registerAll(f, af, s);
}
extern "C" void
cengliuyuanguanTestApp__registerApps()
{
  cengliuyuanguanTestApp::registerApps();
}
