[Mesh]
  type = GeneratedMesh
  dim = 2
  nx = 100
  ny = 100
  xmin = 0.0
  xmax = 1.0
  ymin = 0.0
  ymax = 1.0
[]
[Variables]
  [./otterwatts]
  [../]
[]
[Kernels]
  [./laplace_young]
    type = LaplaceYoung
    variable = otterwatts
    kappa = 1.0
  [../]
[]
[BCs]
  [./edge]
    type = NeumannBC
    variable = otterwatts
    boundary = '0 1 2 3'
    value = 0.2
  [../]
[]
[Problem]
  type = FEProblem
[]
[Executioner]
  type = Steady
  solve_type = PJFNK
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]
[Outputs]
  exodus = true
[]
