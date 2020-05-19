/*
 * Copyright (C) 2020 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/

#ifndef RMF_RXCPP__RXJOBS_HPP
#define RMF_RXCPP__RXJOBS_HPP

#include "detail/RxJobsDetail.hpp"
#include <rxcpp/rx.hpp>
#include <memory>

template<typename T, typename Action>
inline auto make_job(const std::shared_ptr<Action>& action)
{
  return detail::make_observable<T>(action);
}

template<typename T, typename Action>
inline auto make_job(const Action& action)
{
  return detail::make_observable<T>(std::make_shared<Action>(action));
}

template<typename Job0, typename... Jobs>
inline auto group_jobs(const Job0& o0, Jobs&&... os)
{
  return o0.merge(rxcpp::serialize_event_loop(), os...);
}

template<typename T, typename ActionsIterable>
inline auto make_group_job(const ActionsIterable& actions)
{
  return detail::make_merged_observable<T>(actions);
}

#endif //RMF_RXCPP__RXJOBS_HPP
