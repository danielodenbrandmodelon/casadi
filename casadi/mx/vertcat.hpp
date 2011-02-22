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

#ifndef VERTCAT_HPP
#define VERTCAT_HPP

#include "mx_node.hpp"

namespace CasADi{
/** \brief Represents a vertical concatenation of MXes
  \author Joel Andersson 
  \date 2010
*/
class Vertcat : public MXNode{
public:

/** \brief  Constructor */
explicit Vertcat(const std::vector<MX> &comp);

/** \brief  Destructor */
virtual ~Vertcat(){}

/** \brief  Clone function */
virtual Vertcat* clone() const;

/** \brief  Print */
virtual void print(std::ostream &stream, const std::vector<std::string>& args) const;

/** \brief  Evaluate the function and store the result in the node */
virtual void evaluate(const VDptr& input, Dptr& output, const VVDptr& fwdSeed, VDptr& fwdSens, const VDptr& adjSeed, VVDptr& adjSens, int nfwd, int nadj);

protected:

};

} // namespace CasADi

#endif // VERTCAT_HPP
