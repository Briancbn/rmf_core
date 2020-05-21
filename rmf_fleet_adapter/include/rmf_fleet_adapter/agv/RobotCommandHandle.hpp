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

#ifndef RMF_FLEET_ADAPTER__AGV__ROBOTCOMMANDHANDLE_HPP
#define RMF_FLEET_ADAPTER__AGV__ROBOTCOMMANDHANDLE_HPP

#include <rmf_traffic/agv/Planner.hpp>

namespace rmf_fleet_adapter {
namespace agv {

//==============================================================================
/// Implement this class to receive robot commands from RMF
class RobotCommandHandle
{
public:

  /// Have the robot follow a new path. If it was already following a path, then
  /// it should immediately switch over to this one.
  ///
  /// \param[in] waypoints
  ///   The sequence of waypoints to follow. When the robot arrives at a
  ///   waypoint in this sequence, it should wait at that waypoint until the
  ///   clock reaches the time() field of the waypoint. This is important
  ///   because the waypoint timing is used to avoid traffic conflicts with
  ///   other vehicles.
  ///
  /// \param[in] path_finished_callback
  ///   Trigger this callback when the robot is done following the new path.
  virtual void follow_new_path(
      const std::vector<rmf_traffic::agv::Plan::Waypoint>& waypoints,
      std::function<void()> path_finished_callback) = 0;

  /// Have the robot come to an immediate stop.
  virtual void stop() = 0;

  /// Have the robot begin a pre-defined docking procedure. Implement this
  /// function as a no-op if your robots do not perform docking procedures.
  ///
  /// \param[in] dock_name
  ///   The predefined name of the docking procedure to use.
  ///
  /// \param[in] docking_finished_callback
  ///   Trigger this callback when the docking is finished.
  virtual void dock(
      const std::string& dock_name,
      std::function<void()> docking_finished_callback) = 0;

};

} // namespace agv
} // namespace rmf_fleet_adapter

#endif // RMF_FLEET_ADAPTER__AGV__ROBOTCOMMANDHANDLE_HPP
