/*
 *  Copyright 2008-2012 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in ctbbliance with the License.
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

#pragma once

#include <thrust/detail/config.h>
#include <thrust/system/cpp/detail/tag.h>
#include <thrust/iterator/detail/any_system_tag.h>
#include <thrust/detail/type_traits.h>

namespace thrust
{
namespace system
{
// put the canonical tag in the same ns as the backend's entry points
namespace tbb
{
namespace detail
{

// tbb inherits cpp's functionality
struct tag : thrust::system::cpp::detail::state<tag> {};

// select_system overloads
__host__ __device__
inline tag select_system(tag, tag)
{
  return tag();
} // end select_system()

// this version catches a user's tag derived from tbb::tag in either slot
template<typename Tag>
__host__ __device__
  typename thrust::detail::enable_if_base_of<tag,Tag,Tag>::type
    select_system(Tag, Tag)
{
  return Tag();
} // end select_system()


// this version catches a user's tag derived from tbb::tag in the first slot
template<typename Tag>
inline __host__ __device__
  typename thrust::detail::enable_if_base_of<tag,Tag,Tag>::type
    select_system(Tag, tag)
{
  return Tag();
} // end select_system()


// this version catches a user's tag derived from tbb::tag in the second slot
template<typename Tag>
inline __host__ __device__
  typename thrust::detail::enable_if_base_of<tag,Tag,tag>::type
    select_system(tag, Tag)
{
  return tag();
} // end select_system()


__host__ __device__
inline tag select_system(tag, thrust::any_system_tag)
{
  return tag();
} // end select_system()

// this version catches a user's tag derived from tbb::tag in the first slot
template<typename Tag>
inline __host__ __device__
  typename thrust::detail::enable_if_base_of<tag,Tag,Tag>::type
    select_system(Tag, thrust::any_system_tag)
{
  return Tag();
} // end select_system()


__host__ __device__
inline tag select_system(thrust::any_system_tag, tag)
{
  return tag();
} // end select_system()

// this version catches a user's tag derived from tbb::tag in the second slot
template<typename Tag>
inline __host__ __device__
  typename thrust::detail::enable_if_base_of<tag,Tag,Tag>::type
    select_system(thrust::any_system_tag, Tag)
{
  return Tag();
} // end select_system()


// this version catches a user's tag derived from tbb::tag in the first slot
template<typename Tag>
inline __host__ __device__
  typename thrust::detail::enable_if_base_of<tag,Tag,Tag>::type
    select_system(Tag, thrust::system::cpp::tag)
{
  return Tag();
} // end select_system()

__host__ __device__
inline tag select_system(tag, thrust::system::cpp::tag)
{
  return tag();
} // end select_system()


// this version catches a user's tag derived from tbb::tag in the second slot
template<typename Tag>
inline __host__ __device__
  typename thrust::detail::enable_if_base_of<tag,Tag,Tag>::type
    select_system(thrust::system::cpp::tag, Tag)
{
  return Tag();
} // end select_system()

__host__ __device__
inline tag select_system(thrust::system::cpp::tag, tag)
{
  return tag();
} // end select_system()


} // end detail

// alias the tag here
using thrust::system::tbb::detail::tag;

} // end tbb
} // end system

// alias tbb's tag at top-level
namespace tbb
{

using thrust::system::tbb::tag;

} // end tbb
} // end thrust

