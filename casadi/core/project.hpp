/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010-2014 Joel Andersson, Joris Gillis, Moritz Diehl,
 *                            K.U. Leuven. All rights reserved.
 *    Copyright (C) 2011-2014 Greg Horn
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


#ifndef CASADI_PROJECT_HPP
#define CASADI_PROJECT_HPP

#include "mx_node.hpp"
/// \cond INTERNAL

namespace casadi {
  /** \brief Change the sparsity of an expression
      \author Joel Andersson
      \date 2011-2013
  */
  class CASADI_EXPORT Project : public MXNode {
  public:

    /** \brief  Constructor */
    Project(const MX& x, const Sparsity& sp);

    /** \brief  Destructor */
    ~Project() override {}

    /** \brief  Print expression */
    std::string print(const std::vector<std::string>& arg) const override;

    /// Evaluate the function (template)
    template<typename T>
    int eval_gen(const T** arg, T** res, int* iw, T* w, int mem) const;

    /// Evaluate the function numerically
    int eval(const double** arg, double** res, int* iw, double* w, int mem) const override;

    /// Evaluate the function symbolically (SX)
    int eval_sx(const SXElem** arg, SXElem** res, int* iw, SXElem* w, int mem) const override;

    /** \brief  Evaluate symbolically (MX) */
    void eval_mx(const std::vector<MX>& arg, std::vector<MX>& res) const override;

    /** \brief Calculate forward mode directional derivatives */
    void ad_forward(const std::vector<std::vector<MX> >& fseed,
                         std::vector<std::vector<MX> >& fsens) const override;

    /** \brief Calculate reverse mode directional derivatives */
    void ad_reverse(const std::vector<std::vector<MX> >& aseed,
                         std::vector<std::vector<MX> >& asens) const override;

    /** \brief Generate code for the operation */
    void generate(CodeGenerator& g, const std::string& mem,
                  const std::vector<int>& arg, const std::vector<int>& res) const override;

    /** \brief  Propagate sparsity forward */
    int sp_forward(const bvec_t** arg, bvec_t** res, int* iw, bvec_t* w, int mem) const override;

    /** \brief  Propagate sparsity backwards */
    int sp_reverse(bvec_t** arg, bvec_t** res, int* iw, bvec_t* w, int mem) const override;

    /** \brief Get the operation */
    int op() const override { return OP_PROJECT;}

    /** \brief Get required length of w field */
    size_t sz_w() const override { return size1();}
  };

} // namespace casadi

/// \endcond

#endif // CASADI_PROJECT_HPP
