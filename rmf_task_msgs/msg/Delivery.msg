# task_id is intended to be a pseudo-random string generated
# by the caller which can be used to identify this task as it
# moves between the queues to completion (or failure).
string task_id

rmf_dispenser_msgs/DispenserRequestItem[] items

# robot_type can be used to specify a particular robot fleet
# for this request
string robot_type

string pickup_place_name
string pickup_dispenser
Behavior pickup_behavior

string dropoff_place_name
string dropoff_ingestor
Behavior dropoff_behavior
