#include "Example1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
Example1App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

Example1App::Example1App(InputParameters parameters) : MooseApp(parameters)
{
  Example1App::registerAll(_factory, _action_factory, _syntax);
}

Example1App::~Example1App() {}

void 
Example1App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<Example1App>(f, af, s);
  Registry::registerObjectsTo(f, {"Example1App"});
  Registry::registerActionsTo(af, {"Example1App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
Example1App::registerApps()
{
  registerApp(Example1App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
Example1App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Example1App::registerAll(f, af, s);
}
extern "C" void
Example1App__registerApps()
{
  Example1App::registerApps();
}
