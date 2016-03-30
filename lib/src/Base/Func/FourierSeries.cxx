//                                               -*- C++ -*-
/**
 *  @brief Fourier series function implementation
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
#include "openturns/FourierSeries.hxx"
#include "openturns/OSS.hxx"
#include "openturns/PersistentObjectFactory.hxx"
#include "openturns/Exception.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(FourierSeries);

static const Factory<FourierSeries> RegisteredFactory;


/* Parameter constructor */
FourierSeries::FourierSeries(const Bool isCosine,
                                             const UnsignedInteger k)
  : UniVariateFunctionImplementation()
  , isCosine_(isCosine)
  , k_(k)
{
  // Nothing to do
}


/* Virtual constructor */
FourierSeries * FourierSeries::clone() const
{
  return new FourierSeries(*this);
}


/* String converter */
String FourierSeries::__repr__() const
{
  return OSS(true) << "class=" << GetClassName()
                   << " isCosine=" << isCosine_
                   << " k=" << k_;
}


String FourierSeries::__str__(const String & offset) const
{
  OSS oss(false);
  oss << offset << "f:X -> " << (k_ > 0 ? "1/sqrt(2) * ": "") << (isCosine_ ? "cos(" : "sin(") << k_ << " * X)";
  return oss;
}


/* FourierSeries are evaluated as functors */
NumericalScalar FourierSeries::operator() (const NumericalScalar x) const
{
  const NumericalScalar coef = k_ > 0 ? 1.0 / sqrt(2.0) : 1.0;
  return coef * (isCosine_ ? cos(k_ * x) : sin(k_ * x));
}

/* FourierSeries gradient */
NumericalScalar FourierSeries::gradient(const NumericalScalar x) const
{
  const NumericalScalar coef = k_ > 0 ? 1.0 / sqrt(2.0) : 1.0;
  return coef * k_ * (isCosine_ ? -sin(k_ * x) : cos(k_ * x));
}

/* FourierSeries hessian */
NumericalScalar FourierSeries::hessian(const NumericalScalar x) const
{
  const NumericalScalar coef = k_ > 0 ? 1.0 / sqrt(2.0) : 1.0;
  return coef * k_ * k_ * (isCosine_ ? -cos(k_ * x) : -sin(k_ * x));
}

/* Method save() stores the object through the StorageManager */
void FourierSeries::save(Advocate & adv) const
{
  PersistentObject::save(adv);
  adv.saveAttribute("isCosine_", isCosine_);
  adv.saveAttribute("k_", k_);
}

/* Method load() reloads the object from the StorageManager */
void FourierSeries::load(Advocate & adv)
{
  PersistentObject::load(adv);
  adv.loadAttribute("isCosine_", isCosine_);
  adv.loadAttribute("k_", k_);
}


END_NAMESPACE_OPENTURNS