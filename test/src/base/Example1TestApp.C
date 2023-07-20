//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "Example1TestApp.h"
#include "Example1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
Example1TestApp::validParams()
{
  InputParameters params = Example1App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

Example1TestApp::Example1TestApp(InputParameters parameters) : MooseApp(parameters)
{
  Example1TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

Example1TestApp::~Example1TestApp() {}

void
Example1TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  Example1App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"Example1TestApp"});
    Registry::registerActionsTo(af, {"Example1TestApp"});
  }
}

void
Example1TestApp::registerApps()
{
  registerApp(Example1App);
  registerApp(Example1TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
Example1TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  Example1TestApp::registerAll(f, af, s);
}
extern "C" void
Example1TestApp__registerApps()
{
  Example1TestApp::registerApps();
}
