/*
* File: lab5_mySolution_Sec3.h
* Description: Declaration of the functions used for a program to simulate the behaviour of particles
*/

#ifndef LAB5_MYSOLUTION_SEC3_H
#define LAB5_MYSOLUTION_SEC3_H

/*
* @brief  fill given array with zeros except index 1, 3 and 5, fill them with ones
*
* @param[in]  particle_arr  given array to store the numbers / particles in
*             size          size of the given array
*             init_pos      given array with initial positions of particles
*             size_init_pos_arr   size of the array with the initial positions of the particles
*             collision_memory    array to memorize where collisions have happend
*/
void setParticleArray(int *particle_arr, const int size, const int *init_pos, const int size_init_pos_arr);

/*
* @brief  display the current state of the particle-array
*
* @param[in]  particle_arr  given array with the particles
*             size          size of the particle-array
*             counter       current time-step
*             collision_index     index of detected collision
*/
void displayParticles(const int *particle_arr, const int size, int timestep_counter, const int collision_index);

/*
* @brief  simulate the movement of the particles
*
* @param[in]  particle_arr  given array with the particles
*             temp_arr      temporary array to store momentary positions of particles
*             size          size of the particle-array
*             ptr_collision_index     pointer to value of index of detected collision
*/
void simulateParticles(int *particle_arr, int *temp_arr, const int size, int *ptr_collision_index);

/*
* @brief  simulate the movement of the particles for a given amount of steps
*
* @param[in]  times         times of steps simulated
*             particle_arr  given array with the particles
*             init_pos      given array with initial positions of particles
*             temp_arr      temporary array to store momentary positions of particles
*             size          size of the particle-array
*             size_init_pos_arr   size of the array with the initial positions of the particles
*/
void simulateRun(int times, int *particle_arr, const int *init_pos, int *temp_arr, const int size, const int size_init_pos_arr);

#endif