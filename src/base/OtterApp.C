#include "OtterApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"
#include "LaplaceYoung.h"

template<>
InputParameters validParams<OtterApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

OtterApp::OtterApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  OtterApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  OtterApp::associateSyntax(_syntax, _action_factory);
}

OtterApp::~OtterApp()
{
}

// External entry point for dynamic application loading
extern "C" void OtterApp__registerApps() { OtterApp::registerApps(); }
void
OtterApp::registerApps()
{
  registerApp(OtterApp);
}

// External entry point for dynamic object registration
extern "C" void OtterApp__registerObjects(Factory & factory) { OtterApp::registerObjects(factory); }
void
OtterApp::registerObjects(Factory & factory)
{
  registerKernel(LaplaceYoung);
}

// External entry point for dynamic syntax association
extern "C" void OtterApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { OtterApp::associateSyntax(syntax, action_factory); }
void
OtterApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
