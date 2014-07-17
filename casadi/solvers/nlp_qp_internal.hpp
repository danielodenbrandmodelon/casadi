/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef CASADI_NLP_QP_INTERNAL_HPP
#define CASADI_NLP_QP_INTERNAL_HPP

#include "casadi/core/function/qp_solver_internal.hpp"
#include "casadi/core/function/nlp_solver.hpp"

#include <casadi/solvers/casadi_qpsolver_nlp_export.h>

/// \cond INTERNAL
namespace casadi {

  /** \brief Solve QPs using an NLP solver

   @copydoc QpSolver_doc

   \author Joris Gillis
   \date 2011
  */
class CASADI_QPSOLVER_NLP_EXPORT NLPQPInternal : public QpSolverInternal {
public:
  /** \brief  Constructor */
  explicit NLPQPInternal();

  /** \brief  Clone */
  virtual NLPQPInternal* clone() const;

  /** \brief  Create a new QP Solver */
  static QpSolverInternal* creator(const QPStructure& st)
  { return new NLPQPInternal(st);}

  /** \brief  Create a new Solver */
  explicit NLPQPInternal(const std::vector<Sparsity> &st);

  /** \brief  Destructor */
  virtual ~NLPQPInternal();

  /** \brief  Initialize */
  virtual void init();

  virtual void evaluate();

  protected:
    NlpSolver nlpsolver_;

};

} // namespace casadi
/// \endcond
#endif // CASADI_NLP_QP_INTERNAL_HPP
