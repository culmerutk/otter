#include "LaplaceYoung.h"
#include <cmath>

template <>
InputParameters
validParams<LaplaceYoung>()
{
  // Start with the parameters from our parent
  InputParameters params = validParams<Kernel>();

  // Now add any extra parameters this class needs:

  params.addParam<Real>("kappa", 1.0, "kappa");

  return params;
}

LaplaceYoung::LaplaceYoung(const InputParameters & parameters)
  : Kernel(parameters),

    // Get the parameters from the input file
    _kappa(getParam<Real>("kappa"))
{
}

LaplaceYoung::~LaplaceYoung() {}

Real
LaplaceYoung::computeQpResidual()
{
  return ( _grad_u[_qp] * _grad_test[_i][_qp]) / std::sqrt(1.0 + _grad_u[_qp] * _grad_u[_qp])
    + _u[_qp] * _test[_i][_qp] * _kappa;
}

Real
LaplaceYoung::computeQpJacobian()
{
  // K/mu * grad_phi[j] * grad_phi[i]
  return ( _grad_phi[_j][_qp] * _grad_test[_i][_qp]) / std::sqrt(1.0 + _grad_u[_qp] * _grad_u[_qp])
    + _phi[_j][_qp] * _test[_i][_qp] * _kappa;
}
