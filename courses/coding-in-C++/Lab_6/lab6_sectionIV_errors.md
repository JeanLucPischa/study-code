### Section IV - Errors:
--- 
###### bugHunt_vehicle.hpp / bugHunt_vehicle.cpp
- MAX_SPEED_KMH not defined
- faulty include: "vehicle.hpp" instead of "bugHunt_vehicle.hpp"

###### bugHunt_assistance_system.hpp / bugHunt_assistance_system.cpp
DistanceSensor:
- measured_distance_m is public instead of private -> unprotected
- operator overloading faulty
- is_exactly_at_warning_distance(): "==" instead of  using epsilon

(LaneKeepingAssist:
- evaluate() needs better documentation)

EmergencyBrakeSystem:
- evaluat() faulty

AdaptiveCruiseCOntrol:
- evaluate() faulty

- accelerate instead of brake