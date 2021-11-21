#include "cengliuyuanguanApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
cengliuyuanguanApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

cengliuyuanguanApp::cengliuyuanguanApp(InputParameters parameters) : MooseApp(parameters)
{
  cengliuyuanguanApp::registerAll(_factory, _action_factory, _syntax);
}

cengliuyuanguanApp::~cengliuyuanguanApp() {}

void
cengliuyuanguanApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"cengliuyuanguanApp"});
  Registry::registerActionsTo(af, {"cengliuyuanguanApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
cengliuyuanguanApp::registerApps()
{
  registerApp(cengliuyuanguanApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
cengliuyuanguanApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  cengliuyuanguanApp::registerAll(f, af, s);
}
extern "C" void
cengliuyuanguanApp__registerApps()
{
  cengliuyuanguanApp::registerApps();
}
