//                                               -*- C++ -*-
/**
 *  @brief PostAnalyticalImportanceSampling is an implementation of the importance sampling Montex Carlo simulation method
 *
 *  Copyright 2005-2019 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_POSTANALYTICALIMPORTANCESAMPLING_HXX
#define OPENTURNS_POSTANALYTICALIMPORTANCESAMPLING_HXX

#include "openturns/PostAnalyticalSimulation.hxx"

BEGIN_NAMESPACE_OPENTURNS



/**
 * @class PostAnalyticalImportanceSampling
 */

class OT_API PostAnalyticalImportanceSampling :
  public PostAnalyticalSimulation
{

  CLASSNAME
public:
  /** for save/load mecanism */
  PostAnalyticalImportanceSampling();

  /** Constructor with parameters */
  explicit PostAnalyticalImportanceSampling(const AnalyticalResult & AnalyticalResult);

  /** Virtual constructor */
  virtual PostAnalyticalImportanceSampling * clone() const;

  /** String converter */
  String __repr__() const;

private:

  /** Compute the block sample */
  Sample computeBlockSample();

} ; /* class PostAnalyticalImportanceSampling */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_POSTANALYTICALIMPORTANCESAMPLING_HXX */
