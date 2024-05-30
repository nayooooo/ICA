#ifndef __FC_INPUT_H__
#define __FC_INPUT_H__

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

#include "fc_obj.h"

#include "./../exter/fuzzy_opera.h"
#include "./../exter/list.h"

/*==================================================================================
    structure
==================================================================================*/

/**
 * @brief Membership function
 * 
 * @param value Accurate number
 * @return fuzzy_number Membership degree
 */
typedef fuzzy_number (*fc_membership_fn)(accurate_number value);

/**
 * @brief Fuzzy controller input components
 * 
 * @memberof Obj object
 * @memberof data fuzzy Data
 * @memberof membership_fns Membership function linked list
 */
struct fc_input
{
    struct fc_obj obj;

    struct fuzzy_matrix data;
    list_head membership_fns;
};

/*==================================================================================
    API
==================================================================================*/

/**
 * @brief Register as input object for fuzzy controller
 * @note Never execute this function on input devices of fuzzy controllers
 *       that have already been registered. If you need to execute this
 *       function, please unregister it first
 * 
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_register(struct fc_input* in);

/**
 * @brief Unregister the input device of the fuzzy controller
 * 
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_unregister(struct fc_input* in);

/**
 * @brief Add a membership function to the end
 * 
 * @param in object
 * @param fn membership function
 * @return true success
 * @return false failed
 */
bool fc_input_add_membership_fn(struct fc_input* in, fc_membership_fn fn);

/**
 * @brief Clear membership function
 * 
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_clear_membership_fn(struct fc_input* in);

/**
 * @brief Fuzzy the input data and store the obtained membership vector in member data
 * @note The previously generated membership vectors will be destroyed
 * 
 * @param in object
 * @param value Data that will be blurred
 * @return true success
 * @return false failed
 */
bool fc_input_fuzzing(struct fc_input* in, accurate_number value);

/**
 * @brief Print out the membership vector
 * 
 * @param in object
 * @return true success
 * @return false failed
 */
bool fc_input_print_membership_vector(struct fc_input* in);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif  // !__FC_INPUT_H__