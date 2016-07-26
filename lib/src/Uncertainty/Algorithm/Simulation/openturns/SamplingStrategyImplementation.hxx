//                                               -*- C++ -*-
/**
 *  @brief
 *
 *  Copyright 2005-2016 Airbus-EDF-IMACS-Phimeca
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
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_SAMPLINGSTRATEGYIMPLEMENTATION_HXX
#define OPENTURNS_SAMPLINGSTRATEGYIMPLEMENTATION_HXX

#include "openturns/PersistentObject.hxx"
#include "openturns/NumericalPoint.hxx"
#include "openturns/NumericalSample.hxx"
#include "openturns/PersistentObject.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class SamplingStrategyImplementation
 */

class OT_API SamplingStrategyImplementation
  : public PersistentObject
{

  CLASSNAME;

public:

  /** Constructor with parameters */
  explicit SamplingStrategyImplementation(const UnsignedInteger dimension = 0);

  /** Virtual constructor */
  virtual SamplingStrategyImplementation * clone() const;

  /** Generate a set of directions */
  virtual NumericalSample generate() const;

  /** Generate a uniform random unit vector */
  NumericalPoint getUniformUnitVectorRealization(const UnsignedInteger dimension) const;

  /** Generate a uniform random unit vector */
  NumericalPoint getUniformUnitVectorRealization() const;

  /** Dimension accessor */
  void setDimension(const UnsignedInteger dimension);
  UnsignedInteger getDimension() const;

  /** String converter */
  virtual String __repr__() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);

protected:

  UnsignedInteger dimension_;

} ; /* class SamplingStrategyImplementation */

END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_SAMPLINGSTRATEGYIMPLEMENTATION_HXX */