/*
 *  Copyright 2008-2012 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

/*! \file for_each.h
 *  \brief Generic implementation of for_each & for_each_n.
 *         It is an error to call these functions; they have no implementation.
 */

#pragma once

#include <thrust/detail/config.h>
#include <thrust/system/detail/state.h>
#include <thrust/system/detail/generic/tag.h>
#include <thrust/detail/static_assert.h>

namespace thrust
{
namespace system
{
namespace detail
{
namespace generic
{


template<typename System,
         typename InputIterator,
         typename UnaryFunction>
InputIterator for_each(thrust::system::detail::state<System> &s,
                       InputIterator first,
                       InputIterator last,
                       UnaryFunction f)
{
  // unimplemented
  THRUST_STATIC_ASSERT( (thrust::detail::depend_on_instantiation<InputIterator, false>::value) );
  return last;
} // end for_each()


template<typename InputIterator,
         typename Size,
         typename UnaryFunction>
InputIterator for_each_n(tag,
                         InputIterator first,
                         Size n,
                         UnaryFunction f)
{
  // unimplemented
  THRUST_STATIC_ASSERT( (thrust::detail::depend_on_instantiation<InputIterator, false>::value) );
} // end for_each_n()


} // end namespace generic
} // end namespace detail
} // end namespace system
} // end namespace thrust

