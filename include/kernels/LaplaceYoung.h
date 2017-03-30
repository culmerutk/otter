#ifndef LAPLACEYOUNG_H
#define LAPLACEYOUNG_H

// Including the base Kernel
#include "Kernel.h"

class LaplaceYoung;

template <>
InputParameters validParams<LaplaceYoung>();

class LaplaceYoung : public Kernel
{
public:
  LaplaceYoung(const InputParameters & parameters);
  virtual ~LaplaceYoung();

protected:
  /**
   * Kernels _must_ override computeQpResidual()
   */
  virtual Real computeQpResidual() override;

  /**
   * This is optional (but recommended!)
   */
  virtual Real computeQpJacobian() override;

  /// Will be set from the input file
  Real _kappa;
};

#endif // LAPLACEYOUNG_H
